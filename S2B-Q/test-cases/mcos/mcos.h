#ifndef MCOS_H
#define MCOS_H

/*
 * $(CC) -DUSE_PTHREAD ... -lpthread
 *
 * -DMAIN_WAIT_TIME=N (default 1H)
 *     main()を終了するまでの時間
 *     単位は秒で、デフォルトは3600秒(1時間)
 *
 * -DCHECK_USER_CYCLE
 *     カウンタ mcos__cycle_step が MCOS_THREAD_MAX_CYCLE を越えるまで
 *     実行を続ける。なお、1秒間隔のポーリングで判定するため、必ずしも
 *     MCOS_THREAD_MAX_CYCLEでは終わらない。
 *     mcos__cycle_stepは、利用者が適当な箇所でカウントアップする必要が
 *     ある。
 *
 * -DMCOS_THREAD_MAX_CYCLE=N
 *     CHECK_USE_CYCLEを有効にした際に使用される。デフォルトは10000
 */

#ifdef USE_PTHREAD
#include <pthread.h>
#if defined(__MINGW32__) || defined(__MINGW64__)
#define __struct_timespec_defined	1	/* conflict <time.h> ... */
#endif
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 199901L
#if defined(__MINGW32__) || defined(__MINGW64__)
#define alloca	__builtin_alloca
#else
#include <alloca.h>
#endif /* __STDC_VERSION__ */
#endif
#endif

#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef __GNUC__
#ifndef __attribute__
#define __attribute__ (X)
#endif
#endif

#define MC_EOK		0
#define MC_EPAR		(-1)
#define MC_ENOMEM	(-2)

#define LCID_SELF	(0)
#define LCID_ANY	(-1)

#define TPRI_INHERIT	(0)

typedef int16_t mcos_erid_t;
typedef int16_t mcos_id_t;
typedef int16_t mcos_er_t;

typedef struct { uint32_t attrs[2]; } mcos_threadattr_t;

static mcos_er_t
__attribute__ ((unused))
mcos_threadattr_init(mcos_threadattr_t *attr)
{
  (void)attr;
  return MC_EOK;
}

static mcos_er_t
__attribute__ ((unused))
mcos_threadattr_setlcid(mcos_threadattr_t *attr, mcos_id_t lcid)
{
  (void)attr;
  (void)lcid;
  return MC_EOK;
}

static mcos_er_t
__attribute__ ((unused))
mcos_threadattr_setpriority(mcos_threadattr_t *attr, uint8_t pri)
{
  (void)attr;
  (void)pri;
  return MC_EOK;
}

static mcos_er_t
__attribute__ ((unused))
mcos_threadattr_setstacksize(mcos_threadattr_t *attr, uint32_t stacksize)
{
  (void)attr;
  (void)stacksize;
  return MC_EOK;
}

#ifdef USE_PTHREAD

#define CH___STR(X)	#X

#ifndef MCOS_THREAD_MAX_CYCLE
#define MCOS_THREAD_MAX_CYCLE	10000
#endif

