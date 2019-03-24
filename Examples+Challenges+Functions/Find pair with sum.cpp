#include<iostream>
#include<vector>
using namespace std;
int find(const std::vector<int>&com,const int value)
{
    for(int x : com)
    {
        if(x==value)
            return x;
    }
    return 0;
}
main()
{
    std::vector<int> data {1,2,6,5,4,7},comp;

    int sum;
    std::cout<<"Enter sum you want to find : "; std::cin>>sum;

    for(int value : data){
        if(value==find(comp,value)){
            std::cout<<"Found : "<<value<<" + "<<sum-value<<" = "<<sum<<endl;
            }
        comp.push_back(sum-value);
    }
}
