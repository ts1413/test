#include <mcos/mcos.h>
#include <mcos/mcos_ds.h>
#include <string.h>
#include <assert.h>
#include <string.h>
#include "rtwtypes.h"
#include "DiscreteTimeIntegrator3_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "DiscreteTimeIntegrator3_private.h"

#include "testout-DiscreteTimeIntegrator3_res.c"
#include "testout-DiscreteTimeIntegrator3.h"


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
struct tag_RTM_DiscreteTimeIntegrato_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
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
   To: DiscreteTimeIntegrator3_Discrete_TimeIntegrator */
typedef struct {
  int flag__0000_0004;
  real_T DiscreteTimeIntegrator3_In1_1;
  real_T DiscreteTimeIntegrator3_In2_1;
  real_T DiscreteTimeIntegrator3_In3_1;
} TYPE_0000_0004;
TYPE_0000_0004 CH_0000_0004;

/* From: DiscreteTimeIntegrator3_In1
   To: t0 */
typedef struct {
  int flag__IO0001_0000;
  real_T DiscreteTimeIntegrator3_In1_1;
} TYPE_IO0001_0000;
TYPE_IO0001_0000 CH_IO0001_0000;

/* From: DiscreteTimeIntegrator3_In2
   To: t0 */
typedef struct {
  int flag__IO0002_0000;
  real_T DiscreteTimeIntegrator3_In2_1;
} TYPE_IO0002_0000;
TYPE_IO0002_0000 CH_IO0002_0000;

/* From: DiscreteTimeIntegrator3_In3
   To: t0 */
typedef struct {
  int flag__IO0003_0000;
  real_T DiscreteTimeIntegrator3_In3_1;
} TYPE_IO0003_0000;
TYPE_IO0003_0000 CH_IO0003_0000;

/* From: DiscreteTimeIntegrator3_Discrete_TimeIntegrator
   To: extout */
typedef struct {
  int flag__0004_0100;
  real_T DiscreteTimeIntegrator3_Discrete_TimeIntegrator_1;
  real_T DiscreteTimeIntegrator3_Discrete_TimeIntegrator_2;
} TYPE_0004_0100;
TYPE_0004_0100 CH_0004_0100;

/*
 * Tasks
 */

TASK_CODE_PREPARE(0000)

