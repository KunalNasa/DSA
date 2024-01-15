#include<iostream>
using namespace std;

void addToans(vector<vector<int> > &board, int n, vector<vector<int> > &ans)
{
    vector<int> temp;
    for(int i =0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, int n, vector<vector<int> > &board)
{
    int x = row;
    int y = col;

    // for traversing in col (from right to left)
    while(y >= 0)
    {
        if(board[x][y] == 1)
        {
            return false;
        }
        y--;
    }
    x = row;
    y = col;

    // for traversing diagonal upside
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

    // for traversing in diagonal downwards
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
void solve(vector<vector<int> > &ans, vector<vector<int> > &board, int col, int n)
{
    if(col == n)
    {
        addToans(board, n, ans);
        return;
    }

    for(int row = 0; row < n; row++)
    {
        if(isSafe(row, col, n, board))
        {
            board[row][col] = 1;
            solve(ans, board, col + 1, n);
            board[row][col] = 0;
        }
    }
}
vector<vector<int> > nQueens(int n)
{
    vector<vector<int> > board(n, vector<int> (n, 0));
    vector<vector<int> > ans;

    solve(ans, board, 0, n);

    return ans;
}
int main()
{
    
}