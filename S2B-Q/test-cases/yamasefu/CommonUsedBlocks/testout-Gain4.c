#include <mcos/mcos.h>
#include <mcos/mcos_ds.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "Gain4_types.h"
#include "Gain4_private.h"

#include "testout-Gain4_res.c"
#include "testout-Gain4.h"


/*
 * Resource by Core
 */

/* Logical Core task */
#ifndef LCORE_STACK_SIZE
#define LCORE_STACK_SIZE	0 /* default */
#endif /* LCORE_STACK_SIZE */

#ifndef LCORE_PRIORITY
#define LCORE_PRIORITY	128
#endif /* LCORE_PRIVATE */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif


/* Real-time Model Data Structure */
struct tag_RTM_Gain4_T {
  const char_T * volatile errorStatus;
};

#ifndef __GNUC__
#define __inline__
#endif /* __GNUC__ */

#ifndef CORE_TASK_DATA_PREPARE
#define CORE_TASK_DATA_PREPARE(N)	/* none */
#endif /* CORE_TASK_DATA_PREPARE */

#ifndef CORE_TASK_DATA_ATTRIBUTE
#define CORE_TASK_DATA_ATTRIBUTE(N)	/* none */
#endif /* CORE_TASK_DATA_ATTRIBUTE */

#ifndef CORE_TASK_CODE_PREPARE
#define CORE_TASK_CODE_PREPARE(N)	/* none */
#endif /* CORE_TASK_CODE_PREPARE */

#ifndef CORE_TASK_CODE_ATTRIBUTE
#define CORE_TASK_CODE_ATTRIBUTE(N)	/* none */
#endif /* CORE_TASK_CODE_ATTRIBUTE */

#ifndef TASK_DATA_PREPARE
#define TASK_DATA_PREPARE(N)	/* none */
#endif /* TASK_DATA_PREPARE */

#ifndef TASK_DATA_ATTRIBUTE
#define TASK_DATA_ATTRIBUTE(N)	/* none */
#endif /* TASK_DATA_ATTRIBUTE */

#ifndef TASK_CODE_PREPARE
#define TASK_CODE_PREPARE(N)	/* none */
#endif /* TASK_CODE_PREPARE */

#ifndef TASK_CODE_ATTRIBUTE
#define TASK_CODE_ATTRIBUTE(N)	/* none */
#endif /* TASK_CODE_ATTRIBUTE */

/*
 * Channel Macros
 */
#define CH__VEC__CONCAT(A,B)	A##B
#define CH__VEC_CONCAT(A,B)	CH__VEC__CONCAT(A,B)
#define CH__VEC_NAME(N)	CH__VEC_CONCAT(ch__vec_,N)
#define CH__VEC_ELEMENT_TYPE	unsigned long
#define CH__VEC_ELEMENT_BITS	(sizeof (CH__VEC_ELEMENT_TYPE) * 8)
#define CH__VEC_ELEMENT_SIZE(S)	\
  (((S)+CH__VEC_ELEMENT_BITS-1)/CH__VEC_ELEMENT_BITS)
#define CH__VEC_ELEMENT_0	((CH__VEC_ELEMENT_TYPE)0)
#define CH__VEC_ELEMENT_1	((CH__VEC_ELEMENT_TYPE)1)
#define CH__VEC(N,S)	\
  CH__VEC_ELEMENT_TYPE CH__VEC_NAME(N)[CH__VEC_ELEMENT_SIZE(S)] = {0,}
#define CH__VEC_INIT(N) memset(CH__VEC_NAME(N), 0, sizeof CH__VEC_NAME(N))
#define CH__BITCHECK(N,B)	ch__bitcheck(CH__VEC_NAME(N),B)
#define CH__BITSET(N,B)	ch__bitset(CH__VEC_NAME(N),B)
#define CH__COMPLETED(N,S)	ch__completed(CH__VEC_NAME(N),S)

#ifndef CH__SYNCM
#if defined(__v850__) && defined(__GNUC__)
#define CH__SYNCM()	__asm__ __volatile__ ("syncm" ::: "memory")
#else /* !__v850__ || !__GNUC__ */
#define CH__SYNCM()	do { ; } while (0)
#endif /* !__v850__ || __GNUC__ */
#endif /* !CH__SYNCM */

