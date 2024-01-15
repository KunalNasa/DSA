bool isvalid(int j, int k, vector<vector<int> > m, int n, vector<vector<int> > temp)
{
    if((j > 0 && j < n) && (k > 0 && k < n) && temp[j][k] == 0 && m[j][k] == 1)
    {
        return true;
    }
    else
    {
        return 0;
    }
}
void solve(vector<vector<int> >m,vector<vector<int> > temp, int j, int k, int n, 
           vector<string> &ans, string output)
{
    if(j == n - 1 && k == n - 1)
    {
        ans.push_back(output);
        return;
    }
    temp[j][k] = 1;

    // move right 
    int newj = j;
    int newk = k + 1;
    if(isvalid(newj,newk, m, n, temp))
    {
        output.push_back('R');
        solve(m, temp, newj, newk, n,ans, output);
        output.pop_back();
    }
    // move left
    newj = j;
    newk = k - 1;
    if(isvalid(newj,newk, m, n, temp))
    {
        output.push_back('L');
        solve(m, temp, newj, newk, n,ans, output);
        output.pop_back();
    }

    // move up
    newj = j - 1;
    newk = k;
    if(isvalid(newj,newk, m, n, temp))
    {
        output.push_back('U');
        solve(m, temp, newj, newk, n,ans, output);
        output.pop_back();
    }

    // move down 
    newj = j + 1;
    newk = k;
    if(isvalid(newj,newk, m, n, temp))
    {
        output.push_back('D');
        solve(m, temp, newj, newk, n,ans, output);
        output.pop_back(); 
    }
    temp[j][k] = 0;

}