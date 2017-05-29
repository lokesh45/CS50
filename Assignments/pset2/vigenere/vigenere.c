#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

string plain,cipher;
int main(int argc, string argv[])
{
int i,k,k1,j;
char c;
if (argc!=2)
{
  printf("Usage: ./caesar k\n");
  return 1;
}
char *arg1 = argv[1];
char *arg2=argv[1];
int len=strlen(arg1);
for(i=0;i<len;i++)
    if(!isalpha(arg1[i]))
    {
        printf("Usage: ./vigenere k");
        return 1;
    }
printf("plaintext:  ");
plain = get_string();
printf("ciphertext: ");
j=0;
int flag=0;
for(i=0;i<strlen(plain);i++)
{
if(isalpha(plain[i]))
{
    if(j < len && flag==0)
    {
    if(isupper(arg1[j]))
    {
        arg2[j]=arg1[j]-'A';
    }
    else if(islower(arg1[j]))
    {
         arg2[j]=arg1[j]-'a';
    }
    else
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    }
    if(j==len)
        { j=0; flag=1;}
    k1 = (int)arg2[j];
    j++;
    k=k1%26;
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