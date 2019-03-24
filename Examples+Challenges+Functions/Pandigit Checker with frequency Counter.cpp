#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
//Number is Pan-digital if it have all the digit from 0-9 at least once.
main()
{
char number[50],test[10];test[0]='1';
int flag=0,j,count[10];count[0]=0;

cout<<"Enter a Number : ";
gets(number);

for(int i=1;i<10;i++) test[i]='0',count[i]=0;

//Setting values to test and count.
for(int i=0;i<strlen(number);i++)
    {
    test[number[i]-48]=number[i];
    ++count[number[i]-48];
    }
//checking values
for(int j=0;j<10;j++)
    if(test[j]!=j+48)
    {cout<<"\nNot PAN-DIGITAL\n";flag=1;break;}

if(flag==0)
    cout<<"\nNumber is PAN-DIGITAL\n";

//Print No of time digit repeated
for(int j=0;j<10;j++)
  cout<<"\n"<<j<<" is "<<count[j]<<" times";
}
