#include <stdio.h>
int digitPos1(int num, int digit);
void digitPos2(int num, int digit, int *result);

/*
   Write the function digitPos1() that returns the position of the first appearance
   of a specified digit in a positive number. The position of the digit is counted from the
   right and starts from 1. If the required digit is not in the number, the function should
   return 0. For example, digitPos1(12315, 1) returns 2 and digitPos1(12, 3) returns 0.
*/
int main()
{
   int number, digit, result=0;
   printf("Enter the number: \n");
   scanf("%d", &number);
   printf("Enter the digit: \n");
   scanf("%d", &digit);             
   printf("digitPos1(): %d\n", digitPos1(number, digit));            
   digitPos2(number, digit, &result);           
   printf("digitPos2(): %d\n", result);    
   return 0;
}
int digitPos1(int num, int digit)  
{
   int checkdigit, counter = 0;
   do
   {
      counter++;
      checkdigit = num % 10;
      if (checkdigit == digit)
      {
         return counter;
      }
      num = num / 10;
   } while (num > 0);
   
   return 0;
}
void digitPos2(int num, int digit, int *result)  
{
    int pos=0;
    *result=0;
    do {
       pos++;
       if (num%10 == digit){
         *result = pos;
         break;
       }
       num = num/10;
    } while (num > 0);    
}