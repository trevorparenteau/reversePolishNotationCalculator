#include <stdio.h>
#include <ctype.h>
#include "stack.h"

int main(int argc, char* argv[]) {
   
   if (argc < 4){
      printf("Insufficient input\n");
      return 1;
   }
   
   DoubleStack userVals;
   initialize(&userVals); 
   
   double readDigit; 
   double opperand1;
   double opperand2;
   double result; 
   
   for (int i = 1; i < argc; i++){
      
      if (isdigit(argv[i][0])){
         sscanf(argv[i], "%lf", &readDigit);
         push(&userVals, readDigit);
      }
      else if (argv[i][0] == '.'){
         if (isdigit(argv[i][1])){
            sscanf(argv[i], "%lf", &readDigit);
            push(&userVals, readDigit);
         }
      }
      else if (argv[i][0] == '+'){
         if (isdigit(argv[i][1])){
            sscanf(argv[i], "%lf", &readDigit);
            push(&userVals, readDigit);
         }
         else {
         opperand2 = pop(&userVals);
         opperand1 = pop(&userVals); 
         result = opperand1 + opperand2;
         push(&userVals, result);
         }
      }
      else if (argv[i][0] == '-'){
         if (isdigit(argv[i][1])){
            sscanf(argv[i], "%lf", &readDigit);
            push(&userVals, readDigit);
         }
         else{
         opperand2 = pop(&userVals);
         opperand1 = pop(&userVals); 
         result = opperand1 - opperand2;
         push(&userVals, result);
         }
      }
      else if (argv[i][0] == '*'){
         opperand2 = pop(&userVals);
         opperand1 = pop(&userVals); 
         result = opperand1 * opperand2;
         push(&userVals, result);
      }
      else if (argv[i][0] == '/'){
         opperand2 = pop(&userVals);
         opperand1 = pop(&userVals); 
         result = opperand1 / opperand2;
         push(&userVals, result);
      }
      else break;
   }
   
   double finalResult = pop(&userVals);
   
   if (isEmpty(&userVals)){
      printf("%.4lf\n", finalResult);
   }
   else printf("Insufficient input\n"); 

   return 0;
}
