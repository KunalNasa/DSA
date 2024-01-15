// 1. How to create 2D array
// 2. How to take input/output
// 3. How to free memory
#include <iostream>
using namespace std;
int main()
{
    // int row, col;
    // cin >> row;
    // cin >> col;

    // //creating a 2D array
    // int **arr = new int *[row];
    // for (int i = 0; i < row; i++)
    // {
    //     arr[i] = new int[col];
    // }
    // //taking input
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }
    // //getting output
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // //releasing memory
    // for (int i = 0; i < row; i++)
    // {
    //     delete [] arr[i];
    // }
    // delete []arr;

    int rows, columns;
    cout<<"Enter rows: ";
    cin>>rows;
    cout<<"Enter columns: ";
    cin>>columns;
    int **array = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new int[columns - i];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns-i; j++)
        {
            cin>>array[i][j];
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns-i; j++)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }

    for (int i = 0; i < rows; i++)
    {
        delete [] array[i];
    }

    delete [] array;
}