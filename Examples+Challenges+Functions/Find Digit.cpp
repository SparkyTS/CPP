#include<iostream>
#include<string>
using namespace std;
main()
{
    int range,digit,d=10;
    cin>>range>>digit;
    for(int i=0,number=0;i<=range;i++,number=i)
    {
        if(i==digit)    cout<<i<<" ";
        else
        while(number!=0)
        {
            if(number>=d*10)  d=d*10;
            if(number%d==digit || number%(d/10)==digit) {cout<<i<<"  ";break;}
            number/=10;
        }
    }
}
