#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int find_substr(char *a,char *b)
{
int j;
char x;
char /**a="TANAY SHAH",*b="SHAH",*/c[20];
for(int i=0;i<strlen(a);i++)
{
    if(b[0]==a[i])
    {
        for(j=0;j<strlen(b);j++)
            c[j]=a[i+j];

            c[j]='\0';

        if(!strcmp(c,b)){
            cout<<"String Found : ";
            puts(c);
            }
    }
    else if(i==strlen(a)-1)
        {
            cout<<"Not Found";
            return 0;}
}
}
main()
{
char a[50],b[10];
cout<<"Enter A String : ";
gets(a);
cout<<"Enter A substring to find : ";
gets(b);
find_substr(a,b);
}
