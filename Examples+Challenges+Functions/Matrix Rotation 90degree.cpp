#include<iostream>
#include<vector>
int main()
{
    int size = 3 ;
    int n = 2;
/* //Creating pointer to fixed-size array of vector(dynamic array)
*    std::vector <int>* v1 = new std::vector<int>[3];
*   std::vector <int>* v90 = new std::vector<int>[3];
*/  
//creating vector of vectors (fully dynamic)
    std::vector < std::vector<int> > v1 (3,std::vector<int>(3));
    std::vector < std::vector<int> > v90 (3,std::vector<int>(3));
//Initializing 3*3 matrix	
	v1[0][0]=1;		v1[0][1]=2;		v1[0][2]=3;
    v1[1][0]=4;     v1[1][1]=5;	    v1[1][2]=6;
    v1[2][0]=7;		v1[2][1]=8;		v1[2][2]=9;

    for(int row = 0 ; row < size ; row++,n=2,std::cout<<std::endl)
        for(int col = 0 ; col < size ; col++,n--)
            std::cout << (v90[row][col] = v1[n][row]) << " ";
}