#ifndef CH__MEM_BARRIER
#ifdef __GNUC__
#define CH__MEM_BARRIER()	__asm__ __volatile__ ("" ::: "memory")
#else /* !__GNUC__ */
#define CH__MEM_BARRIER()	do { ; } while (0)
#endif /* !__GNUC__ */
#endif /* !CH__MEM_BARRIER */

#ifndef CH__TASK_SCHED
#ifdef MCOS_H
#define CH__TASK_SCHED(C,V,S)	mcos_thread_delay(0)
#else /* !MCOS_H */
#define CH__TASK_SCHED(C,V,S)	do { ; } while (0)
#endif /* !MCOS_H */
#endif /* !CH__TASK_SCHED */

#ifndef CH__EVENT
#define CH__EVENT(T,C)	CH__MEM_BARRIER()
#endif /* CH__EVENT */

#ifndef CH__END_LOG
#define CH__END_LOG(C)	do { ; } while (0)
#endif /* CH__END_LOG */

#ifndef CH__CORE_THREAD_SCHED
#define CH__CORE_THREAD_SCHED(C,V,S)	do { ; } while (0)
#endif /* CH__CORE_THREAD_SCHED */

/* check channle bitvec */
static __inline__ int
ch__bitcheck (CH__VEC_ELEMENT_TYPE *v, size_t b)
{
  return (v[b/CH__VEC_ELEMENT_BITS]
          & (CH__VEC_ELEMENT_1 << (b % CH__VEC_ELEMENT_BITS)));
}

/* set channle bitvec */
static __inline__ void
ch__bitset (CH__VEC_ELEMENT_TYPE *v, size_t b)
{
  v[b/CH__VEC_ELEMENT_BITS]
    |= (CH__VEC_ELEMENT_1 << (b % CH__VEC_ELEMENT_BITS));
}

/* completed channel wait */
static __inline__ int
ch__completed (CH__VEC_ELEMENT_TYPE *v, size_t n)
{
  const size_t restbits = n % CH__VEC_ELEMENT_BITS;
  size_t i;
  size_t e = (n - 1) / CH__VEC_ELEMENT_BITS;
  CH__VEC_ELEMENT_TYPE const
    restmask =  ((restbits == 0)
		 ? (~CH__VEC_ELEMENT_0)
		 : ((CH__VEC_ELEMENT_1 << restbits) - 1));
  for (i = 0; i < e; i++, v++)
    {
      if (*v != ~(CH__VEC_ELEMENT_0))
	return 0;
    }
  if (*v != restmask)
    return 0;
  return 1;
}

/*
 * Channels
 */

/* From: t0
   To: Gain4_VectorConcatenate */
typedef struct {
  int flag__0000_0003;
  real_T Gain4_In1_1;
} TYPE_0000_0003;
TYPE_0000_0003 CH_0000_0003;

/* From: Gain4_In1
   To: t0 */
typedef struct {
  int flag__IO0001_0000;
  real_T Gain4_In1_1;
} TYPE_IO0001_0000;
TYPE_IO0001_0000 CH_IO0001_0000;

/* From: Gain4_Gain
   To: extout */
typedef struct {
  int flag__0002_0100;
  real_T Gain4_Gain_1;
} TYPE_0002_0100;
TYPE_0002_0100 CH_0002_0100;

/* From: Gain4_VectorConcatenate
   To: Gain4_Gain */
typedef struct {
  int flag__0003_0002;
  real_T Gain4_VectorConcatenate_1[2];
} TYPE_0003_0002;
TYPE_0003_0002 CH_0003_0002;

/*
 * Tasks
 */

TASK_CODE_PREPARE(0000)

