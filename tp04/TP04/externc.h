#ifndef EXTERNC_H
#define EXTERNC_H

#define _DEFAULT_SOURCE
#define _ISOC99_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "main_c/main_types.h"
#include "types_c/types_types.h"


Types__complex Main__twiddle[1024];
void Externc__printcycle_step(int *cycle, int *idx, int *in, int *out);
void Externc__printcomplex_step(struct Types__complex *v);
void Externc__printvector_step(struct Types__complex *v);
void Externc__my_usleep_step(int *);

#endif

