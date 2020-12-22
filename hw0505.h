#ifndef HW0505_H_INCLUDE
#define HW0505_H_INCLUDE

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>
#include<time.h>

void RandomBomb(char (*ans)[20],char (*ans1)[20],int32_t width,int32_t height,int32_t mine);
void Open(char (*visual)[20],char (*ans)[20],char (*ans1)[20],int32_t width,int32_t height,int32_t mine,int32_t row,int32_t column);
void Check(char (*visual)[20],char (*ans)[20],char (*ans1)[20],int32_t width,int32_t height,int32_t mine,int32_t row,int32_t column);
void Flag(char (*visual)[20],int32_t width,int32_t height);
void Printer(char (*visual)[20],int32_t width,int32_t height);
void win(char (*visual)[20],int32_t width,int32_t height,int32_t mine);

#endif
