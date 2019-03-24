#include <iostream>
#include<math.h>

using namespace std;

int match_found = 0;
sum_finder(char* op,int* arr)
{
 int new_arr[10];
 int temp=arr[0];
 int i=0,j=0,sum=0;
 char last_sign = '+';

 while(i<8)
 {
     if(op[i]==' ')
     {
         temp*=10;
         temp+=arr[i+1];
         if(i==7){
            new_arr[j++]=(last_sign=='+')?temp:0-temp;
            new_arr[j]='\0';
         }
     }
     else{
        new_arr[j++]=(last_sign=='+')?temp:0-temp;
        temp=new_arr[j]=arr[i+1];
        last_sign=op[i];
     }
     i++;
 }

 if(last_sign=='-')   new_arr[j]=-new_arr[j];

 new_arr[++j]='\0';

for(int i=0;new_arr[i]!='\0';i++) sum+=new_arr[i];

    if(sum==100){
        for(int i=0;new_arr[i]!='\0';i++){
            if(new_arr[i]>0 && i!=0) cout<<"+";
            cout<<new_arr[i];
     }
     cout<<" = "<<sum<<"\n";match_found++;
   }
}


find_per(int n,char* op,int* arr)
{
    if(n<1){
	sum_finder(op,arr);
    }

    else
    {
	op[n-1]='+';
	find_per(n-1,op,arr);
	op[n-1]=' ';
	find_per(n-1,op,arr);
	op[n-1]='-';
	find_per(n-1,op,arr);
    }
}

print_array(int* a,int i=0){
while(a[i]!='\0')
    cout << a[i++]<<" ";cout<<"\n\n";
}

main()
{
    char op[9]; op[8]='\0';
    int arr1[]={1,2,3,4,5,6,7,8,9,'\0'};
    cout<<"For : ";print_array(arr1);
    find_per(8,op,arr1);
    cout<<"Total "<<match_found<<" match found.\n\n";

    match_found=0;
    int arr2[]={9,8,7,6,5,4,3,2,1,'\0'};
    cout<<"For : ";print_array(arr2);
    find_per(8,op,arr2);
    cout<<"Total "<<match_found<<" match found.\n\n";
}
