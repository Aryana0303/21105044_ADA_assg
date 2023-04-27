#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

vector<vector<char> > board(9, vector<char>(9, '.')); 

bool isValid(vector<vector<char> > &board, int row, int col, char c)
{
   

    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c) // char already present in the row
        {
            return false;
        }
        if (board[row][i] == c) // char alrady present in the col
        {
            return false;
        }
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) //checks if the char is present in the 3*3 box or not 
        {
            return false;
        }
    }
    return true;
}



bool solve(vector<vector<char> >& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')//check if it is an empty cell
                {
                    //once you find an empty cell you will try out everyhting from 0 to 9
                    for(char c='1';c<='9';c++)
                    {
                        if(isValid(board,i,j,c))//this isValid will check wether we can place the char at that empty position or not
                        {
                            board[i][j] = c;
                            if(solve(board)==true)
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';//reset 
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;//If all cells are filled with valid numbers, return true.
    }




void sudokuSolver(vector<vector<char> > &board)
{
   
    solve(board);
}

int main()
{
    for (int i = 0; i < 9; i++)  //take input
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    sudokuSolver(board);

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

   
}
 
 
 