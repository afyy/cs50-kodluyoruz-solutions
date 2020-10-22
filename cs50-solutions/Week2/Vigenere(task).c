#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>
int shift(char c)
{
	if(isupper(c))
		c=c%65;
	else
		c=c%97;
	return (int)c;
}
bool is_str(string s)
{
	for(int i=0,len=strlen(s);i<len;i++)
	{
		if(!isalpha(s[i]))
			return false;
	}
    return true;
}
int main(int argc, string argv[])
{
	if(argc!=2 || !is_str(argv[1])) //HATALI GÝRÝÞ
	{
		printf("Usage: %s keyword.\n",argv[0]);
		return 1;
	}
	int key,len2=strlen(argv[1]);
	string plaintext=get_string("plaintext: ");
	printf("ciphertext: ");
	for(int i=0,len=strlen(plaintext),j=i;i<len;i++,j++)
	{
        if(isupper(plaintext[i]))
        {
            key=shift((char)argv[1][(j%len2)]);
            plaintext[i]=(plaintext[i]-'A'+key)%26 + 'A';
            printf("%c",plaintext[i]);
        }
        else if(islower(plaintext[i]))
        {
            key=shift((char)argv[1][(j%len2)]);
            plaintext[i]=(plaintext[i]-'a'+key)%26 + 'a';
            printf("%c",plaintext[i]);
        }
        else
        {
            j--;
            printf("%c",plaintext[i]);
        }
	}
    printf("\n");
}

