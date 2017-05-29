#include <stdio.h>
#include <cs50.h>

int main(void)
{
int Height,i,h,j;
    do
    {
    printf("Height: ");
    Height = get_int();
    h=Height;
    }while(Height<0 || Height > 23);
    
    for(i=0;i<Height;i++)
    {
         for(j=0;j<h-1;j++)
            printf(" ");
        for(j=0;j<i+2;j++)
            printf("#");
        printf("\n");
        h--;
    }
}