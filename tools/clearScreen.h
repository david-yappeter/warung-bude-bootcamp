#ifndef CLEAR_SCREEN_TOOLS_PARAM
#define CLEAR_SCREEN_TOOLS_PARAM 1
#include<stdlib.h>
#include<stdio.h>

void Clrscr(){
    system("cls||clear");
}

void NotValid(){
    printf("\nInput Not Valid!!!\nPress Enter To Continue ...\n");
    getchar();
}

void Valid(){
    printf("\nPress Enter To Continue ...\n");
    getchar();
}

#endif
