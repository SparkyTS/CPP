#include<iostream>
#include<map>
using namespace std;

main()
{
    map <int,string>m1;
    m1[100]="Tanay";
    m1[200]="Sahil";
    m1[300]="yash";

    cout<<m1[100]<<endl<<m1[200]<<endl;

    map <int,string> :: iterator it=m1.begin();

    cout<<endl<<m1.at(200);

    cout<<endl<<m1.size();

    cout<<endl<<m1.empty()<<endl;

    m1.insert(pair<int,string> (105,"stark"));

    while(it!=m1.end())
    {
        cout<<it->second<<" ";it++;
    }

}
