/*
 *
 *  Author: Jason Torola
 *  Purpose: This code is just to implement a vector "class" in C.
 *           main.c is just a driver. All implementation is in
 *           vector.h and vector.c
 *
 */

/* System headers */
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

/* User headers */
#include "vector.h"

#define COUNT 64000
#define DEBUG 1

int main(void) {
    /* jveci32 *vec = jveci32_alloc(); */
    unsigned long long cnt = 0;
    jveci32 vec;

    for(unsigned int y = 0; y != 1000; ++y) {
        jveci32_init(&vec);

        for(uint32_t x = 0; x != COUNT; ++x) {
            jveci32_pushback(&vec, (int32_t)x);
        }

        jveci32_set(vec, 55, 5552424);
        jveci32_shrink_to_fit(&vec);

        for(uint32_t x = 0; x < jveci32_size(vec); ++x) {
            /*printf("val=%d\n", jveci32_get(vec, (int) x));*/
            cnt += jveci32_get(vec, x);
        }

#if DEBUG
        /* Test that it was created correctly */
        assert(jveci32_size(vec) == COUNT);
        for(int32_t x = 0; x != (int32_t)jveci32_size(vec); ++x) {
            if(x == 55) {
                assert(jveci32_get(vec, 55) == 5552424);
            }
            else {
                assert(jveci32_get(vec, x) == x);
            }
        }
#endif

        jveci32_destroy(&vec);
    }

    printf("Counted %llu times\n", cnt);
    /*jveci32_free(vec);*/
    return 0;
}
