#include<iostream>
#include<array>
#include<tuple>
using namespace std;
class name
{
    string fname,lname;
public:
    setdata(string a,string b)
    {
        fname=a;
        lname=b;
    }
    showdata()
    {
        cout<<fname<<" "<<lname;
    }
    friend ostream& operator<<(ostream&,name);
};
ostream& operator<<(ostream& out,name n)
{
n.showdata();
return out;
}
main()
{
    cout<<"\n\n::::::::::::::::: In Array :::::::::::::\n\n";
    array <int,6>a={1,2,3,4,5};
    array <int,6>b={5,4,3,2,1};
    cout<<"to display element of array at nth position"<<endl;
    cout<<a.at(2);
    cout<<a[2];
    cout<<"\n\nto access first and last element"<<endl;
    cout<<a.front();
    cout<<a.back();
    cout<<"\n\nto display actual size of array"<<endl;
    cout<<a.size();
    cout<<"\n\nto swap 2 arrays of same size and same type"<<endl;
    a.swap(b);
    for(int i=0;i<a.size();i++) cout<<a.at(i)<<" ";
    for(int i=0;i<b.size();i++) cout<<b.at(i)<<" ";
    cout<<"\n\nto fill whole array with same no n :\n";
    a.fill(10);
    for(int i=0;i<a.size();i++) cout<<a.at(i)<<" ";

    cout<<"\n\n::::::::::::::::: In pair :::::::::::::\n\n";
    pair <string,int>p1;
    p1=make_pair("Tanay",18);
    cout<<p1.first<<" "<<p1.second;
    pair <string,name>p2;
    name n1;
    n1.setdata("Tanay","Shah");
    p2=make_pair(10,n1);
    //name n=p2.second;
    cout<<p2.first<<" "<<p2.second;//note Operator << is overloaded
    //n.showdata();


    cout<<"\n\n::::::::::::::::: In tuples :::::::::::::\n\n";
    tuple <string,int,int>t1;
    t1=make_tuple("Tanay",10,15);
    cout<<get<0>(t1);
    cout<<get<1>(t1);
    cout<<get<2>(t1);
}
