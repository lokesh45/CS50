#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
int c,change;
float chan;
printf("O hai! ");
c=0;
    do
    {
    printf("How much change is owed?\n");
    chan = get_float();
    }while(chan < 0.0);
    
    change=(int)round(chan*100);
    
    while(change != 0)
    {
        if(change>=25)
        {
            change=change-25;
            c++;
        }
        else if(change>=10)
        {
          
            change=change-10;
            c++;
        }
        else if(change>=5)
        {
            
            change=change-5;
            c++;
        }
        else if(change>=1)
        {
            change=change-1;
            c++;
        }
        else
        {
        change=0;
        }
    }
    printf("%d\n",c);
}




