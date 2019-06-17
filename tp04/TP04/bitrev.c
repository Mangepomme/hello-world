#include "types_c/types_types.h"
#include <string.h>
// This function is adapted from
//   http://www.katjaas.nl/bitreversal/bitreversal.html

// Change this type with the type of your choice
// (in this TP, Types__complex, corresponding to
// the complex type defined in Heptagon,
// in file complex.ept).
#define datatype Types__complex
static inline void swap(unsigned int forward,
			unsigned int rev,
			datatype *data) {
  datatype tmp;  
  tmp = data[forward];               
  data[forward] = data[rev];
  data[rev] = tmp;
}
// Main function
void bitrev(datatype *data, unsigned int logN)
{
  // Initialization of frequently used constants
  const unsigned int N = 1<<logN;
  const unsigned int halfn = N>>1;   
  const unsigned int quartn = N>>2;
  const unsigned int nmin1 = N-1;

  // Variables
  unsigned int i, forward, rev, zeros;
  unsigned int nodd, noddrev;

  // Variable initialization
  forward = halfn;
  rev = 1;

  // start of bitreversed permutation loop, N/4 iterations
  for(i=quartn; i; i--) {
    // Gray code generator for even values:      
    nodd = ~i;                                  // counting ones is easier
    for(zeros=0; nodd&1; zeros++) nodd >>= 1;   // find trailing zeros in i
    forward ^= 2 << zeros;                      // toggle one bit of forward
    rev ^= quartn >> zeros;                     // toggle one bit of rev
    
    // swap even and ~even conditionally
    if(forward<rev) {
      swap(forward, rev, data);
      nodd = nmin1 ^ forward;                   // compute the bitwise negations
      noddrev = nmin1 ^ rev;       
      swap(nodd, noddrev, data);                // swap bitwise-negated pairs
    }
      
    nodd = forward ^ 1;                         // compute the odd values from the even
    noddrev = rev ^ halfn;
    swap(nodd, noddrev, data);                  // swap odd unconditionally
  }   
}
// Instantiation for size 16, working with Heptagon's
// calling conventions.
void Fftc__bitrev8_step(Types__complex*i,Types__complex*o) {
  memcpy(o,i,8*sizeof(Types__complex)) ;
  bitrev(o,3) ;
}

void Fftc__bitrev16_step(Types__complex*i,Types__complex*o) {
  memcpy(o,i,16*sizeof(Types__complex)) ;
  bitrev(o,4) ;
}

void Fftc__bitrev32_step(Types__complex*i,Types__complex*o) {
  memcpy(o,i,32*sizeof(Types__complex)) ;
  bitrev(o,5) ;
}

void Fftc__bitrev64_step(Types__complex*i,Types__complex*o) {
  memcpy(o,i,64*sizeof(Types__complex)) ;
  bitrev(o,6) ;
}

void Fftc__bitrev128_step(Types__complex*i,Types__complex*o) {
  memcpy(o,i,128*sizeof(Types__complex)) ;
  bitrev(o,7) ;
}

void Fftc__bitrev256_step(Types__complex*i,Types__complex*o) {
  memcpy(o,i,256*sizeof(Types__complex)) ;
  bitrev(o,8) ;
}

void Fftc__bitrev512_step(Types__complex*i,Types__complex*o) {
  memcpy(o,i,512*sizeof(Types__complex)) ;
  bitrev(o,9) ;
}

void Fftc__bitrev1024_step(Types__complex*i,Types__complex*o) {
  memcpy(o,i,1024*sizeof(Types__complex)) ;
  bitrev(o,10) ;
}
