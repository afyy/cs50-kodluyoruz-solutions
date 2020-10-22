#include<stdio.h>
#include<math.h>
#include<cs50.h>

int main()
{
    int counter=0;
    int quarter=25,dime=10,nickel=5,penny=1;
    float dollars;
    do
    {
        dollars=get_float("Change owed:");
    }while(dollars<0);
    int cents = round(dollars * 100);
    
    do
    {
        if(cents>=quarter)
        {
            counter += (cents/quarter);
            cents = (cents%quarter);
        }
        if(cents>=dime)
        {
            counter += (cents/dime);
            cents = (cents%dime); 
        }
        if(cents>=nickel)
        {
            counter += (cents/nickel);
            cents = (cents%nickel); 
        }
        if(cents>=penny)
        {
            counter += (cents/penny);
            cents = (cents%penny); 
        }
    }while(cents!=0);
    printf("%i\n",counter);
}
