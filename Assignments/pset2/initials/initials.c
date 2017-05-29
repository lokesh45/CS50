#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

string name;
int main(void)
{
int i;
name = get_string();
printf("%c",toupper(name[0]));
for(i=0;i<strlen(name);i++)
if(name[i]==' ')
    printf("%c",toupper(name[i+1]));
printf("\n");
}