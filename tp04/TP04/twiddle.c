#include <math.h>
#include <complex.h>

#include <types_c/types_types.h>
void init_twiddle1024(Types__complex*twiddle) {
  int i,span ;
  float Complex__pi = 3.14159265358979;
  // Init the twiddles
  for(span=1;span<=512;span<<=1) {
    float primitive_root = -Complex__pi/span ;
    for(i=0;i<span;i++) {
      Types__complex t =
	{
	  .re = cosf(primitive_root*i) ,
	  .im = sinf(primitive_root*i)
	} ;
      twiddle[span+i] = t ;
    }
  }
}
