#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
typedef struct {
   char name[20];
   int telno;
} PhoneBk;
void printPB(PhoneBk *pb, int size);
int readin(PhoneBk *pb);
void search(PhoneBk *pb, int size, char *target);

int main() {
   PhoneBk s[MAX];
   char t[20], *p;
   int size=0, choice;
   char dummychar;
     
   printf("Select one of the following options: \n");
   printf("1: readin()\n");      
   printf("2: search()\n");
   printf("3: printPB()\n");
   printf("4: exit()\n");       
   do
    {
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      switch (choice)
        {
         case 1:     
            scanf("%c", &dummychar);        
            size = readin(s);  
            break;
         case 2:  
            scanf("%c", &dummychar);   
            printf("Enter search name: \n");
            fgets(t, 20, stdin);   
            if (p=strchr(t,'\n')) *p= '\0';
            search(s,size,t);                    
            break;
         case 3:  
            printPB(s, size);
            break;          
      
        }
   
    } while (choice< 4);
   return 0; 
}
void printPB(PhoneBk *pb, int size)   
{
    int i = 0;
    
    if (size == 0)
    {
        printf("Phone book is empty!\n");
    }
    for(i = 0; i < size; i++)
    {
        printf("Name: %s\n",(pb + i)->name);
        printf("Telno: %d\n", (pb + i)->telno);
    }
    
}
int readin(PhoneBk *pb) 
{
    int i = 0, j;
    char str[20];
    
    printf("Enter Name: \n");
    scanf("%20[^\n]", str);
    
    if (str[0] == '#')
    {
        return i;
    }
    
    while(str[0] != '#')
    {
        // printf("string: %s\n", str);
        printf("Enter Telno: \n");
        scanf("%d[^\n]", &((pb+ i)->telno));
        scanf("%1*[\n]");
        strcpy((pb + i)->name, str);
        
        printf("Enter Name: \n");
        scanf("%20[^\n]", str);
        i++;
    }

    
    return i;
    
}
void search(PhoneBk *pb, int size, char *target) 
{
    int i = 0;
    char str[20], str1[20], str2[20];
    
    for (int j = 0; j < 20; j++)
    {
        str1[j] = tolower(target[j]);
    }
    
    for (i = 0; i < size; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            str2[j] = tolower((pb + i)->name[j]);
        }
        if (strcmp(str1, str2) == 0)
        {
            printf("Name = %s, Tel = %d\n",(pb + i)->name, (pb + i)->telno);
            return;
        }
        
    }
    printf("Name not Found!\n");
}
