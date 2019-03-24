///Simple Function Pointer
//#include<iostream>
//#include<vector>
//using namespace std;
//
//void printvalue(int value)
//{
//    std::cout << " Value : " << value << std::endl;
//}
//void print(const std::vector<int>& values,void(*display)(int))
//{
//    for(int value : values)
//        display(value);
//}
//main()
//{
//      vector<int> values {1,2,5,4,3};
//      print(values,printvalue);
////    auto display = print;
////    void(*display)(const std::vector<int>&) = print;
////    display function = print;
////    function();
////    display(values);
////    print(values);
//}
///Function Pointer Without Name(lambda)
//#include<iostream>
//#include<vector>
//using namespace std;
//void print(const std::vector<int>& values,void(*display)(int))
//{
//    for(int value : values)
//        display(value);
//}
//main()
//{
//      vector<int> values {1,2,5,4,3};
//      ///Example of lambda
//      print(values,[](int value){std::cout << "Value: " <<value <<std::endl;});
//}
///Function Pointer using Functional Library
//check out predefine_osp.h 228-232
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
void print(const std::vector<int>& values,const std::function<void(int)>& display)
{
    for(int value : values)
        display(value);
}
main()
{
std::vector<int> values {1,2,5,4,3};

auto it=std::find_if(values.begin(),values.end(),[](int value){ return value>4;});//used find if to iterate through all the values for finding value is -gt 4
std::cout<<"greater than 4 : "<<*it<<std::endl;
auto lambda1 = [=](int value){std::cout << "Value: " <<value <<std::endl;};
print(values,lambda1);
///Example of lambda
int a=9;
auto lambda2 = [=](int value)mutable{a=7;std::cout << "Value: " <<a <<std::endl;};//used mutable to change the value of a
//note::a is out side of function so thats why pass = to copy all values in function constantly
//could have written &a or a in the capture[] to pass the outside variable
//for more about lambdas and capture<[]> refer to reference cpp reference website
print(values,lambda2);
}