/* Block: t0 */
void mcos_lcore_task_0000(uint32_t stacd, uintptr_t extinfo)
{  /* input channel bit vector */
  CH__VEC(IN_0000,3);

  /* omit output channel bit vector */
  /* CH__VEC(OUT_0000,1); */
  real_T DiscreteTimeIntegrator3_In1_1;
  real_T DiscreteTimeIntegrator3_In2_1;
  real_T DiscreteTimeIntegrator3_In3_1;

  /* Common Initialization */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize task context */
{
  DiscreteTimeIntegrator3_In1_1 = 0.0;
}
{
  DiscreteTimeIntegrator3_In2_1 = 0.0;
}
{
  DiscreteTimeIntegrator3_In3_1 = 0.0;

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
      /* input: DiscreteTimeIntegrator3_In1 */
      if (CH__BITCHECK(IN_0000,0) == 0 && CH_IO0001_0000.flag__IO0001_0000 == 1) {
	DiscreteTimeIntegrator3_In1_1 = CH_IO0001_0000.DiscreteTimeIntegrator3_In1_1;
	CH__SYNCM();
	CH_IO0001_0000.flag__IO0001_0000 = 0;
	CH__EVENT(TASK_0000, OUT_IO0001);
	CH__BITSET(IN_0000,0);
      }

      /* input: DiscreteTimeIntegrator3_In2 */
      if (CH__BITCHECK(IN_0000,1) == 0 && CH_IO0002_0000.flag__IO0002_0000 == 1) {
	DiscreteTimeIntegrator3_In2_1 = CH_IO0002_0000.DiscreteTimeIntegrator3_In2_1;
	CH__SYNCM();
	CH_IO0002_0000.flag__IO0002_0000 = 0;
	CH__EVENT(TASK_0000, OUT_IO0002);
	CH__BITSET(IN_0000,1);
      }

      /* input: DiscreteTimeIntegrator3_In3 */
      if (CH__BITCHECK(IN_0000,2) == 0 && CH_IO0003_0000.flag__IO0003_0000 == 1) {
	DiscreteTimeIntegrator3_In3_1 = CH_IO0003_0000.DiscreteTimeIntegrator3_In3_1;
	CH__SYNCM();
	CH_IO0003_0000.flag__IO0003_0000 = 0;
	CH__EVENT(TASK_0000, OUT_IO0003);
	CH__BITSET(IN_0000,2);
      }

      if (CH__COMPLETED(IN_0000,3)) {
	CH__END_LOG(IN_0000);
	break;
      }

      CH__TASK_SCHED(IN_0000,CH__VEC_NAME(IN_0000),3);

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
      /* output: DiscreteTimeIntegrator3_Discrete_TimeIntegrator */
      if (CH_0000_0004.flag__0000_0004 == 0) {
	CH_0000_0004.DiscreteTimeIntegrator3_In1_1 = DiscreteTimeIntegrator3_In1_1;
	CH_0000_0004.DiscreteTimeIntegrator3_In2_1 = DiscreteTimeIntegrator3_In2_1;
	CH_0000_0004.DiscreteTimeIntegrator3_In3_1 = DiscreteTimeIntegrator3_In3_1;
	CH__SYNCM();
	CH_0000_0004.flag__0000_0004 = 1;
	CH__EVENT(TASK_0000,IN_0004);
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
  real_T DiscreteTimeIntegrator3_Discrete_TimeIntegrator_1;
  real_T DiscreteTimeIntegrator3_Discrete_TimeIntegrator_2;

  /* Common Initialization */
  rt_InitInfAndNaN(sizeof(real_T));

#ifdef TASK_INITIALIZE_0100_COMPLETED
  TASK_INITIALIZE_0100_COMPLETED();
#endif

  /* task loop */
  while (1) {

    /* wait input channel */
    while (1) {
      /* input: DiscreteTimeIntegrator3_Discrete_TimeIntegrator */
      if (CH_0004_0100.flag__0004_0100 == 1) {
	DiscreteTimeIntegrator3_Discrete_TimeIntegrator_1 = CH_0004_0100.DiscreteTimeIntegrator3_Discrete_TimeIntegrator_1;
	DiscreteTimeIntegrator3_Discrete_TimeIntegrator_2 = CH_0004_0100.DiscreteTimeIntegrator3_Discrete_TimeIntegrator_2;
	CH__SYNCM();
	CH_0004_0100.flag__0004_0100 = 0;
	CH__EVENT(TASK_0100, OUT_0004);
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

/* Block: DiscreteTimeIntegrator3_In1 */
void mcos_lcore_task_IO0001(uint32_t stacd, uintptr_t extinfo)
{  /* omit output channel bit vector */
  /* CH__VEC(OUT_IO0001,1); */
  real_T DiscreteTimeIntegrator3_In1_1;

  /* Common Initialization */
  rt_InitInfAndNaN(sizeof(real_T));

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
	CH_IO0001_0000.DiscreteTimeIntegrator3_In1_1 = DiscreteTimeIntegrator3_In1_1;
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

/* Block: DiscreteTimeIntegrator3_In2 */
void mcos_lcore_task_IO0002(uint32_t stacd, uintptr_t extinfo)
{  /* omit output channel bit vector */
  /* CH__VEC(OUT_IO0002,1); */
  real_T DiscreteTimeIntegrator3_In2_1;

  /* Common Initialization */
  rt_InitInfAndNaN(sizeof(real_T));

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
	CH_IO0002_0000.DiscreteTimeIntegrator3_In2_1 = DiscreteTimeIntegrator3_In2_1;
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

TASK_CODE_PREPARE(IO0003)

/* Block: DiscreteTimeIntegrator3_In3 */
void mcos_lcore_task_IO0003(uint32_t stacd, uintptr_t extinfo)
{  /* omit output channel bit vector */
  /* CH__VEC(OUT_IO0003,1); */
  real_T DiscreteTimeIntegrator3_In3_1;

  /* Common Initialization */
  rt_InitInfAndNaN(sizeof(real_T));

#ifdef TASK_INITIALIZE_IO0003_COMPLETED
  TASK_INITIALIZE_IO0003_COMPLETED();
#endif

  /* task loop */
  while (1) {

    /****************************************************
     *
     * You should insert some codes here for external input.
     *
     ****************************************************/

#ifdef TASK_EXECUTE_IO0003_COMPLETED
    TASK_EXECUTE_IO0003_COMPLETED();
#endif

    /* wait output channel */
    while (1) {
      /* output: t0 */
      if (CH_IO0003_0000.flag__IO0003_0000 == 0) {
	CH_IO0003_0000.DiscreteTimeIntegrator3_In3_1 = DiscreteTimeIntegrator3_In3_1;
	CH__SYNCM();
	CH_IO0003_0000.flag__IO0003_0000 = 1;
	CH__EVENT(TASK_IO0003,IN_0000);
	CH__END_LOG(OUT_IO0003);
	break;
      }

      CH__TASK_SCHED(OUT_IO0003,NULL,1);

      CH__MEM_BARRIER();
    }

#ifdef TASK_OUT_IO0003_COMPLETED
    TASK_OUT_IO0003_COMPLETED();
#endif
  }
}

TASK_CODE_PREPARE(0004)

/* Block: DiscreteTimeIntegrator3_Discrete_TimeIntegrator */
void mcos_lcore_task_0004(uint32_t stacd, uintptr_t extinfo)
{  /* omit input channel bit vector */
  /* CH__VEC(IN_0004,1); */

  /* omit output channel bit vector */
  /* CH__VEC(OUT_0004,1); */

  /* Real-Time Model Object */
  RT_MODEL_DiscreteTimeIntegrat_T DiscreteTimeIntegrator3_M_;
  RT_MODEL_DiscreteTimeIntegrat_T * const DiscreteTimeIntegrator3_M = &DiscreteTimeIntegrator3_M_;

  /* states */
  struct {
    real_T Discrete_TimeIntegrator_DSTATE;
    int8_T Discrete_TimeIntegrator_PrevRes;
    uint8_T Discrete_TimeIntegrator_IC_LOAD;
  } DiscreteTimeIntegrator3_DW;

  /* params */
  struct {
    real_T Discrete_TimeIntegrator_gainval;
    real_T Discrete_TimeIntegrator_UpperSa;
    real_T Discrete_TimeIntegrator_LowerSa;
  } DiscreteTimeIntegrator3_P = {
  };
  real_T DiscreteTimeIntegrator3_In1_1;
  real_T DiscreteTimeIntegrator3_In2_1;
  real_T DiscreteTimeIntegrator3_In3_1;
  real_T DiscreteTimeIntegrator3_Discrete_TimeIntegrator_1;
  real_T DiscreteTimeIntegrator3_Discrete_TimeIntegrator_2;

  /* Common Initialization */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize Real-Time Model Object */
  /* initialize real-time model */
  (void) memset((void *)DiscreteTimeIntegrator3_M, 0,
                sizeof(RT_MODEL_DiscreteTimeIntegrat_T));

  /* initialize state structure */
  memset(&DiscreteTimeIntegrator3_DW, 0, sizeof DiscreteTimeIntegrator3_DW);

  /* initialize states */
{
  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete_TimeIntegrator' */
  DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_IC_LOAD = 1U;
  DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_PrevRes = 2;
}

  /* initialize task context */
{
  DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_UpperSa = rtInf;
  DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_LowerSa = rtMinusInf;

  DiscreteTimeIntegrator3_Discrete_TimeIntegrator_1 = 0.0;
  DiscreteTimeIntegrator3_Discrete_TimeIntegrator_2 = 0.0;

}

#ifdef TASK_INITIALIZE_0004_COMPLETED
  TASK_INITIALIZE_0004_COMPLETED();
#endif

  /* task loop */
  while (1) {

    /* wait input channel */
    while (1) {
      /* input(with update): t0 */
      if (CH_0000_0004.flag__0000_0004 == 1) {
	DiscreteTimeIntegrator3_In1_1 = CH_0000_0004.DiscreteTimeIntegrator3_In1_1;
	DiscreteTimeIntegrator3_In2_1 = CH_0000_0004.DiscreteTimeIntegrator3_In2_1;
	DiscreteTimeIntegrator3_In3_1 = CH_0000_0004.DiscreteTimeIntegrator3_In3_1;
	CH__SYNCM();
	CH_0000_0004.flag__0000_0004 = 0;
	CH__EVENT(TASK_0004, OUT_0000);
	CH__END_LOG(IN_0004);
	break;
      }

      CH__TASK_SCHED(IN_0004,NULL,1);

      CH__MEM_BARRIER();
    }

#ifdef TASK_IN_0004_COMPLETED
    TASK_IN_0004_COMPLETED();
#endif

    /* C code */
        {
{

  if (DiscreteTimeIntegrator3_M->Timing.TaskCounters.TID[1] == 0) {

    /* DiscreteIntegrator: '<Root>/Discrete_TimeIntegrator' incorporates:
     *  Inport: '<Root>/In1'
     *  Inport: '<Root>/In2'
     *  Inport: '<Root>/In3'
     */
    if (DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_IC_LOAD != 0) {
      DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_DSTATE =
        DiscreteTimeIntegrator3_In3_1;
      if (DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_DSTATE >=
          DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_UpperSa) {
        DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_DSTATE =
          DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_UpperSa;
      } else {
        if (DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_DSTATE <=
            DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_LowerSa) {
          DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_DSTATE =
            DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_LowerSa;
        }
      }
    }

    if ((DiscreteTimeIntegrator3_In2_1 > 0.0) &&
        (DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_PrevRes <= 0)) {
      DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_DSTATE =
        DiscreteTimeIntegrator3_In3_1;
      if (DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_DSTATE >=
          DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_UpperSa) {
        DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_DSTATE =
          DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_UpperSa;
      } else {
        if (DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_DSTATE <=
            DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_LowerSa) {
          DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_DSTATE =
            DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_LowerSa;
        }
      }
    }

    DiscreteTimeIntegrator3_Discrete_TimeIntegrator_1 =
      DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_gainval *
      DiscreteTimeIntegrator3_In1_1 +
      DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_DSTATE;
    if (DiscreteTimeIntegrator3_Discrete_TimeIntegrator_1 >=
        DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_UpperSa) {
      DiscreteTimeIntegrator3_Discrete_TimeIntegrator_1 =
        DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_UpperSa;
      DiscreteTimeIntegrator3_Discrete_TimeIntegrator_2 = 1.0;
    } else if (DiscreteTimeIntegrator3_Discrete_TimeIntegrator_1 <=
               DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_LowerSa) {
      DiscreteTimeIntegrator3_Discrete_TimeIntegrator_1 =
        DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_LowerSa;
      DiscreteTimeIntegrator3_Discrete_TimeIntegrator_2 = -1.0;
    } else {
      DiscreteTimeIntegrator3_Discrete_TimeIntegrator_2 = 0.0;
    }

    /* End of DiscreteIntegrator: '<Root>/Discrete_TimeIntegrator' */

  }

}

    }

#ifdef TASK_EXECUTE_0004_COMPLETED
    TASK_EXECUTE_0004_COMPLETED();
#endif

    /* wait output channel */
    while (1) {
      /* output: extout */
      if (CH_0004_0100.flag__0004_0100 == 0) {
	CH_0004_0100.DiscreteTimeIntegrator3_Discrete_TimeIntegrator_1 = DiscreteTimeIntegrator3_Discrete_TimeIntegrator_1;
	CH_0004_0100.DiscreteTimeIntegrator3_Discrete_TimeIntegrator_2 = DiscreteTimeIntegrator3_Discrete_TimeIntegrator_2;
	CH__SYNCM();
	CH_0004_0100.flag__0004_0100 = 1;
	CH__EVENT(TASK_0004,IN_0100);
	CH__END_LOG(OUT_0004);
	break;
      }

      CH__TASK_SCHED(OUT_0004,NULL,1);

      CH__MEM_BARRIER();
    }

#ifdef TASK_OUT_0004_COMPLETED
    TASK_OUT_0004_COMPLETED();
#endif

    /* wait input channel */
    while (1) {
      /* update: t0 */
      if (CH_0000_0004.flag__0000_0004 == 1) {
	DiscreteTimeIntegrator3_In1_1 = CH_0000_0004.DiscreteTimeIntegrator3_In1_1;
	DiscreteTimeIntegrator3_In2_1 = CH_0000_0004.DiscreteTimeIntegrator3_In2_1;
	DiscreteTimeIntegrator3_In3_1 = CH_0000_0004.DiscreteTimeIntegrator3_In3_1;
	CH__SYNCM();
	CH_0000_0004.flag__0000_0004 = 0;
	CH__EVENT(TASK_0004, OUT_0000);
	CH__END_LOG(IN_0004);
	break;
      }

      CH__TASK_SCHED(IN_0004,NULL,1);

      CH__MEM_BARRIER();
    }

#ifdef TASK_UPDATE_IN_0004_COMPLETED
    TASK_UPDATE_IN_0004_COMPLETED();
#endif

    /* Update */
    {
{

  if (DiscreteTimeIntegrator3_M->Timing.TaskCounters.TID[1] == 0) {

    /* Update for DiscreteIntegrator: '<Root>/Discrete_TimeIntegrator' incorporates:
     *  Inport: '<Root>/In1'
     *  Inport: '<Root>/In2'
     */
    DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_IC_LOAD = 0U;
    DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_DSTATE =
      DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_gainval *
      DiscreteTimeIntegrator3_In1_1 +
      DiscreteTimeIntegrator3_Discrete_TimeIntegrator_1;
    if (DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_DSTATE >=
        DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_UpperSa) {
      DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_DSTATE =
        DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_UpperSa;
    } else {
      if (DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_DSTATE <=
          DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_LowerSa) {
        DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_DSTATE =
          DiscreteTimeIntegrator3_P.Discrete_TimeIntegrator_LowerSa;
      }
    }

    if (DiscreteTimeIntegrator3_In2_1 > 0.0) {
      DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_PrevRes = 1;
    } else if (DiscreteTimeIntegrator3_In2_1 < 0.0) {
      DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_PrevRes = -1;
    } else if (DiscreteTimeIntegrator3_In2_1 == 0.0) {
      DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_PrevRes = 0;
    } else {
      DiscreteTimeIntegrator3_DW.Discrete_TimeIntegrator_PrevRes = 2;
    }

    /* End of Update for DiscreteIntegrator: '<Root>/Discrete_TimeIntegrator' */

  }

}

    }

#ifdef TASK_UPDATE_0004_COMPLETED
    TASK_UPDATE_0004_COMPLETED();
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
  static mcos_id_t tids[6];
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

#ifdef MCOS_LCORE_TASK_IO0003_STATCK_SIZE
  mcos_threadattr_setstacksize (&attr, MCOS_LCORE_TASK_IO0003_STATCK_SIZE);
#else
  mcos_threadattr_setstacksize (&attr, LCORE_STACK_SIZE);
#endif
  tid = mcos_thread_create (&attr, mcos_lcore_task_IO0003, 0);
  if (tid == MC_EPAR || tid == MC_ENOMEM)
    return;
  tids[num++] = tid;

#ifdef MCOS_LCORE_TASK_0004_STATCK_SIZE
  mcos_threadattr_setstacksize (&attr, MCOS_LCORE_TASK_0004_STATCK_SIZE);
#else
  mcos_threadattr_setstacksize (&attr, LCORE_STACK_SIZE);
#endif
  tid = mcos_thread_create (&attr, mcos_lcore_task_0004, 0);
  if (tid == MC_EPAR || tid == MC_ENOMEM)
    return;
  tids[num++] = tid;

  for (i = 0; i < num; i++) {
    mcos_thread_start (tids[i], 0);
  }
}
