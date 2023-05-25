#include <stdio.h>   
#include <stdlib.h>  
#include <string.h>  
#define SIZE 30
void toLowerCase(char plain[], int ps)
{
    int i;
    for (i = 0; i < ps; i++) {
        if (plain[i] > 64 && plain[i] < 91)
            plain[i] += 32;
    }
}

int removeSpaces(char* plain, int ps)
{
    int i, count = 0;
    for (i = 0; i < ps; i++)
        if (plain[i] != ' ')
            plain[count++] = plain[i];
    plain[count] = '\0';
    return count;
}
void Table(char key[], int ks, char m[5][5])
{
    int i, j, k, flag = 0, *dicty;
    dicty = (int*)calloc(26, sizeof(int));
    for (i = 0; i < ks; i++) {
        if (key[i] != 'j')
            dicty[key[i] - 97] = 2;
    }
    dicty['j' - 97] = 1;
    i = 0;
    j = 0;
    for (k = 0; k < ks; k++) 
    {
        if (dicty[key[k] - 97] == 2) 
            {
            	dicty[key[k] - 97] -= 1;
            	m[i][j] = key[k];
            	j++;
            	if (j == 5) 
                {
                	i++;
               	 j = 0;
            	}
        	}
    }
    for (k = 0; k < 26; k++) {
        if (dicty[k] == 0) {
            m[i][j] = (char)(k + 97);
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }
}
void search(char m[5][5], char a, char b, int arr[])
{
    int i, j;

    if (a == 'j')
        a = 'i';
    else if (b == 'j')
        b = 'i';
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (m[i][j] == a) {
                arr[0] = i;
                arr[1] = j;
            }
            else if (m[i][j] == b) {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}
int mod5(int a) { return (a % 5); }
int prepare(char str[], int ptrs)
{
    if (ptrs % 2 != 0) {
        str[ptrs++] = 'z';
        str[ptrs] = '\0';
    }
    return ptrs;
}
void encrypt(char str[], char m[5][5], int ps)
{
    int i, a[4];
    for (i = 0; i < ps; i += 2) {
        search(m, str[i], str[i + 1], a);
        if (a[0] == a[2]) {
            str[i] = m[a[0]][mod5(a[1] + 1)];
            str[i + 1] = m[a[0]][mod5(a[3] + 1)];
        }
        else if (a[1] == a[3]) {
            str[i] = m[mod5(a[0] + 1)][a[1]];
            str[i + 1] = m[mod5(a[2] + 1)][a[1]];
        }
        else {
            str[i] = m[a[0]][a[3]];
            str[i + 1] = m[a[2]][a[1]];
        }
    }
}
void encryptBypf(char str[], char key[])
{
    char ps, ks, m[5][5];
    ks = strlen(key);
    ks = removeSpaces(key, ks);
    toLowerCase(key, ks);
    ps = strlen(str);
    toLowerCase(str, ps);
    ps = removeSpaces(str, ps);
    ps = prepare(str, ps);
    Table(key, ks, m);
    encrypt(str, m, ps);
}
int main()
{
	char str[SIZE], key[SIZE];
	printf("Enter a keyword: \n");
	fgets(key,sizeof(key),stdin);
	//scanf("%s",key);
	printf("Enter a Plaintext to be encrypted: \n");
	fgets(str,sizeof(str),stdin);
	//scanf("%s",str);
	encryptBypf(str,key);
	printf("Ciphered Text:%s",str);
	return 0;
}
