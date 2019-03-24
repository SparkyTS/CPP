//One of the Efficient method to find Prime Numbers
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
main()
{
    int n,count=0;
    cout<<"Enter Range to find prime Numbers : ";
    cin>>n;
    int iteration=sqrt(n);//storing to save processing(function calling) time while iteration
    vector <int> prime(n-1);

    for(int i=0;i<prime.size();i++)
        prime[i]=i+2;

    for(int i=0;i<iteration;i++)//for(i=0;i<prime.size();i++) //used sqrt(n)+1(iteration) to reduce the iterations
     for(int j=i+1;j<prime.size();j++)
        if(prime[j]%prime[i]==0)
               prime.erase(prime.begin()+j);

    for(int i=0;i<prime.size();i++)
            cout<<prime[i]<<"  ";
}
