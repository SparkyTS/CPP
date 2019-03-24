#include<iostream>
using namespace std;

int isprime(int number)
{
    for(int i=2;i<=number;i++)
        for(int j=2;j<i;j++)
            if(number%j==0)
                return 0;
    return 1;
}

main()
{
    long long number,j=0;
    cout<<"Enter A Number : ";
    cin>>number;
    cout<<"\nPrime Factors Of "<<number<<" Are : ";
    for(int i=2;i<=number;i++,j=0)
    if(isprime(i))
    while(number%i==0)
        {
         cout<<i<<" ";
         number=number/i;
        }
}
