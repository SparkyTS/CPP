#include<iostream>
using namespace std;
count_digit(int number)
{
    int count=0;
    while(number!=0)
    {
        number=number/10;
        count++;
    }
    return count;
}
asc_dsc(int number,int count,int &small ,int &big)
{
    int a[count],limit=count;
    small=0;big=0;
    while(count)
    {
        a[--count]=number%10;
        number/=10;
    }

    for(int i=0;i<limit-1;i++)
        for(int j=i+1;j<limit;j++)
            if(a[i]>a[j])
            a[i]=a[i]+a[j]-(a[j]=a[i]);

    for(int i=1,j=0,k=limit-1;j<limit;i*=10,j++,k--)
        big+=a[j]*i,small+=a[k]*i;
}

main()
{
    int number,small,big,iteration=1;
    cin>>number;
    int count=count_digit(number);

    if(count>4){cout<<"Not a Valid Input";return 0;}

    asc_dsc(number,count,small,big);
    number=big-small;
    cout<<big<<" - "<<small<<" = "<<number<<endl;
    while(number!=6174 && number!=0)
    {
        count=count_digit(number);
        asc_dsc(number,count,small,big);
        number=big-small;
        cout<<big<<" - "<<small<<" = "<<number<<endl;
        iteration++;
    }
    if(number == 0)
        cout<<"Not a valid Input ";
    else
        cout<<"Getting 6174 after "<<iteration<<" Iterations";
}
