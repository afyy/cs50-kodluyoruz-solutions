#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
bool check_valid_key(string s);
int main(int argc, string argv[])
{
    if (argc != 2 || check_valid_key(argv[1]))
    {
    	printf("Usage: %s key\n",argv[0]);
    	return 1;
    }
    int key=atoi(argv[1]);
    
	string plaintext=get_string("plaintext: ");
	
	printf("ciphertext: ");
	for (int i = 0, n = strlen(plaintext); i < n; i++)
    {           
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')  // Highlighted line
        {
            plaintext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
        }
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            plaintext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
        }
            printf("%c", plaintext[i]);
    }
    printf("\n");
    return 0;
}
bool check_valid_key(string s)
{
	for(int i=0,len=strlen(s);i<len;i++)
	  if(!isdigit(s[i]))
	  	return true;
	return false;
}

