#include<iostream>
#include<vector>

using namespace std;

int predict(vector<int>& series)
{
    vector<int> x;

    for(int i=0;i<series.size()-1;i++)
        x.push_back(series[i+1]-series[i]);

    int f = x[1]/x[0];
    int a = x[1]%x[0];
    int diff = x.back() * f + a;

    if(a!=0)
        diff=predict(x);

    return (series.back()+diff);
}
main()
{
vector <int>data(5);
cout<<"Enter first 5 numbers : ";
cin>>data[0]>>data[1]>>data[2]>>data[3]>>data[4];
cout<<"Next no would be : "<<predict(data);
}
