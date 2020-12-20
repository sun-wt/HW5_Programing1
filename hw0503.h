#ifndef HW0503_H_INCLUDE
#define HW0503_H_INCLUDE

#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>

void Plus(int32_t degree1,int32_t degree2,int32_t *coefficients1,int32_t *coefficients2,int32_t *plus);

void Minus(int32_t degree1,int32_t degree2,int32_t *coefficients1,int32_t *coefficients2,int32_t *minus);

void Mul(int32_t degree1,int32_t degree2,int32_t *coefficients1,int32_t *coefficients2);

char device(int32_t degree,int32_t *coefficients);
#endif
