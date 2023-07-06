#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int i, j, len,rails,count,code[100][1000];
    char str[1000];
    printf("Enter a Secret Message\n");
    fgets(str, sizeof(str), stdin);
    len=strlen(str);
    printf("Enter number of rails\n");
    scanf("%d",&rails);
    for(i=0;i<rails;i++)
    {
        for(j=0;j<len;j++)
        {
            code[i][j]=0;
        }
    }
    count=0;
    int r=0;
    j = 0;
    while (r < len)
    {
        if (j < rails)
        {
            code[j][r] = str[r];
            j++;
            r++;
        }
        else
        {
            j = rails - 2;
            while (j > 0 && r < len)
            {
                code[j][r] = str[r];
                j--;
                r++;
            }
        }
    }
    printf("\nEncrypted Message:\n");
    for(i=0;i<rails;i++)
    { 
        for(j=0;j<len;j++)
        {
            if(code[i][j]!=0)
            printf("%c",code[i][j]);
        }
    }
    char decryptedStr[len + 1];
    int k = 0;
    for (j = 0; j < len; j++)
    {
        for (i = 0; i < rails; i++)
        {
            if (code[i][j] != 0)
            {
                decryptedStr[k++] = (char)code[i][j];
            }
        }
    }
    decryptedStr[k] = '\0';
    printf("\nDecrypted Message: \n%s\n", decryptedStr);
}
