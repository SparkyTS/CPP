#include<iostream>
#include<vector>

using namespace std;

main()
{
    vector <int>v1 {10,20,30,40,50};
    cout<<"CAPACITY : ";
    cout<<v1.capacity();
    cout<<"\n\nSize : ";
    cout<<v1.size();
    //cout<<v1.at(2);
    //cout<<v1[2];
    cout<<"\n\nAfter Push back";
    v1.push_back(60);

    cout<<"\n\nCAPACITY : ";
    cout<<v1.capacity();
    cout<<"\n\nSize : ";
    cout<<v1.size();
    cout<<"\n\nFront : "<<v1.front();
    cout<<"\n\nBack : "<<v1.back();

    cout<<"\n\nAfter POP back";
    v1.pop_back();

    cout<<"\n\nSize : ";
    cout<<v1.size();
    cout<<"\n\nCAPACITY : ";
    cout<<v1.capacity();
    cout<<"\n\nFront : "<<v1.front();
    cout<<"\n\nBack : "<<v1.back();
    cout<<"\n\n------------------------------------------";

    vector <int>v2;
    cout<<"\n\nSize : ";
    cout<<v2.size();
    cout<<"\n\nCAPACITY : ";
    cout<<v2.capacity();

    cout<<"\n\n------------------------------------------";

    vector <int>v3(5);
    cout<<"\n\nSize : ";
    cout<<v3.size();
    cout<<"\n\nCAPACITY : ";
    cout<<v3.capacity();
    cout<<"\n\nFront : "<<v3.front();
    cout<<"\n\nBack : "<<v3.back();

    cout<<"\n\n------------------------------------------";

    vector <int>v4(5,10);
    cout<<"\n\nSize : ";
    cout<<v4.size();
    cout<<"\n\nCAPACITY : ";
    cout<<v4.capacity();
    cout<<"\n\nFront : "<<v4.front();
    cout<<"\n\nBack : "<<v4.back();

    if(v1!=v4) cout<<"Not same";

    vector <int> :: iterator it=v1.begin();
    v1.insert(it+1,15);//15 inserted at index 1
    for(int i=0;i<v1.size();i++)cout<<v1[i];
    it=v1.end();
    v1.insert(it-1,222);
    for(int i=0;i<v1.size();i++)cout<<v1[i];

}
