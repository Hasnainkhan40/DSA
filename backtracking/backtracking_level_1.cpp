
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;


//***find the all permutations ***
void permutation(string& str, int i){
    if(i >= str.length()){
        cout<< str << " ";
        return;
    }

    for (int j = i; j < str.length(); j++)
    {  
        swap(str[i], str[j]);

        //recursion call
        permutation(str, i+1);

        //backtraking
        swap(str[i], str[j]);
    }
    
}



//---solve the maze----
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
char direction[] = {'D', 'L', 'R', 'U'};


bool isSafe(int i, int j, int row, int col, int maze[3][3], vector<vector<bool>> &visited){
    if(((i >= 0 && i < row)&& (j >= 0 && j < col))&& (maze[i][j] == 1)&&(visited[i][j] == false)){
        return true;
    }
    else
    {
        return false;
    }
    
}


void solveMaze(int maze[3][3], int row, int col, int i, int j, vector<vector<bool>> &visited, vector<string>& path, string output){
    //bascase
    if(i == row-1 && j == col-1){
        path.push_back(output);
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        int newx = i + dx[k];
        int newy = j + dy[k];
        char dir = direction[k];

        if(isSafe(newx, newy, row, col, maze, visited)){
            visited[newx][newy] = true;
            //recursion
            solveMaze(maze, row, col, newx, newy, visited, path, output + dir);
            // backtracking
            visited[newx][newy] = false;
        }
    }

}



int main (){
    //---solve the maze----
    int maze[3][3] = {{1,0,0,},{1,1,0,},{1,1,1,},};

    if(maze[0][0] == 0){
        cout<<"No Path"<< endl ;
    }

    int row = 3;
    int col = 3;

    vector<vector<bool>> visited(row, vector<bool> (col, false));
    visited[0][0]= true;
    vector<string> path;
    string output = "";

    solveMaze(maze, row, col, 0,0, visited, path, output);

    for(auto i : path){
        cout << i << " ";
    }
    if(path.size() == 0){
        cout<< "No path have" ;
    }








    // ***find the all permutations ***
    // string str = "abc";
    // int i=0;

    // permutation(str, i);
    return 0;
}
