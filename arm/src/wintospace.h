#include <stdio.h>
#include < math.h > 
#include <stdlib.h>
#define EPSILON 10;
#include <string.h>
#define allowerr 5;
#define koef 1;

//#define debugL

#ifndef START

#define START
typedef struct crd {
    int x;
    int y;
};
typedef struct globConv {
    crd one;
    crd two;
    crd three;
    crd four;
    crd object;
    int radius;
};
int read (char* in, char* out);
int AreSame(float a, float b);
#endif
