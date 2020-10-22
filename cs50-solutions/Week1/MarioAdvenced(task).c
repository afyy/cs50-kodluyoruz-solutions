#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int num;
    do
    {
        num=get_int("Height:");
    }while(num<1 || num>8);
    for(int i=0; i<num; i++)
    {
        for(int j=num-1; j>=0; j--)
        {
            if(j<=i)
                printf("#");
            else
                printf(" ");
        }
        printf("  ");
        for(int k=0; k<=i;k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
