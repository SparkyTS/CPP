#include<iostream>
#include<string>
#include<string.h>
using namespace std;

main()
{
    string s1="Hello";
    string s2(" Tanay");
    string s3(s1);

    cout<<s1+s2<<endl;
    cout<<(s3==s1)<<endl;//try different operators
    cout<<s1.size()<<endl;
    s3+=s2;    cout<<s3<<endl;

    s1.assign("Hey..."); cout<<s1<<endl;
    s1.replace(2,s1.size(),"llo");    cout<<s1<<endl;
    s1.append("...");    cout<<s1<<endl;

    cout<<s3.find("Tanay")<<endl;
    s3+=s2;

    cout<<s3.rfind(" Tanay")<<endl;

    char str[20];
    strcpy(str,s3.c_str());
    cout<<str<<endl;

    s1.insert(2,"Tanay");
    cout<<s1<<endl;

    string s4="Amar";
    string s5="Amit";

    cout<<s4.compare(s5)<<endl;
    cout<<s1.compare(s4)<<endl;
    s5.assign(s4);
    cout<<s4.compare(s5)<<endl;

    s4.erase(); cout<<s4<<endl;

}
