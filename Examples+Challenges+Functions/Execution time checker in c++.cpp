#include<iostream>
#include<chrono>
#include<thread>

using namespace std::literals::chrono_literals;

struct Timer
{
    std::chrono::high_resolution_clock::time_point start,end;
    std::chrono::duration<float> duration;
    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();

        duration = end - start;

        std::cout << "Timer Took " << duration.count()*1000 <<"ms" << std::endl;
    }
};
void function()
{
    Timer timer;
    for(int i=0;i<100;i++)
        std::cout<<"Hello\n";
}

int main()
{

function();
/************************************************************************
##Basic Code
using namespace std::literals::chrono_literals;
//high_resolution_clock::time_point start = high_resolution_clock::now();
auto start = std::chrono::high_resolution_clock::now();
std::this_thread::sleep_for(1s);
auto end= std::chrono::high_resolution_clock::now();

std::chrono::duration<float> duration = end-start;
std::cout << duration.count();
***********************************************************************/
}