/* Block: t0 */
void mcos_lcore_task_0000(uint32_t stacd, uintptr_t extinfo)
{
  /* definitions of step function */
  real_T tmp;

  /* end of definitions */
  /* omit input channel bit vector */
  /* CH__VEC(IN_0000,1); */

  /* omit output channel bit vector */
  /* CH__VEC(OUT_0000,1); */
  real_T Gain4_In1_1;

  /* initialize task context */
{
  Gain4_In1_1 = 0.0;
}

#ifdef TASK_INITIALIZE_0000_COMPLETED
  TASK_INITIALIZE_0000_COMPLETED();
#endif

  /* task loop */
  while (1) {

    /* wait input channel */
    while (1) {
      /* input: Gain4_In1 */
      if (CH_IO0001_0000.flag__IO0001_0000 == 1) {
	Gain4_In1_1 = CH_IO0001_0000.Gain4_In1_1;
	CH__SYNCM();
	CH_IO0001_0000.flag__IO0001_0000 = 0;
	CH__EVENT(TASK_0000, OUT_IO0001);
	CH__END_LOG(IN_0000);
	break;
      }

      CH__TASK_SCHED(IN_0000,NULL,1);

      CH__MEM_BARRIER();
    }

#ifdef TASK_IN_0000_COMPLETED
    TASK_IN_0000_COMPLETED();
#endif

#ifdef TASK_EXECUTE_0000_COMPLETED
    TASK_EXECUTE_0000_COMPLETED();
#endif

    /* wait output channel */
    while (1) {
      /* output: Gain4_VectorConcatenate */
      if (CH_0000_0003.flag__0000_0003 == 0) {
	CH_0000_0003.Gain4_In1_1 = Gain4_In1_1;
	CH__SYNCM();
	CH_0000_0003.flag__0000_0003 = 1;
	CH__EVENT(TASK_0000,IN_0003);
	CH__END_LOG(OUT_0000);
	break;
      }

      CH__TASK_SCHED(OUT_0000,NULL,1);

      CH__MEM_BARRIER();
    }

#ifdef TASK_OUT_0000_COMPLETED
    TASK_OUT_0000_COMPLETED();
#endif
  }
}

TASK_CODE_PREPARE(0100)

/* Block: extout */
void mcos_lcore_task_0100(uint32_t stacd, uintptr_t extinfo)
{
  /* definitions of step function */
  real_T tmp;

  /* end of definitions */
  /* omit input channel bit vector */
  /* CH__VEC(IN_0100,1); */
  real_T Gain4_Gain_1;

#ifdef TASK_INITIALIZE_0100_COMPLETED
  TASK_INITIALIZE_0100_COMPLETED();
#endif

  /* task loop */
  while (1) {

    /* wait input channel */
    while (1) {
      /* input: Gain4_Gain */
      if (CH_0002_0100.flag__0002_0100 == 1) {
	Gain4_Gain_1 = CH_0002_0100.Gain4_Gain_1;
	CH__SYNCM();
	CH_0002_0100.flag__0002_0100 = 0;
	CH__EVENT(TASK_0100, OUT_0002);
	CH__END_LOG(IN_0100);
	break;
      }

      CH__TASK_SCHED(IN_0100,NULL,1);

      CH__MEM_BARRIER();
    }

#ifdef TASK_IN_0100_COMPLETED
    TASK_IN_0100_COMPLETED();
#endif

#ifdef TASK_EXECUTE_0100_COMPLETED
    TASK_EXECUTE_0100_COMPLETED();
#endif

    /****************************************************
     *
     * You may insert some codes here for external output.
     *
     ****************************************************/
  }
}

TASK_CODE_PREPARE(IO0001)

/* Block: Gain4_In1 */
void mcos_lcore_task_IO0001(uint32_t stacd, uintptr_t extinfo)
{
  /* definitions of step function */
  real_T tmp;

  /* end of definitions */
  /* omit output channel bit vector */
  /* CH__VEC(OUT_IO0001,1); */
  real_T Gain4_In1_1;

#ifdef TASK_INITIALIZE_IO0001_COMPLETED
  TASK_INITIALIZE_IO0001_COMPLETED();
#endif

  /* task loop */
  while (1) {

    /****************************************************
     *
     * You should insert some codes here for external input.
     *
     ****************************************************/

#ifdef TASK_EXECUTE_IO0001_COMPLETED
    TASK_EXECUTE_IO0001_COMPLETED();
#endif

    /* wait output channel */
    while (1) {
      /* output: t0 */
      if (CH_IO0001_0000.flag__IO0001_0000 == 0) {
	CH_IO0001_0000.Gain4_In1_1 = Gain4_In1_1;
	CH__SYNCM();
	CH_IO0001_0000.flag__IO0001_0000 = 1;
	CH__EVENT(TASK_IO0001,IN_0000);
	CH__END_LOG(OUT_IO0001);
	break;
      }

      CH__TASK_SCHED(OUT_IO0001,NULL,1);

      CH__MEM_BARRIER();
    }

#ifdef TASK_OUT_IO0001_COMPLETED
    TASK_OUT_IO0001_COMPLETED();
#endif
  }
}

TASK_CODE_PREPARE(0002)

