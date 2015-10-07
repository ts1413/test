#include <mcos/mcos.h>
#include <mcos/mcos_ds.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "LookupTable2D_types.h"
#include "LookupTable2D_private.h"

#include "testout-LookupTable2D_res.c"
#include "testout-LookupTable2D.h"


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
struct tag_RTM_LookupTable2D_T {
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
   To: LookupTable2D_2_DLookupTable */
typedef struct {
  int flag__0000_0003;
  real_T LookupTable2D_In1_1;
  real_T LookupTable2D_In2_1;
} TYPE_0000_0003;
TYPE_0000_0003 CH_0000_0003;

/* From: LookupTable2D_In1
   To: t0 */
typedef struct {
  int flag__IO0001_0000;
  real_T LookupTable2D_In1_1;
} TYPE_IO0001_0000;
TYPE_IO0001_0000 CH_IO0001_0000;

/* From: LookupTable2D_In2
   To: t0 */
typedef struct {
  int flag__IO0002_0000;
  real_T LookupTable2D_In2_1;
} TYPE_IO0002_0000;
TYPE_IO0002_0000 CH_IO0002_0000;

/* From: LookupTable2D_2_DLookupTable
   To: extout */
typedef struct {
  int flag__0003_0100;
  real_T LookupTable2D_2_DLookupTable_1;
} TYPE_0003_0100;
TYPE_0003_0100 CH_0003_0100;

/*
 * Tasks
 */

TASK_CODE_PREPARE(0000)

/* Block: t0 */
void mcos_lcore_task_0000(uint32_t stacd, uintptr_t extinfo)
{  /* input channel bit vector */
  CH__VEC(IN_0000,2);

  /* omit output channel bit vector */
  /* CH__VEC(OUT_0000,1); */
  real_T LookupTable2D_In1_1;
  real_T LookupTable2D_In2_1;

  /* initialize task context */
{
  LookupTable2D_In1_1 = 0.0;
}
{
  LookupTable2D_In2_1 = 0.0;
}

#ifdef TASK_INITIALIZE_0000_COMPLETED
  TASK_INITIALIZE_0000_COMPLETED();
#endif

  /* task loop */
  while (1) {

    /* clear input channel bit vector */
    CH__VEC_INIT(IN_0000);

    /* wait input channel */
    while (1) {
      /* input: LookupTable2D_In1 */
      if (CH__BITCHECK(IN_0000,0) == 0 && CH_IO0001_0000.flag__IO0001_0000 == 1) {
	LookupTable2D_In1_1 = CH_IO0001_0000.LookupTable2D_In1_1;
	CH__SYNCM();
	CH_IO0001_0000.flag__IO0001_0000 = 0;
	CH__EVENT(TASK_0000, OUT_IO0001);
	CH__BITSET(IN_0000,0);
      }

      /* input: LookupTable2D_In2 */
      if (CH__BITCHECK(IN_0000,1) == 0 && CH_IO0002_0000.flag__IO0002_0000 == 1) {
	LookupTable2D_In2_1 = CH_IO0002_0000.LookupTable2D_In2_1;
	CH__SYNCM();
	CH_IO0002_0000.flag__IO0002_0000 = 0;
	CH__EVENT(TASK_0000, OUT_IO0002);
	CH__BITSET(IN_0000,1);
      }

      if (CH__COMPLETED(IN_0000,2)) {
	CH__END_LOG(IN_0000);
	break;
      }

      CH__TASK_SCHED(IN_0000,CH__VEC_NAME(IN_0000),2);

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
      /* output: LookupTable2D_2_DLookupTable */
      if (CH_0000_0003.flag__0000_0003 == 0) {
	CH_0000_0003.LookupTable2D_In1_1 = LookupTable2D_In1_1;
	CH_0000_0003.LookupTable2D_In2_1 = LookupTable2D_In2_1;
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
{  /* omit input channel bit vector */
  /* CH__VEC(IN_0100,1); */
  real_T LookupTable2D_2_DLookupTable_1;

#ifdef TASK_INITIALIZE_0100_COMPLETED
  TASK_INITIALIZE_0100_COMPLETED();
#endif

  /* task loop */
  while (1) {

    /* wait input channel */
    while (1) {
      /* input: LookupTable2D_2_DLookupTable */
      if (CH_0003_0100.flag__0003_0100 == 1) {
	LookupTable2D_2_DLookupTable_1 = CH_0003_0100.LookupTable2D_2_DLookupTable_1;
	CH__SYNCM();
	CH_0003_0100.flag__0003_0100 = 0;
	CH__EVENT(TASK_0100, OUT_0003);
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

/* Block: LookupTable2D_In1 */
void mcos_lcore_task_IO0001(uint32_t stacd, uintptr_t extinfo)
{  /* omit output channel bit vector */
  /* CH__VEC(OUT_IO0001,1); */
  real_T LookupTable2D_In1_1;

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
	CH_IO0001_0000.LookupTable2D_In1_1 = LookupTable2D_In1_1;
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

TASK_CODE_PREPARE(IO0002)

/* Block: LookupTable2D_In2 */
void mcos_lcore_task_IO0002(uint32_t stacd, uintptr_t extinfo)
{  /* omit output channel bit vector */
  /* CH__VEC(OUT_IO0002,1); */
  real_T LookupTable2D_In2_1;

#ifdef TASK_INITIALIZE_IO0002_COMPLETED
  TASK_INITIALIZE_IO0002_COMPLETED();
#endif

  /* task loop */
  while (1) {

    /****************************************************
     *
     * You should insert some codes here for external input.
     *
     ****************************************************/

#ifdef TASK_EXECUTE_IO0002_COMPLETED
    TASK_EXECUTE_IO0002_COMPLETED();
#endif

    /* wait output channel */
    while (1) {
      /* output: t0 */
      if (CH_IO0002_0000.flag__IO0002_0000 == 0) {
	CH_IO0002_0000.LookupTable2D_In2_1 = LookupTable2D_In2_1;
	CH__SYNCM();
	CH_IO0002_0000.flag__IO0002_0000 = 1;
	CH__EVENT(TASK_IO0002,IN_0000);
	CH__END_LOG(OUT_IO0002);
	break;
      }

      CH__TASK_SCHED(OUT_IO0002,NULL,1);

      CH__MEM_BARRIER();
    }

#ifdef TASK_OUT_IO0002_COMPLETED
    TASK_OUT_IO0002_COMPLETED();
#endif
  }
}

TASK_CODE_PREPARE(0003)

/* Block: LookupTable2D_2_DLookupTable */
void mcos_lcore_task_0003(uint32_t stacd, uintptr_t extinfo)
{  /* omit input channel bit vector */
  /* CH__VEC(IN_0003,1); */

  /* omit output channel bit vector */
  /* CH__VEC(OUT_0003,1); */

  /* params */
  struct {
    real_T _DLookupTable_tableData[9];
    real_T _DLookupTable_bp01Data[3];
    real_T _DLookupTable_bp02Data[3];
    uint32_T _DLookupTable_maxIndex[2];
  } LookupTable2D_P = {
  };
  real_T LookupTable2D_In1_1;
  real_T LookupTable2D_In2_1;
  real_T LookupTable2D_2_DLookupTable_1;

  /* functions */

real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[],
                     const real_T table[], const uint32_T maxIndex[], uint32_T
                     stride)
{
  real_T frac;
  uint32_T bpIndices[2];
  real_T fractions[2];
  real_T yL_1d;
  uint32_T iRght;
  uint32_T bpIdx;
  uint32_T iLeft;

  /* Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U]
      - 1U]);
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U]
      - 1U]);
  }

  /* Interpolation 2-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_1d = (table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx];
  bpIdx += stride;
  return (((table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx]) -
          yL_1d) * frac + yL_1d;
}

  /* initialize task context */
{
  LookupTable2D_2_DLookupTable_1 = 0.0;

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
	LookupTable2D_In1_1 = CH_0000_0003.LookupTable2D_In1_1;
	LookupTable2D_In2_1 = CH_0000_0003.LookupTable2D_In2_1;
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

  /* Lookup_n-D: '<Root>/2_DLookupTable' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  LookupTable2D_2_DLookupTable_1 = look2_binlxpw(LookupTable2D_In1_1,
    LookupTable2D_In2_1, LookupTable2D_P._DLookupTable_bp01Data,
    LookupTable2D_P._DLookupTable_bp02Data,
    LookupTable2D_P._DLookupTable_tableData,
    LookupTable2D_P._DLookupTable_maxIndex, 3U);

}

    }

#ifdef TASK_EXECUTE_0003_COMPLETED
    TASK_EXECUTE_0003_COMPLETED();
#endif

    /* wait output channel */
    while (1) {
      /* output: extout */
      if (CH_0003_0100.flag__0003_0100 == 0) {
	CH_0003_0100.LookupTable2D_2_DLookupTable_1 = LookupTable2D_2_DLookupTable_1;
	CH__SYNCM();
	CH_0003_0100.flag__0003_0100 = 1;
	CH__EVENT(TASK_0003,IN_0100);
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

#ifdef MCOS_LCORE_TASK_IO0002_STATCK_SIZE
  mcos_threadattr_setstacksize (&attr, MCOS_LCORE_TASK_IO0002_STATCK_SIZE);
#else
  mcos_threadattr_setstacksize (&attr, LCORE_STACK_SIZE);
#endif
  tid = mcos_thread_create (&attr, mcos_lcore_task_IO0002, 0);
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
