#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
int hesapla1(string card_number);
int hesapla2(string card_number);
int main()
{
	bool isValid;
	bool isTrue=false;
	int toplam3=0,counter;
	string card_number="";
	while(isTrue!=true)
	{
		card_number=get_string("Number:");
		counter=strlen(card_number);
		for(int i=0;i<counter;i++)
		{
			if(!isdigit(card_number[i]))
			{
				isTrue=false;
				break;
			}
			else
				isTrue=true;
		}
	}
	toplam3=hesapla1(card_number)+hesapla2(card_number);
	string card="";
	if((toplam3%10)==0)
	{
		if((counter==13 || counter==16) && card_number[0]=='4')
			card="VISA";
		else if(counter==15 && (card_number[0]=='3' && (card_number[1]=='4' || card_number[1]=='7')))
			card="AMEX";
		else if(counter==16 && (card_number[0]=='5' && (card_number[1]=='1' || card_number[1]=='2' || card_number[1]=='3' || card_number[1]=='4' || card_number[1]=='5')))
			card="MASTERCARD";
		else
			card="INVALID";
	}
	else
		card="INVALID";
	printf("%s\n",card);
}

int hesapla1(string card_number)
{
	int toplam1=0;
	int counter=strlen(card_number);
	for(int i=counter-1;i>=0;i=i-2)
	{
		toplam1=toplam1+((int)card_number[i]-48);
	}
	return toplam1;
}
int hesapla2(string card_number)
{
	int toplam2=0;
	int counter=strlen(card_number);
	for(int i=counter-2;i>=0;i=i-2)
	{
		if((2*((int)card_number[i]-48))>=10)
			toplam2=toplam2+((2*((int)card_number[i]-48))-9);
		else
			toplam2=toplam2+(2*((int)card_number[i]-48));
	}
	return toplam2;
}

