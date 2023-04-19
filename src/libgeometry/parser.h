#pragma once
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Point {
    double x;
    double y;
} point;

float pcircle(float rad);
float acircle(float rad);
void Exception(char* string);
void parse_start();