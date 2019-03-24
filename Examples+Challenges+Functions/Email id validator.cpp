#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

main()
{
char a[50];
int flagdot=0,flagat=0,flag=0;
cout<<"Enter A String : ";
gets(a);
for(int i=0;i<strlen(a);i++)
{
    if(a[i]=='@')  flagat++,flag=1;
    if(a[i]=='.' && flag==1) flagdot++;

}
    if(flagdot==1 || flagdot==2 && flagat==1 )
        cout<<"Valid.";
    else
        cout<<"Not Valid";
}
