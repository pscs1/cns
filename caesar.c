#include<stdio.h>
int main()
{
	char a[50], b, c[50];
	int i, key;
	printf("Enter a message to encrypt\n");
	fgets(a, 50, stdin);
	printf("Enter a key\n");
	scanf("%d",&key);
	
	for(i=0;a[i]!='\0';i++)
	{
		b=a[i];
	
		if(b>='a' && b<='z')
		{
			b=(b-'a'+key)%26+'a';
		}
		else if(b>='A' && b<='Z')
		{
			b=(b-'A'+key)%26+'A';
		}
		if(b>='0' && b<='9')
		{
			b=(b-'0'+key)%10+'0';
		}
		a[i]=b;
	}
	printf("Encrypted message: %s\n", a);
	printf("Enter a message to decrypt\n");
	getchar();
	fgets(c, 20, stdin);
	for(i=0;c[i]!='\0';i++)
	{
		b=c[i];
		if(b>='a' && b<='z')
		{
			b=(b-'a'-key)%26+'a';
		}
		else if(b>='A' && b<='Z')
		{
			b=(b-'A'-key)%26+'A';
		}
		if(b>='0' && b<='9')
		{
			b=(b-'0'-key)%10+'0';
		}
		c[i]=b;
	}
	printf("Decrypted message: %s\n", c);
	return 0;
}