static mcos_er_t
__attribute__ ((unused))
mcos__thread_create (void *(*func) (void *), void *arg,
		     int line, const char *name)
{
  pthread_t pth;
  pthread_attr_t attr;
  int r;

  pthread_attr_init (&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  r = pthread_create (&pth, NULL, func, arg);
  if (r != 0)
    {
      fprintf (stderr, "%d: %s: pthread_create r=%d: %s\n",
	       line, name, r, strerror (errno));
      exit (1);
    }
  return MC_EOK;
}


#define mcos_thread_create(A,E,I)				\
  mcos__thread_create (CH__VEC_CONCAT(f__,E), (void *)I,	\
		       __LINE__, CH___STR(E))
#else  /* !USE_PTHREAD */
static mcos_erid_t
__attribute__ ((unused))
mcos_thread_create(const mcos_threadattr_t *attr,
		   void (*entry)(uint32_t, uintptr_t), uintptr_t exinf)
{
  (void)attr;
  (void)entry;
  return MC_EOK;
}
#endif	/* !USE_PTHREAD */

static mcos_erid_t
__attribute__ ((unused))
mcos_thread_delay(uint32_t m)
{
  (void)m;
#ifdef USE_PTHREAD
  sched_yield ();
#endif	/* USE_PTHREAD */
  return MC_EOK;
}

static mcos_er_t
__attribute__ ((unused))
mcos_thread_start(mcos_id_t tid, uint32_t param)
{
  (void)tid;
  (void)param;
  return MC_EOK;
}

#define CH__SYNCM()	__asm__ __volatile__ ("mfence" ::: "memory")

#if defined(USE_PTHREAD)

#ifndef PTHREAD_DEBUG
#define PTHREAD_DEBUG	0
#endif

static int ch__bitcheck (unsigned long *v, size_t b);
void create_init_threads (void);

static void
ch___event(pthread_mutex_t *mutex, pthread_cond_t *cond, int* flag,
	   int line, const char *ch_name, const char* task_name)
{
  (void)pthread_mutex_lock(mutex);
  (*flag)++;
  (void)pthread_cond_signal(cond);
  (void)pthread_mutex_unlock(mutex);
  if (PTHREAD_DEBUG) {
    printf("%d: %s: send event from %s\n", line, ch_name, task_name);
    fflush (stdout);
  }
}

#define CH__EVENT(T,X)				\
  ch___event(&CH__VEC_CONCAT(mutex__,X),	\
	     &CH__VEC_CONCAT(cond__,X),		\
	     &CH__VEC_CONCAT(flag__,X),		\
	     __LINE__, CH___STR(X), CH___STR(T))

static void
ch___task_sched(pthread_mutex_t *mutex, pthread_cond_t *cond, int* flag,
		unsigned long* v, size_t size,
		int line, const char* ch_name)
{
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
  char bitbuf[(size + 1 + 15) / 16];
#else
  char *bitbuf = alloca ((size + 1 + 15) / 16);
#endif
  char *s;
  size_t i;
  s = bitbuf + size;
  *s-- = 0;
  if (v == NULL)
    *s-- = '0';
  else
    {
      for (i = 0; i < size; i++)
	*s-- = ch__bitcheck(v, i) ? '1' : '0';
    }
  if (PTHREAD_DEBUG) {
    printf("%d: %s: wait event(%s)\n", line, ch_name, bitbuf);
    fflush(stdout);
  }
  (void)pthread_mutex_lock(mutex);
  while (*flag == 0) {
    struct timespec val;
    int er;
    val.tv_sec = time(NULL) + 6000;
    val.tv_nsec = 0;
    er = pthread_cond_timedwait(cond, mutex, &val);
    if (er)
      {
	if (errno == ETIMEDOUT)
	  {
	    fprintf(stderr, "%d: %s: TIMEDOUT\n", line, ch_name);
	    fflush (stderr);
	    break;
	  }
      }
    else
      {
	if (PTHREAD_DEBUG) {
	  printf("%d: %s: get event\n",line, ch_name);
	  fflush(stdout);
	}
	break;
      }
  }
  *flag = 0;
  pthread_mutex_unlock (mutex);
}

#define CH__TASK_SCHED(C,V,S)				\
  ch___task_sched(&CH__VEC_CONCAT(mutex__,C),		\
		  &CH__VEC_CONCAT(cond__,C),		\
		  &CH__VEC_CONCAT(flag__,C),		\
		  (V), (S), __LINE__, CH___STR(C))

#define CH__CORE_THREAD_SCHED(C,V,S)	CH__TASK_SCHED(C,V,S)

#define CH__END_LOG(C)					\
  do {							\
    if (PTHREAD_DEBUG) {				\
      printf ("%d: %s: end\n", __LINE__, CH___STR(C));	\
      fflush (stdout);					\
    }							\
  } while (0)

#endif	/* USE_PTHREAD */

#ifndef MAIN_WAIT_TIME
#define MAIN_WAIT_TIME	3600	/* 1h */
#endif

#ifdef CHECK_USER_CYCLE
unsigned int mcos__cycle_step = 0;

int main (void)
{
  unsigned int laps = 0;
  unsigned int last;

  create_init_threads ();

  last = mcos__cycle_step;
  while (mcos__cycle_step < MCOS_THREAD_MAX_CYCLE) {
    if (laps++ >= 600) {
      printf ("not change 10min, mcos__cycle_step=%u\n", mcos__cycle_step);
      break;
    }
    if (last != mcos__cycle_step) {
      last = mcos__cycle_step;
      laps = 0;
    }
    sleep (1);
    laps++;
    __asm__ __volatile__ ("":::"memory");
  }
  return 0;
}
#else  /* !CHECK_USER_CYCLE */
int main (void)
{
  create_init_threads ();
  sleep (MAIN_WAIT_TIME);
  return 0;
}
#endif	/* !CHECK_USER_CYCLE */

#endif	/* MCOS_H */
