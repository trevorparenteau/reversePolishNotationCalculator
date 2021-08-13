
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef STACK
#define STACK

#define MAX_STACK_SIZE 50 

typedef struct {
   int top; 
   double stackArray[MAX_STACK_SIZE];
} DoubleStack; 

void initialize(DoubleStack * s);
bool isEmpty(const DoubleStack * s);
bool isFull(const DoubleStack * s);
bool push (DoubleStack * stack, double value); // Returns false if push fails due to a full stack
double pop (DoubleStack * stack);
double top (const DoubleStack * stack);

#endif 
