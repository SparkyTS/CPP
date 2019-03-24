#include <iostream>
#include <cmath>
#include <vector>

constexpr bool place_queen  {true};
constexpr bool remove_queen {false};
constexpr int N = 6;//no. of queens on the board.

void printBoard ();
bool placeQueen(int);
bool is_safe(int,int);

bool board[N][N]={};//initializing board with no queens in it.
int count = 0;//to count the number of possible solution.

///---------------------------------------------------
//creating new class to store coordinates of queens which has been placed on the board.
struct coords{
    int row,col;

    coords()
        : row{-1},col{-1} {}
    coords(int r , int c)
        : row{r},col{c} { }
};
///-------------------------------------------------


////////////////////////////////////////////////////////
///*** This Block is Keeping the track of Queens.
//creating a array of N queens instead of vector for the sake of speed.
//to store the list of coordinates on which queen is present.

coords Queens[N]; //std::vector <coords>Queens;
int q_size = -1;  //to keep track of valid index.

void AddQueen(const int row ,const int col){
    q_size++;
    Queens[q_size].row = row;
    Queens[q_size].col = col;
}

void RemoveQueen(){
    q_size--;
}
/////////////////////////////////////////////////////////


///--------------- MAIN FUNCTION ------------------------------
int main()
{
	//start placing the queen from first coloumn.
    placeQueen(0);
    std::cout << "Total no of solution found is : " << count;
}
///------------------------------------------------------------


/////////////////////////////////////////////////////////////
///This Block is dedicated for printing stuff.
//to print the board after all queen is placed.
void printBoard() {
    for(const auto& row : board){
        for(const auto& elem : row)
            std::cout << (elem ? 'Q' : '_') << ' ';
        std::cout << '\n';
    }
    /*//Heavy Weight Print Function "Should Use For Printing only one solution.
    for(int i = 0 ; i <= (N * 5) ; i++,std::cout << '-');
    std::cout <<"\n";
    for(const auto& row : board){
        for(const auto& elem : row)
            std::cout << (elem ? " Q " : "   ") << " |";
        std::cout << "\n";
        for(int i = 0 ; i <= (N * 5) ; i++,std::cout << '-');
        std::cout << '\n';
    }*/
    std::cout << "\n\n";
    count++;
}
///////////////////////////////////////////////////////////////

///-----------------------------------------------------------
//for checking the queens position before placing onto the board.
bool is_safe(const int row,const int col){
    for(int i = 0 ; i <=q_size ; i++){
		//if two queen is there on the same row.
        if(Queens[i].row == row)
            return false;
		//if two queens are on the same diagonal then slope will be 1 so can not place there.
        if(std::abs(Queens[i].row - row ) == std::abs(Queens[i].col - col))
            return false;
    }
    return true;
}
///------------------------------------------------------------


////////////////////////////////////////////////////////////////////////
///for placing the queen on the board.
bool placeQueen(const int col){
    //if all queens are placed successfully on the board print the board and return true.
	if(col == N ){
        printBoard();
        return true;
    }

	//trying to place the queens on the different rows.
    for(int row = 0 ; row < N ; row++){
            //checking to see if position is safe to place the queen or not.
			if(is_safe(row,col)){
				//if it is safe to place queen then place it on the board.
                board[row][col] = place_queen;
				//add the coordinates on which queen is placed.
                    AddQueen(row,col);//for vector : Queens.emplace_back(row,col);
                //now try to place the queens on the next columns.
				placeQueen(col+1);

/*  //for only printing one solution.
         if(placeQueen(col+1)) return true;
*/
				//now remove the queen from the last position to try different combinations.
                board[row][col] = remove_queen;
				//remove the coordinates from the list after removing the queen.
                RemoveQueen(); //for vector : Queens.pop_back();
            }
    }
    return false;
}
//////////////////////////////////////////////////////////////////////////
