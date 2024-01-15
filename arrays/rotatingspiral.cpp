#include<iostream>
using namespace std;
void spiral(int arr[3][3])
{
    int startingcol = 0;
    int startingrow = 0;
    int endingcol = 2;
    int endingrow = 2;
    int totalelements = 3*3;
    int count = 0;
    //complexity of code = O(m*n),
    
    while (count < totalelements)
    {
        //printing starting row
        for (int index = startingcol; count < totalelements && index <= endingcol; index++)
        {
            cout<<arr[startingrow][index]<<" ";
            count++;
        }
        startingrow++;
        //printing ending column
        for (int index = startingrow; count<totalelements && index <= endingrow; index++)
        {
            cout<<arr[index][endingcol]<<" ";
            count++;
        }
        endingcol--;
        //printing ending row
        for (int index = endingcol; count<totalelements && index >=startingcol ; index--)
        {
            cout<<arr[endingrow][index]<<" ";
            count++;
        }
        endingrow--;
        //printing starting column
        for (int index = endingrow; count<totalelements && index >= startingrow; index--)
        {
            cout<<arr[index][startingcol]<<" ";
            count++;
        }
        startingcol++;
    }
    
}
int main()
{
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    spiral(arr);
}