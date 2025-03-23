#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t size_;        /* Current vector length */
    size_t capacity_;    /* Current vector max size */
    int32_t *vec;           /* Array to hold the elements */

} jveci32;

/* Allocate a vector object */
jveci32* jveci32_alloc(void);

/* Initialize vector */
void jveci32_init(jveci32*);

/* Destroy a vector object */
void jveci32_destroy(jveci32* vector);

/* Free vector */
void jveci32_free(jveci32* vector);

/* Access memory at this index */
int jveci32_get(jveci32 vector, size_t indx); /* access memory at this index */

/* Set a value at index */
void jveci32_set(jveci32 vector, size_t indx, int32_t value);

/* Get the current vector length */
size_t jveci32_size(jveci32 vector);

 /* Add an element to the end of the vector */
void jveci32_pushback(jveci32* vector, int32_t val);

/* Remove an element to the end of the vector and return it */
int32_t jveci32_popback(jveci32* vector);

/* Shrink the current vector to the current size */
void jveci32_shrink_to_fit(jveci32* vector);

#endif 
