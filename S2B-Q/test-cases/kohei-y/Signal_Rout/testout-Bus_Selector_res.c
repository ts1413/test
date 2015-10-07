#include <stdio.h>
#include <pthread.h>

/* IN_0000 */
pthread_mutex_t mutex__IN_0000 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond__IN_0000 = PTHREAD_COND_INITIALIZER;
int flag__IN_0000 = 0;

/* IN_0003 */
pthread_mutex_t mutex__IN_0003 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond__IN_0003 = PTHREAD_COND_INITIALIZER;
int flag__IN_0003 = 0;

/* IN_0004 */
pthread_mutex_t mutex__IN_0004 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond__IN_0004 = PTHREAD_COND_INITIALIZER;
int flag__IN_0004 = 0;

/* IN_0100 */
pthread_mutex_t mutex__IN_0100 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond__IN_0100 = PTHREAD_COND_INITIALIZER;
int flag__IN_0100 = 0;

/* OUT_0000 */
pthread_mutex_t mutex__OUT_0000 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond__OUT_0000 = PTHREAD_COND_INITIALIZER;
int flag__OUT_0000 = 0;

/* OUT_0003 */
pthread_mutex_t mutex__OUT_0003 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond__OUT_0003 = PTHREAD_COND_INITIALIZER;
int flag__OUT_0003 = 0;

/* OUT_0004 */
pthread_mutex_t mutex__OUT_0004 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond__OUT_0004 = PTHREAD_COND_INITIALIZER;
int flag__OUT_0004 = 0;

/* OUT_IO0001 */
pthread_mutex_t mutex__OUT_IO0001 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond__OUT_IO0001 = PTHREAD_COND_INITIALIZER;
int flag__OUT_IO0001 = 0;

/* OUT_IO0002 */
pthread_mutex_t mutex__OUT_IO0002 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond__OUT_IO0002 = PTHREAD_COND_INITIALIZER;
int flag__OUT_IO0002 = 0;

void mcos_lcore_task_0000(uint32_t stacd, uintptr_t exinf);
void mcos_lcore_task_0003(uint32_t stacd, uintptr_t exinf);
void mcos_lcore_task_0004(uint32_t stacd, uintptr_t exinf);
void mcos_lcore_task_0100(uint32_t stacd, uintptr_t exinf);
void mcos_lcore_task_IO0001(uint32_t stacd, uintptr_t exinf);
void mcos_lcore_task_IO0002(uint32_t stacd, uintptr_t exinf);

static void *f__mcos_lcore_task_0000 (void *arg)
{
  if (PTHREAD_DEBUG) {
    fputs ("start mcos_lcore_task_0000\n", stdout);
    fflush (stdout);
  }
  mcos_lcore_task_0000 (0, (uintptr_t)arg);
  return NULL;
}

static void *f__mcos_lcore_task_0003 (void *arg)
{
  if (PTHREAD_DEBUG) {
    fputs ("start mcos_lcore_task_0003\n", stdout);
    fflush (stdout);
  }
  mcos_lcore_task_0003 (0, (uintptr_t)arg);
  return NULL;
}

static void *f__mcos_lcore_task_0004 (void *arg)
{
  if (PTHREAD_DEBUG) {
    fputs ("start mcos_lcore_task_0004\n", stdout);
    fflush (stdout);
  }
  mcos_lcore_task_0004 (0, (uintptr_t)arg);
  return NULL;
}

static void *f__mcos_lcore_task_0100 (void *arg)
{
  if (PTHREAD_DEBUG) {
    fputs ("start mcos_lcore_task_0100\n", stdout);
    fflush (stdout);
  }
  mcos_lcore_task_0100 (0, (uintptr_t)arg);
  return NULL;
}

static void *f__mcos_lcore_task_IO0001 (void *arg)
{
  if (PTHREAD_DEBUG) {
    fputs ("start mcos_lcore_task_IO0001\n", stdout);
    fflush (stdout);
  }
  mcos_lcore_task_IO0001 (0, (uintptr_t)arg);
  return NULL;
}

static void *f__mcos_lcore_task_IO0002 (void *arg)
{
  if (PTHREAD_DEBUG) {
    fputs ("start mcos_lcore_task_IO0002\n", stdout);
    fflush (stdout);
  }
  mcos_lcore_task_IO0002 (0, (uintptr_t)arg);
  return NULL;
}
