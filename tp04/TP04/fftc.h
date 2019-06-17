#ifndef FFTC_H
#define FFTC_H

#include "types_c/types_types.h"

extern Types__complex Fft__twiddle[1024];
void Fftc__bitrev16_step(Types__complex*i,Types__complex*o);
void Fftc__bitrev8_step(Types__complex*i,Types__complex*o);
void Fftc__bitrev32_step(Types__complex*i,Types__complex*o);
void Fftc__bitrev64_step(Types__complex*i,Types__complex*o);
void Fftc__bitrev128_step(Types__complex*i,Types__complex*o);
void Fftc__bitrev256_step(Types__complex*i,Types__complex*o);
void Fftc__bitrev512_step(Types__complex*i,Types__complex*o);
void Fftc__bitrev1024_step(Types__complex*i,Types__complex*o);

#endif

