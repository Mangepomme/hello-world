#include "externc.h"

void Externc__printcycle_step(int *cycle, int *idx, int *in, int *out)
{
    char * str_cycle = "Fast";
    if (*cycle == 1)
        str_cycle = "GNC";
    else if (*cycle == 0)
        str_cycle = "Thermal";
    printf("Cycle : %s, idx = %d\n", str_cycle, *idx);
    if (*cycle)
        printf("in = %d, out = %d\n", *in, *out);

}

void Externc__printcomplex_step(struct Types__complex *v)
{
    printf("--printcomplex-: (re=%f, im=%f)\n", v->re, v->im);
}

void Externc__printvector_step(struct Types__complex *v)
{
    printf("Vector: \n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d = ", i);
        Externc__printcomplex_step(&v[i]);
    }
}

void Externc__my_usleep_step(int *c)
{
    usleep(*c);
}
