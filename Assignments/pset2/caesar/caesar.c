#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

string plain,cipher;
int main(int argc, string argv[])
{
int i,k;
char c;
if (argc!=2)
{
  printf("Usage: ./caesar k\n");
  return 1;
}
int k1 = atoi(argv[1]);
printf("plaintext:  ");
plain = get_string();
printf("ciphertext: ");
k1=k1%26;
for(i=0;i<strlen(plain);i++)
{
    k=k1;
if(isalpha(plain[i]))
{
    if(isupper(plain[i]))
    {
        int l=(int)('Z'-plain[i]);
       if(l < k)
        {
         k=k-(int)('Z'-plain[i]);
         c='@'+k;
         printf("%c",c);
        }
        else
        {
            c=plain[i]+k;
            printf("%c",c);
        }
        
    }
    else
    {
       int l=(int)('z'-plain[i]);
       if(l < k)
        {
         k=k-(int)('z'-plain[i]);
         c='`'+k;
         printf("%c",c);
        }
        else
        {
            c=plain[i]+k;
            printf("%c",c);
        }
    }
    
}
else
printf("%c",plain[i]);
}
printf("\n");
}