#include<stdio.h>
#include<string.h>

int main()
{
	char msg[50];
	char key[20];
	printf("Enter a message:\n");
	scanf("%s",msg);
	printf("Enter a key:\n");
	scanf("%s",key);
	int msglen = strlen(msg), keylen = strlen(key), i, j;
	char newkey[msglen], encryptedmsg[msglen], decryptedmsg[msglen];
	for(i=0, j=0;i<msglen;i++, j++)
	{
		if(j == keylen)
			j=0;
		newkey[i] = key[j];
	}
	
	newkey[i] = '\0';
	
	for(i=0; i < msglen; i++)
	{
		encryptedmsg[i] = ((msg[i] + newkey[i])%26)+'A';
	}
	encryptedmsg[i] = '\0';
	
	for(i=0; i < msglen; i++)
	{
		decryptedmsg[i] = (((encryptedmsg[i] - newkey[i])+26)%26)+'A';
	}
	decryptedmsg[i] = '\0';
	
	printf("Original Message: %s\n", msg);
	printf("Key: %s\n", key);
	printf("Generated key: %s\n", newkey);
	printf("Encrypted Message: %s\n", encryptedmsg);
	printf("Decrypted Message: %s\n", decryptedmsg);
	
	char table[27][27];
	table[0][0] = ' ';
	for(i = 1; i < 27; i++)
	{
		table[0][i] = 'A' + (i - 1);
		table[i][0] = 'A' + (i - 1);
	}
	for(i = 1; i < 27; i++)
	{
		for(j = 1; j < 27; j++)
		{
			table[i][j] = ((i + j - 2) % 26) + 'A';
		}
	}
	printf("\nVigenere Table:\n");
	for(i = 0; i < 27; i++)
	{
		for(j = 0; j < 27; j++)
		{
			printf("%c  ", table[i][j]);
		}
		printf("\n");
	}
}
