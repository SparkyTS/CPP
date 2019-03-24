#include<stdio.h>
float x[20]/*={1891,1901,1911,1921,1931}*/;
float y[20]/*={46,66,81,93,101}*/;
float temp[20];
static int length;
show_steps()
{
    int i;
    static int count=length;
    for(i=0;i<count;i++) printf(" %0.2f ",y[i]); printf("\n"); count--;
}

get_tabular()
{ int i,j,k;
    show_steps();
    for(j=length;j>1;j--)
    {
        for(i=length-1;i>=0;i--)
            if((i+1)>=j)
                temp[i]=y[i];
            else
                temp[i]=y[i+1]-y[i];
        for(k=0;k<length;k++)
            y[k]=temp[k];
        show_steps();
    }
}

int fact(int n)
{
    int i,f=1;
    for (i=2;i<=n;i++)   f *= i;
    return f;
}

show_tabular()
{
int i,j;
printf("\n\nTabular Values Are : \n\n");

for(i=0,j=length-1;i<length/2;i++,j--)    y[i]=y[j]+y[i]-(y[j]=y[i]);

for(i=0;i<length;i++)
  printf(" %0.2f ",y[i]);
}

main()
{
    float h,p,f,sum,a;int i;

    printf("What is the length of table : ");     scanf("%d",&length);

    printf("\nEnter the values of x : ");         for(i=0;i<length;i++) scanf("%f",&x[i]);

    printf("\nEnter the values of y(x) : ");      for(i=0;i<length;i++) scanf("%f",&y[i]);

    printf("\nEnter the value of Xn to find : "); scanf("%f",&f);

    get_tabular();    show_tabular();

    sum=y[0];       h=x[1]-x[0];        p=(f-x[length-1])/h;

   for(i=1,a=p;i<length;i++)
    {
        sum+=(a*y[i])/fact(i);
        a=a*(p+i);
    }
    printf("\n\n y(%0.f) = %0.2f\n",f,sum);
    printf("\n\n---------------------------------------------------------------------   -    ______________________________________  |\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n ");
}
