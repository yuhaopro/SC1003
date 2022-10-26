// Write the function strncpy() that copies not more than n characters (characters that follow a
// null character are not copied) from the array pointed to by s2 to the array pointed to by s1.  
// If the array pointed to by s2 is a string shorter than n characters, null characters are
// appended to the copy in the array pointed to by s1, until n characters in all have been
// written.  The strncpy returns the value of s1.

#include <stdio.h>
#define SIZE 20

char *strncpy(char * s1, char * s2, int n);

int main()
{
    int n;
    char s1[SIZE], s2[SIZE];
    printf("Enter a String: \n");
    fgets(s2, SIZE, stdin);  
    printf("Enter number of characters: \n");
    scanf("%d", &n);
    printf("String: %s", strocpy(s1, s2, n));

}

char *strncpy(char * s1, char * s2, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (s2[i] == '\n')
        {
            s1[i] = '\0';
            break;
        }
        s1[i] = s2[i];
    }
    return s1;
}
