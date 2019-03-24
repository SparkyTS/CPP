#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

///With One alive function ## Time Consuming ##
one_alive(int *a,int n)
{
    int j=1,sev;
    for(int i=0;i<n && j<3;i++)
    {
        if(a[i]==1)
        sev=i,j++;
    }
    if(j==2)
        {
        cout<<"\n\n The lucky Surviver is "<<sev+1<<endl;
        return 1;
        }
    else
        return 0;

}
//int next_to_kill(int *a,int n,int i)
//{
//    i=i+1;
//    if(i==n)
//        i=0;
//
//    for(i;i<n;i++)
//        if(a[i]==1)
//            return i;
//    if(i==n)
//        return next_to_kill(a,n,-1);
//}
//main()
//{
//    int a[101];
//    int n,i,kill;
//    cout<<"Enter total no of player : ";
//    cin>>n;
//
//    for(i=0;i<n;i++)
//        a[i]=1; a[i]='\0';
//
//        for(i=0;!one_alive(a,n);i++)
//            {
//                   if(i==n)  i=0;
//                   if(a[i]==1)
//                    {
//                    kill=next_to_kill(a,n,i);
//                    a[kill]=0;
//                    cout<<endl<<setw(3)<<i+1<<" killed "<<kill+1<<setw(5);
//                    i=kill;
//                    }
//            }
//}
///Printing Every Process Of Game :
int next_to_kill(const int *player,const int n,int i)
{
    i=i+1;
    if(i==n)
        i=0;

    for(i;i<n;i++)
        if(player[i]==1)
            return i;
    if(i==n)
        return next_to_kill(player,n,-1);
}

main()
{
    int player[151];
    int n,i,kill,surviver;
    cout<<"Enter total no of player : ";
    cin>>n;

    while(n>150){ cout<<"Maximum 150 players can play...!\n\nEnter total no of player : ";cin>>n; }

    surviver=n;

    for(i=0;i<n;i++)
        player[i]=1; player[i]='\0';

        for(i=0;surviver!=1;i++)
            {
                   if(i==n)  i=0;
                   if(player[i]==1)
                    {
                    kill=next_to_kill(player,n,i);
                    player[kill]=0;surviver--;
                    cout<<endl<<setw(3)<<i+1<<" killed "<<kill+1<<setw(5);
                    i=kill;
                    }
            }

        for(int i=0;i<n;i++)
        {

            if(player[i]==surviver)
            {
               cout<<"\n\nLucky Surviver is "<<i+1;
               break;
            }
        }
}
//
//main()
//{
//    int n,i,kill;
//    cout<<"Enter total no of player : ";
//    cin>>n;
//    vector<int> player(n);
//    for(int i=1;i<=n;i++) player[i-1]=i;
//    i=1;
//    while(player.size()!=1)
//    {
//        player.erase(player.begin()+i);
//        i+=1;
//    }
//
//}

///Only for finding Surviver
//int main() {
//    int Num,y,surviver;
//        cin>>Num;
//        surviver=-1;
//        y=1;
//        for(int x=0;x<Num;x++){
//            if(surviver<x){
//                    surviver=2*y-1;
//                    y++;
//            }
//            else{
//                    surviver=1;
//                    y=2;
//            }
//        }
//        cout<<"\nThe lucky surviver is "<<surviver;
//     return 0;
//}

