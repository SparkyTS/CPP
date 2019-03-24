#include<iostream>
#include<iomanip>
using namespace std;

/*Automorphic Number : A last digits of the square of the number is number it self.
for example : number=5  square=25
            number=6  square=36
input:Enter a limit till you want to find automorphic number.
*/

main()
{
    long long number,square,limit,j;
    cin>>limit;
    for(j=0;j<=limit;j++)
    {
    number=j;
    square=number*number;
    for(int i=0;number!=0;i++)
    {
     if(number%10!=square%10)
            break;
        number=number/10;
        square/=10;
    }
    if(number==0)
        cout<<"\nNumber : "<<setw(5)<<j<<setw(15)<<"  Square : "<<j*j;
    }
}
