   int k = 0;
    char *token = strtok(str1, " ");
    while( token != NULL ) 
    {
        str2[k] = token[0];
        token = strtok(NULL, " ");
        k++;
    }
    str2[k] = '\0';
