#include <stdio.h>
#include <cs50.h>

int main(void)
{
int Minutes,Bottles;
    printf("Minutes: ");
    Minutes = get_int();
    if(Minutes>0)
    {
    Bottles = Minutes*12; 
    printf("Bottles: %d",Bottles);
    }
    else
    {
    printf("Enter positive integer");
    }
}