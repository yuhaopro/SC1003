// The following unknown function receives a string argument and a character argument,
// modifies the string argument and returns an integer value. Describe the purpose of the
// function. Give an example to support your answer.

#include <stdio.h>
int unknown(char str[ ], char c);
int main()
{
    int value = 0;
    char str[5] = "abeed";
    value = unknown(str,'e');
    printf("%d", value);
}

int unknown(char str[ ], char c)
{
    int x, y=0, z=0;
    for (x=0; str[x] != '\0'; x++)//increase x until it reaches string terminator
    {    
        if (str[x] != c)//checks if str at index x is not equals to c
        {
            str[y++] = str[x];//if it is not, let str at index y+1 = str at index x
        } 
        else
        {
            z++;// if c is found, z + 1
        }
        printf("x-str[%d]: %c\n",x,str[x]);
        printf("y-str[%d]: %c\n",y,str[y]);
        printf("string: %s\n", str);
    }
    printf("z: %d\n",z);
    str[y] = '\0';//once string reaches terminator, assign str at index y to terminator
    printf("string: %s\n", str);
    return z; 
}

/*
    The unknwon function loops through the string.
    It finds if the char at index x matches the string.
    If it does, it will increment its counter z
    Once the loop finishes, the string will then no longer have any character that is equals to c.
*/