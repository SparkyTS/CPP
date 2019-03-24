#include<iostream>
using namespace std;
float x[5];
float y[5];
float temp[5];
static int length=5;

get_tabular()
{
    for(int j=length;j>1;j--)
    {
        for(int i=length-1;i>=0;i--)
            if((i+1)>=j)
                temp[i]=y[i];
            else
                temp[i]=y[i+1]-y[i];
        for(int k=0;k<length;k++)
            y[k]=temp[k];
    }
}

int fact(int n)
{
    int i,f=1;
    for (i=2;i<=n;i++)   f *= i;
    return f;
}

main()
{
    float p,f=length+1,sum,a;int i;

    for(i=0;i<length;i++) x[i]=i+1;

    cout<<"Enter 5 values : ";  for(i=0;i<length;i++) scanf("%f",&y[i]);

    get_tabular();

    sum=y[0]; p=(f-x[length-1]);

   for(i=1,a=p;i<length;i++)
    {
        sum+=(a*y[i])/fact(i);
        a=a*(p+i);
    }
    printf("\n\nNext number would be %0.4f\n",sum);
}
