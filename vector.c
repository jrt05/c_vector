
#include "vector.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include <stdio.h>

#define DEF_SIZE 32           /* Default starting size */

void jveci32_copyvec(jveci32* vec, int32_t* dest);

/* Allocate jveci32 object, then initialize its elements */
jveci32* jveci32_alloc(void) {
    jveci32* v = malloc(sizeof(jveci32));

    jveci32_init(v);

    return v;
}

/* Initialize an allocated jveci32 object */
void jveci32_init(jveci32 *vec) {
    memset(vec, 0, sizeof(jveci32));
    size_t len = DEF_SIZE;

    vec->vec = malloc(len * sizeof(int32_t));
    memset(vec->vec, 0, len * sizeof(int32_t));
    vec->capacity_ = DEF_SIZE;
    vec->size_ = 0;

    return;
}

/* Calls destroy to clean up the jveci32 elements then frees
   the jveci32 object itself */
void jveci32_free(jveci32 *vector) {
    jveci32_destroy(vector);
    free(vector);
    return;
}

/* Destroy the elements of the jveci32. Does not destroy the
   jveci32 object itself */
void jveci32_destroy(jveci32 *vector) {
    free(vector->vec);
    vector->vec = NULL;
    vector->size_ = 0;
    vector->capacity_ = 0;
    return;
}

/* Get an element it index and return it */
int32_t jveci32_get(jveci32 vector, size_t indx) {
    assert(indx < vector.size_);

    if(indx >= vector.size_) return 0;

    return vector.vec[indx];
}

/* Set an element at index */
void jveci32_set(jveci32 vector, size_t indx, int32_t value) {
    assert(indx < vector.size_);

    if(indx >= vector.size_) return;

    vector.vec[indx] = value;

    return;
}

/* Push an element to the end of the vector */
void jveci32_pushback(jveci32* vector, int32_t val) {
    /* assert(indx < vector.size_); */
    if(vector->vec == NULL) return;
    if(vector->capacity_ == 0) return;

    /* No room. Double the size of vec and insert it then */
    if(vector->size_ >= vector->capacity_) {
        size_t cap = vector->capacity_ * 2;
        int32_t *v  = malloc(cap * sizeof(int32_t));
        memset(v, 0, cap * sizeof(int32_t));
        /* Copy old vector to new vector */
        jveci32_copyvec(vector, v);
        free(vector->vec);      /* Free old vector */
        /* Init new vector */
        vector->vec = v;
        v = NULL;
        vector->capacity_ = cap;
    }

    vector->vec[vector->size_++] = val;

    return;
}
/* Remove an element to the end of the vector and return it */
int32_t jveci32_popback(jveci32* vector) {
    int32_t ret = 0;
    if(vector->size_ == 0) return ret;

    /* Grab last element, while dec size */
    ret = vector->vec[--vector->size_];

    /* Clear popped element */
    vector->vec[vector->size_] = 0;

    return ret;
}

/* Shrink the current vector to the current size */
void jveci32_shrink_to_fit(jveci32* vector) {
    /* Verify everything is up to snuff */
    assert(vector != NULL);
    assert(vector->size_ <= vector->capacity_);
    assert(vector->vec != NULL);

    size_t minlen = 1;

    if(vector == NULL) return;      /* Need a real pointer */

    if(vector->size_ >= vector->capacity_) return;  /* Nothing to do if they are equal */

    if(minlen < vector->size_) minlen = vector->size_;

    int32_t *v = malloc(minlen * sizeof(int32_t));
    /* Copy old vector to new vector */
    jveci32_copyvec(vector, v);
    free(vector->vec);
    vector->vec = v;
    v = NULL;
    /* Set current capacity */
    vector->capacity_ = minlen;

    return;
}

/* Copies old vector to new vector */
void jveci32_copyvec(jveci32* vec, int32_t* dest) {
    if(vec->vec == NULL || vec->size_ == 0) return;
    memcpy(dest, vec->vec, vec->size_*sizeof(int32_t));
}

/* Get current vector size */
size_t jveci32_size(jveci32 vector) {
    return vector.size_;
}















