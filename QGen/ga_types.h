#ifndef __GA_TYPES__
#define __GA_TYPES__

#define GAFALSE 0
#define GATRUE 1

typedef char GAINT8;
typedef short GAINT16;
typedef int GAINT32;
typedef double GAREAL;
typedef float GASINGLE;
typedef char* GASTRING;

typedef unsigned char GABOOL;
typedef unsigned char GAUINT8;
typedef unsigned short GAUINT16;
typedef unsigned int GAUINT32;

extern GABOOL gaint8_to_gabool (GAINT8 value);
extern GABOOL gaint16_to_gabool (GAINT16 value);
extern GABOOL gaint32_to_gabool (GAINT32 value);
extern GABOOL gareal_to_gabool (GAREAL value);
extern GABOOL gasingle_to_gabool (GASINGLE value);
extern GABOOL gauint8_to_gabool (GAUINT8 value);
extern GABOOL gauint16_to_gabool (GAUINT16 value);
extern GABOOL gauint32_to_gabool (GAUINT32 value);

#endif
