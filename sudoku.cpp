#include <bits/stdc++.h>
using namespace std;

    
bool is_valid(int rw, int cl, char num, vector< vector< char > > &board)
{
    for(int i = 0; i < 9; i+=1)
    {
        if(board[i][cl] == num)
            return false;
    }
    
    for(int i = 0; i < 9; i+=1)
    {
        if(board[rw][i] == num)
            return false;
    }
    
    int t_rw = 3*(rw/3) ; 
    int t_cl = 3*(cl/3) ;
    
    for(int i = t_rw; i < t_rw + 3 ; i+=1)
    {
        for(int j = t_cl; j < t_cl + 3; j+=1)
        {
            if( board[i][j] == num)
                return false;
        }
        
    }
    
    return true; 
}


bool sudoku_solver(vector< vector<char> > &board)
{
    int used = 0;
    for(int i = 0; i < board.size(); i +=1)
        for(int j = 0; j < board[0].size(); j +=1)
            if(board[i][j] != '.') 
                used +=1;

    if(used == 81)
        return true;

    for(int i = 0; i < board.size(); i +=1)
    {
        for(int j = 0; j < board[0].size(); j +=1)
        {
            if(board[i][j] == '.')
            {
                for(char ch = '1'; ch <= '9'; ch+=1)
                {
                    if(is_valid(i, j, ch,  board))
                    {
                        board[i][j] = ch;
                        if(sudoku_solver(board) == true)
                            return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }

    return true;
}
    
int main()
{
    vector<vector< char> > board ;
    int flag = 0;
    // board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
    board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    // board.push_back({'5','3','.','.','7','.','.','.','.'});
    // vector <char> temp ;
    // temp =  {'5','3','.','.','7','.','.','.','.'};
    int used = 0;
    sudoku_solver(board); 
    for(int i = 0; i < board.size(); i +=1)
    {
        for(int j = 0; j < board[0].size(); j +=1)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}    
    // void solveSudoku(vector<vector<char>>& board) {
    //     int flag = 0;
    // }
// };



