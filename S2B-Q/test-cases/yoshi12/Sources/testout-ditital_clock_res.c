#include <stdio.h>
#include <pthread.h>

void mcos_lcore_task_0000(uint32_t stacd, uintptr_t exinf);
void mcos_lcore_task_0100(uint32_t stacd, uintptr_t exinf);

static void *f__mcos_lcore_task_0000 (void *arg)
{
  if (PTHREAD_DEBUG) {
    fputs ("start mcos_lcore_task_0000\n", stdout);
    fflush (stdout);
  }
  mcos_lcore_task_0000 (0, (uintptr_t)arg);
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
