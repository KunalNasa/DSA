#include<iostream>
using namespace std;

void addToans(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;
    
    // for moving in cols backward(from right to left)
    while(y >= 0)
    {
        if(board[x][y] == 1)
        {
            return false;
        }
        y--;
    }
    y = col;
    x = row;
    // for moving upside in diagonal
    while(x >= 0 && y >= 0)
    {
        if(board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }
    x = row;
    y = col;
    // for moving downside in diagonal
    while(x < n && y >= 0)
    {
        if(board[x][y] == 1)
        {
            return false;
        }
        x++;
        y--;
    }
    
    return true;
}
void solve(vector<vector<int>> &board, vector<vector<int>> &ans, int col, int n)
{
    if(col == n)
    {
        addToans(board, ans, n);
        return;
    }
    // solve 1 case and leave rest on recursion
    for(int row = 0; row < n; row++)
    {
        // if placing queen is safe
        if(isSafe(row, col, board, n))
        {
            //place queen in board
            board[row][col] = 1;
            solve(board, ans, col + 1, n);
            //backtrack
            board[row][col] = 0;
        }
    }
}
vector<vector<int>> nQueens(int n)
{
	// Write your code here
	vector<vector<int>> board(n , vector<int> (n, 0));
    vector<vector<int> > ans;
        
    solve(board, ans, 0, n);
        
    return ans;
	
}
int main()
{
    
}