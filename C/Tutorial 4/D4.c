// Write a C function that compares the string pointed to by s1 to the string pointed to by s2. If
// the string pointed to by s1 is greater than, equal to, or less than the string pointed to by s2,
// then it returns 1, 0 or –1 respectively. Write the code for the function without using the
// standard C string library function strcmp(). The function prototype is given as follows:  


#include <stdio.h>
#define SIZE 20

int stringcmp(char *s1, char *s2);

int main()
{
    char s1[SIZE], s2[SIZE];
    printf("Enter a source String: \n");
    fgets(s1, SIZE, stdin);  
    printf("Enter a target String: \n");
    fgets(s2, SIZE, stdin); 
    printf("String: %d", stringcmp(s1, s2));

}

int stringcmp(char *s1, char *s2)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (s1[i] == '\n' && s2[i] != '\n')
        {
            return -1;
        }
        else if (s1[i] != '\n' && s2[i] == '\n')
        {
            return 1;
        }
        else if (s1[i] == '\n' && s2[i] == '\n')
        {
            return 0;
        }


        if (s1[i] != s2[i])
        {
            if (s1[i] > s2[i])
            {
                return 1;
            }
            else if (s1[i] < s2[i])
            {
                return -1;
            }
        }
    }
    return 0;
    
}