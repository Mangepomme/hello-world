# include <stdlib.h>

# include "math_func.h"

unsigned long fact(unsigned long n){
  unsigned long res = 1;
  for (unsigned long i = 1; i < n+1; i++){
    res = res * i;
  }
  return res;
}

unsigned long fibo(unsigned long n){
  if (n == 0){
    return 0;
  }
  else if (n == 1){
    return 1;
  }
  else{
    return fibo(n-1) + fibo(n-2);
  }
}

unsigned long int_sqrt(unsigned long n){
  if (n == 0){
    return 0;
  }
  else{
    unsigned long res = 1;
    while (res*res > n || n >= (res+1)*(res+1)){
      res = (res + n/res) / 2;
    }
    return res;
  }
}

unsigned long digit_number(unsigned long n){
  if(n == 0){
    return 1;
  }
  else{
    unsigned long res = 0;
    while(n != 0){
      res++;
      n = n / 10;
    }
    return res;
  }
}

unsigned long binary_digit_number(unsigned long n){
  if (n == 0 || n == 1){
    return 1;
  }
  else{
    unsigned long tmp = n;
    unsigned long res = 0;
    while (tmp > 0){
      tmp = tmp >> 1;
      res++;
    }
    return res;
  }
}

unsigned long power_of_2(unsigned long n){
  if (n == 0)
    return 1;
  else{
    unsigned long res = 2;
    for (unsigned long i = 1; i < n; i++){
      res = res * 2;
    }
    return res;
  }
}

unsigned long divisor_sum(unsigned long n){

  if (n == 0 || n == 1)
    return 1;
  unsigned long res = 0;
  for (unsigned long i = 1; i < n; i++)
    if (!(n % i))
      res += i;
  return res;
}
