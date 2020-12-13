/*
 * File:   utilis.c
 * Author: FabioSouza
 * Numero:2018015299
 * Created on 13 de junho de 2020, 15:54
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

void initRandom()
{
    srand(time(NULL));
}

int intUniformRnd(int a, int b)
{
    return a + rand()%(b-a+1);
}

int probEvento(float prob)
{
    return prob > ((float)rand()/RAND_MAX);
}
