
#include <iostream>
#include <limits.h>
#include <vector>
#include <unordered_map>

using namespace std;

//usibg map in TC = O(1)
unordered_map<int, bool> rowChack;
unordered_map<int, bool> udChack;
unordered_map<int, bool> bdChack;

void printboard(vector<vector<char>> &board, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j< n; j++)
        {
           cout<< board[i][j]  << " " ;
        }
        cout<<  endl;
    }
    cout<< endl << endl;
}

bool isSafe(int row, int col,  vector<vector<char>> &board,  int n){

    if(rowChack[row] == true){
       return false;
    }
     if(udChack[n-1+col-row] == true){
       return false;
    }
     if(bdChack[row+col] == true){
       return false;
    }
    return true;
    // int i = row;
    // int j = col;

    // while (j>=0)
    // {
    //     if(board[i][j] == 'Q'){
    //         return false;
    //     }
    //     j--;
    // }

    
    //  i = row;
    //  j = col;
    // while (i >=0 && j >= 0)
    // {
    //     if(board[i][j] == 'Q'){
    //         return false;
    //     }
    //     i--;
    //     j--;
    // }


    //  i = row;
    //  j = col;
    // while (i < n && j >= 0)
    // {
    //     if(board[i][j] == 'Q'){
    //         return false;
    //     }
    //     i++;
    //     j--;
    // }
    
    // return true;
}

//TC = O(1)
void solove(vector<vector<char>> &board, int col, int n){
    if(col >= n){
        printboard(board, n);
        return;
    }

    //Ek case 
    for (int row = 0; row < n; row++)
    {
    if (isSafe( row, col, board, n))
        {
        board[row][col] = 'Q';
        rowChack[row] = true;
        udChack[n-1+col-row] =  true;
        bdChack[row+col] = true;

        solove(board, col+1, n);
        board[row][col] = '-';
        rowChack[row] = false;
        udChack[n-1+col-row] = false;
        bdChack[row+col] = false;
        }
        
    }
    
}


//****N-Queen***
int main(){
    int n = 4;
    vector<vector<char>> board(n, vector<char> (n, '-'));

    int col = 0;
    solove(board, col, n);
    return 0;
}