#include<iostream>
#include<iomanip>
static int row,col;
static int call_left = 2;
static int call_right = 1;
static int call_up = 1;
static int call_down = 2;
static int count = 1;
static int n ;
void Right(int** matrix){
    int i = 1 ;
    while(i++ <= call_right)
        if((row < n && row >= 0 )
            && (col<n && col>=0))
                matrix[row][++col] = count++;
    call_right+=2;
}
void Left(int** matrix){
    int i = 1 ;
    while(i++ <= call_left)
        if((row < n && row >= 0 )
           && (col<n && col>=0))
                matrix[row][--col] = count++;
    call_left+=2;
}
void Up(int** matrix){
    int i = 1 ;
    while(i++ <= call_up)
            if((row < n && row >= 0 )
               && (col<n && col>=0))
                    matrix[--row][col] = count++;
    call_up+=2;
}
void Down(int** matrix){
    int i = 1 ;
    while(i++ <= call_down)
            if((row < n && row >= 0 )
                && (col<n && col>=0))
                    matrix[++row][col] = count++;
    call_down+=2;
}
PrintMatrix(int** matrix){
for(int i = 0 ; i < n ; i++,std::cout<<"\n\n")
    for(int j = 0 ; j < n ; j++)
        std::cout << std::setw(5) <<matrix[i][j] << std::setw(5);
}
main()
{
    int square=n*n;
    std::cin >> n;
    square = n*n;
    if(n%2==0){
        row = n/2 ;
        col = row-1;
    }
    else
    row = col = (n/2);

    int** matrix;
    matrix = new int* [n];
    for(int i=0;i<n;i++)
        matrix[i] = new int[n];

    matrix[row][col] = count++;
    while(count<=square){
        Right(matrix);
        Up(matrix);
        Left(matrix);
        Down(matrix);
    }
    PrintMatrix(matrix);
}
