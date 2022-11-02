int k = 0;

for (int i = 0; i < 5; i++)
{
    for (int j = 0; j < 3; j++)
    {
        if (str1[i] == str2[j])
        {
            str3[k] = str1[i];
            k++;
        }
    }
}
str3[k] = '\0';