/* Block: Gain4_Gain */
void mcos_lcore_task_0002(uint32_t stacd, uintptr_t extinfo)
{
  /* definitions of step function */
  real_T tmp;

  /* end of definitions */
  /* omit input channel bit vector */
  /* CH__VEC(IN_0002,1); */

  /* omit output channel bit vector */
  /* CH__VEC(OUT_0002,1); */

  /* params */
  struct {
    real_T Gain_Gain[2];
  } Gain4_P = {
  };
  real_T Gain4_VectorConcatenate_1[2];
  real_T Gain4_Gain_1;

  /* initialize task context */
{
  Gain4_Gain_1 = 0.0;

}

#ifdef TASK_INITIALIZE_0002_COMPLETED
  TASK_INITIALIZE_0002_COMPLETED();
#endif

  /* task loop */
  while (1) {

    /* wait input channel */
    while (1) {
      /* input: Gain4_VectorConcatenate */
      if (CH_0003_0002.flag__0003_0002 == 1) {
	memcpy(Gain4_VectorConcatenate_1,
	  CH_0003_0002.Gain4_VectorConcatenate_1,
	  sizeof Gain4_VectorConcatenate_1);
	CH__SYNCM();
	CH_0003_0002.flag__0003_0002 = 0;
	CH__EVENT(TASK_0002, OUT_0003);
	CH__END_LOG(IN_0002);
	break;
      }

      CH__TASK_SCHED(IN_0002,NULL,1);

      CH__MEM_BARRIER();
    }

#ifdef TASK_IN_0002_COMPLETED
    TASK_IN_0002_COMPLETED();
#endif

    /* C code */
        {
{

  /* Gain: '<Root>/Gain' */
  tmp = Gain4_P.Gain_Gain[0] * Gain4_VectorConcatenate_1[0];
  tmp += Gain4_P.Gain_Gain[1] * Gain4_VectorConcatenate_1[1];
  Gain4_Gain_1 = tmp;

}

    }

#ifdef TASK_EXECUTE_0002_COMPLETED
    TASK_EXECUTE_0002_COMPLETED();
#endif

    /* wait output channel */
    while (1) {
      /* output: extout */
      if (CH_0002_0100.flag__0002_0100 == 0) {
	CH_0002_0100.Gain4_Gain_1 = Gain4_Gain_1;
	CH__SYNCM();
	CH_0002_0100.flag__0002_0100 = 1;
	CH__EVENT(TASK_0002,IN_0100);
	CH__END_LOG(OUT_0002);
	break;
      }

      CH__TASK_SCHED(OUT_0002,NULL,1);

      CH__MEM_BARRIER();
    }

#ifdef TASK_OUT_0002_COMPLETED
    TASK_OUT_0002_COMPLETED();
#endif
  }
}

TASK_CODE_PREPARE(0003)

/* Block: Gain4_VectorConcatenate */
void mcos_lcore_task_0003(uint32_t stacd, uintptr_t extinfo)
{
  /* definitions of step function */
  real_T tmp;

  /* end of definitions */
  /* omit input channel bit vector */
  /* CH__VEC(IN_0003,1); */

  /* omit output channel bit vector */
  /* CH__VEC(OUT_0003,1); */
  real_T Gain4_In1_1;
  real_T Gain4_VectorConcatenate_1[2];

  /* initialize task context */
{
  Gain4_VectorConcatenate_1[0] = 0.0;
  Gain4_VectorConcatenate_1[1] = 0.0;
}

#ifdef TASK_INITIALIZE_0003_COMPLETED
  TASK_INITIALIZE_0003_COMPLETED();
#endif

  /* task loop */
  while (1) {

    /* wait input channel */
    while (1) {
      /* input: t0 */
      if (CH_0000_0003.flag__0000_0003 == 1) {
	Gain4_In1_1 = CH_0000_0003.Gain4_In1_1;
	CH__SYNCM();
	CH_0000_0003.flag__0000_0003 = 0;
	CH__EVENT(TASK_0003, OUT_0000);
	CH__END_LOG(IN_0003);
	break;
      }

      CH__TASK_SCHED(IN_0003,NULL,1);

      CH__MEM_BARRIER();
    }

#ifdef TASK_IN_0003_COMPLETED
    TASK_IN_0003_COMPLETED();
#endif

    /* C code */
        {
{

  /* SignalConversion: '<Root>/ConcatBufferAtVectorConcatenateIn1' incorporates:
   *  Inport: '<Root>/In1'
   */
  Gain4_VectorConcatenate_1[0] = Gain4_In1_1;


}

{

  /* SignalConversion: '<Root>/ConcatBufferAtVectorConcatenateIn2' incorporates:
   *  Inport: '<Root>/In1'
   */
  Gain4_VectorConcatenate_1[1] = Gain4_In1_1;


}

    }

#ifdef TASK_EXECUTE_0003_COMPLETED
    TASK_EXECUTE_0003_COMPLETED();
#endif

    /* wait output channel */
    while (1) {
      /* output: Gain4_Gain */
      if (CH_0003_0002.flag__0003_0002 == 0) {
	memcpy(CH_0003_0002.Gain4_VectorConcatenate_1,
	  Gain4_VectorConcatenate_1,
	  sizeof Gain4_VectorConcatenate_1);
	CH__SYNCM();
	CH_0003_0002.flag__0003_0002 = 1;
	CH__EVENT(TASK_0003,IN_0002);
	CH__END_LOG(OUT_0003);
	break;
      }

      CH__TASK_SCHED(OUT_0003,NULL,1);

      CH__MEM_BARRIER();
    }

#ifdef TASK_OUT_0003_COMPLETED
    TASK_OUT_0003_COMPLETED();
#endif
  }
}

