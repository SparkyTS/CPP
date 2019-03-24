#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

main()
{
char str[50];
cout<<"Enter a string : ";
gets(str);
int count1=0,count2=0,count3=0;
for(int i=0;i<strlen(str);i++)
{
    if(str[i]=='\\') i++;
    else if(str[i]=='(') count1++;
    else if(str[i]==')') count1--;
    else if(str[i]=='[') count2++;
    else if(str[i]==']') count2--;
    else if(str[i]=='{') count3++;
    else if(str[i]=='}') count3--;
    if(count1<0 || count2<0 || count3<0) break;
}

count1==0 && count2==0 && count3==0 ? cout<<"true" : cout<<"false";
}
