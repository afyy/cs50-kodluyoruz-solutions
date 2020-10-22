#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        printf("Hata");
        return 1;
    }
    char *card=argv[1];
    FILE *file=fopen(card,"r");
    if(card==NULL)
    {
        fprintf(stderr,"Could not open %s",card);
        return 2;
    }

    BYTE bytes[4]={0x00,0x00,0x00,0x00};
    while(bytes[0]!=0xff || bytes[1]!=0xd8 || bytes[2]!=0xff || (bytes[3]!=0xe0 && bytes[3]!=0xe1 && bytes[3]!=0xe2 && bytes[3]!=0xe3 &&
    bytes[3]!=0xe4 && bytes[3]!=0xe5 && bytes[3]!=0xe6 && bytes[3]!=0xe7 && bytes[3]!=0xe8 && bytes[3]!=0xe9 && bytes[3]!=0xea &&
    bytes[3]!=0xeb && bytes[3]!=0xec && bytes[3]!=0xed && bytes[3]!=0xee && bytes[3]!=0xef))
    {
        fread(bytes,sizeof(BYTE),4,file);
    }
    fseek(file,-4,SEEK_CUR);
    char buffer[50];
    int num=0;
    char array[512];
    while(num<50)
    {
        sprintf(buffer,"%.3i.jpg",num);
        num++;
        FILE *jpeg=fopen(buffer,"w");
        if(card==NULL)
        {
           fprintf(stderr,"Could not open %s",buffer);
           return 3;
        }
        if(num==50)
        {
            while(1){
            fread(array,sizeof(BYTE),1,file);
            if(!feof(file))
                fwrite(array,sizeof(BYTE),1,jpeg);
            else
                break;
            }
        }
        else
        {
            fread(array,sizeof(BYTE),512,file);
            fwrite(array,sizeof(BYTE),512,jpeg);
            fread(bytes,sizeof(BYTE),4,file);
            fseek(file,-4,SEEK_CUR);
            while(bytes[0]!=0xff || bytes[1]!=0xd8 || bytes[2]!=0xff || (bytes[3]!=0xe0 && bytes[3]!=0xe1 && bytes[3]!=0xe2 && bytes[3]!=0xe3 &&
            bytes[3]!=0xe4 && bytes[3]!=0xe5 && bytes[3]!=0xe6 && bytes[3]!=0xe7 && bytes[3]!=0xe8 && bytes[3]!=0xe9 && bytes[3]!=0xea &&
            bytes[3]!=0xeb && bytes[3]!=0xec && bytes[3]!=0xed && bytes[3]!=0xee && bytes[3]!=0xef))
            {
                fread(array,sizeof(BYTE),512,file);
                fwrite(array,sizeof(BYTE),512,jpeg);
                fread(bytes,sizeof(BYTE),4,file);
                fseek(file,-4,SEEK_CUR);
            }
        }
        fclose(jpeg);
    }
    fclose(file);
    return 0;
}
