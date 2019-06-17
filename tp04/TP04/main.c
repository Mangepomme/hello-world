#include "main_c/main.h"
#include <stdio.h>

void main() {
    Main__main_mem mem;
    Main__main_reset(&mem);
    for (;;) {
        Main__main_step(&mem);
    }
}
