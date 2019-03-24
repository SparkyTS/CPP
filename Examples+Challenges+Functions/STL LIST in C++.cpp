#include<iostream>
#include<list>

using namespace std;

main()
{
    list <int>l1 {20,10,50,40,30};
    list <string>name {"Tanay","Krupa","Sahil"};
    list <string>name1 {"yash","Dhiraj","harsh"};
    //cout<<l1.size();//returns total size of lists total elements

    l1.sort();//sort the list

    name.sort();
    list <string> :: iterator i=name.begin();
    name1.swap(name);
    while(i!=name.end())
    {
        cout<<*i<<" ";i++;
    }

    l1.push_front(0);
    list <int> :: iterator it=l1.begin();
    while(it!=l1.end())
    {
        cout<<*it<<" ";it++;
    }

    l1.pop_front();//pop the elements from the front of the list

    l1.remove(30);//removes passed argument if found

    l1.reverse();//reverse whole list
    l1.find(4);

    it=l1.begin();

    while(it!=l1.end())
    {
        cout<<*it<<" ";it++;
    }

    l1.clear();//clear whole list

}
