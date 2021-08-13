#include "stack.h"

void initialize(DoubleStack * s){
   s->top = -1;
}

bool isEmpty(const DoubleStack * s){
   if (s->top == -1){
      return true;
   }
   else return false;
} 

bool isFull(const DoubleStack* s){
   if (s->top == (MAX_STACK_SIZE - 1)){
      return true;
   }
   else return false;
}

bool push (DoubleStack * stack, double value){
   if (isFull(stack)){
      return false;
   }
   (stack->top)++;
   stack->stackArray[stack->top] = value; 
   return true; 
}
   
   // Returns false if push fails due to a full stack
double pop (DoubleStack * stack){
   if (isEmpty(stack)){
      return 0;
   }
   double temp = stack->stackArray[stack->top]; 
   stack->stackArray[stack->top] = stack->stackArray[(stack->top - 1)];
   (stack->top)--; 
   return temp;
}
   
double top (const DoubleStack * stack){
   if (isEmpty(stack)){
      return 0;
   }
   return (stack->stackArray[stack->top]);
}
