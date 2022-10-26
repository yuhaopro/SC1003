#include <stdio.h>
#include <string.h>
char *sweepSpace1(char *str);
char *sweepSpace2(char *str);
int main()
{
   char str[80],str2[80], *p;

   printf("Enter the string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n'))
   {
       *p = '\0';
   }
   strcpy(str2,str);
   printf("sweepSpace1(): %s\n", sweepSpace1(str));
   printf("sweepSpace2(): %s\n", sweepSpace2(str2));
   return 0;
}
char *sweepSpace1(char *str)
{
    int i , y = 0;
   for (i = 0; str[i]!='\0'; i++)
   {
        if (str[i] != ' ')
        {
            str[y++] = str[i];
        }
   }
   str[y] = '\0';
   return str;
}
char *sweepSpace2(char *str)
{
   int i , y = 0;
   for (i = 0; *(str + i)!='\0'; i++)
   {
        if (*(str + i) != ' ')
        {
            *(str + y) = *(str + i);
            y++;
        }
   }
   str[y] = '\0';
   return str;
}