/*
 * MCOS thread creation
 *
 *   create_init_threads
 */
void
create_init_threads (void)
{
  mcos_erid_t tid;
  mcos_id_t lcid;
  mcos_threadattr_t attr;
  static mcos_id_t tids[5];
  size_t num = 0;
  size_t i;

  mcos_threadattr_init (&attr);

  mcos_threadattr_setlcid (&attr, LCID_ANY);
  mcos_threadattr_setpriority (&attr, LCORE_PRIORITY);

#ifdef MCOS_LCORE_TASK_0000_STATCK_SIZE
  mcos_threadattr_setstacksize (&attr, MCOS_LCORE_TASK_0000_STATCK_SIZE);
#else
  mcos_threadattr_setstacksize (&attr, LCORE_STACK_SIZE);
#endif
  tid = mcos_thread_create (&attr, mcos_lcore_task_0000, 0);
  if (tid == MC_EPAR || tid == MC_ENOMEM)
    return;
  tids[num++] = tid;

#ifdef MCOS_LCORE_TASK_0100_STATCK_SIZE
  mcos_threadattr_setstacksize (&attr, MCOS_LCORE_TASK_0100_STATCK_SIZE);
#else
  mcos_threadattr_setstacksize (&attr, LCORE_STACK_SIZE);
#endif
  tid = mcos_thread_create (&attr, mcos_lcore_task_0100, 0);
  if (tid == MC_EPAR || tid == MC_ENOMEM)
    return;
  tids[num++] = tid;

#ifdef MCOS_LCORE_TASK_IO0001_STATCK_SIZE
  mcos_threadattr_setstacksize (&attr, MCOS_LCORE_TASK_IO0001_STATCK_SIZE);
#else
  mcos_threadattr_setstacksize (&attr, LCORE_STACK_SIZE);
#endif
  tid = mcos_thread_create (&attr, mcos_lcore_task_IO0001, 0);
  if (tid == MC_EPAR || tid == MC_ENOMEM)
    return;
  tids[num++] = tid;

#ifdef MCOS_LCORE_TASK_0002_STATCK_SIZE
  mcos_threadattr_setstacksize (&attr, MCOS_LCORE_TASK_0002_STATCK_SIZE);
#else
  mcos_threadattr_setstacksize (&attr, LCORE_STACK_SIZE);
#endif
  tid = mcos_thread_create (&attr, mcos_lcore_task_0002, 0);
  if (tid == MC_EPAR || tid == MC_ENOMEM)
    return;
  tids[num++] = tid;

#ifdef MCOS_LCORE_TASK_0003_STATCK_SIZE
  mcos_threadattr_setstacksize (&attr, MCOS_LCORE_TASK_0003_STATCK_SIZE);
#else
  mcos_threadattr_setstacksize (&attr, LCORE_STACK_SIZE);
#endif
  tid = mcos_thread_create (&attr, mcos_lcore_task_0003, 0);
  if (tid == MC_EPAR || tid == MC_ENOMEM)
    return;
  tids[num++] = tid;

  for (i = 0; i < num; i++) {
    mcos_thread_start (tids[i], 0);
  }
}