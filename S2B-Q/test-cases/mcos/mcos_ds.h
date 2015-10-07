#ifndef MCOS_DS_H
#define MCOS_DS_H

#ifdef NO_DEBUG_PRINTF
#define mcos_debug_printf(X,...)	do { ; } while (0)
#else
#include <stdio.h>
#include <stdarg.h>

#ifndef __GNUC__
#ifndef __attribute__
#define __attribute__ (X)
#endif
#endif

static void
__attribute__ ((unused))
mcos_debug_printf(const char *fmt, ...)
{
  va_list ap;

  va_start (ap, fmt);

  vprintf (fmt, ap);
  fflush (stdout);

  va_end (ap);
}

#endif
#endif
