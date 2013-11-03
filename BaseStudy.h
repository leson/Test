#ifndef BASESTUDY_H_INCLUDED
#define BASESTUDY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static char arrs[3][10]={"姓名","兴趣","性别"};

char * int2char(int inta);
void test();
void oper();
void testSprintf();
void testConvert();
void printAscii();
int fac(int n);
void CardNumber2str(char cardNum[], char str[]);
void str2CardNumber(char str[], char cardNum[]);
void testConv();
void forceConvert();
int getStrLen(char* str);
void copyStr(char* str1,char* str2);
void swapStr(char* s1,char* s2);
void testArr();


#endif // BASESTUDY_H_INCLUDED
