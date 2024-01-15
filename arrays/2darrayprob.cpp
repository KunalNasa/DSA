// #include<iostream>
// using namespace std;
// void wave(int arr[4][4])
// {
//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             if(i%2 == 0)
//             {
//             cout<<arr[j][i]<<"  ";
//             }
//             else
//             {
//                 cout<<arr[3-j][i]<<"  ";
//             }
//         }
//     }
// }
// int main()
// {
//     int arr[4][4] = {{1,1,1,1},{2,2,2,2},{3,3,3,3},{4,4,4,4}};
//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     wave(arr);
// }

//----PROBLEM - 2-----
//spiral print
// #include<iostream>
// using namespace std;
// void spiral(int arr[3][3])
// {
//     int startingcol = 0;
//     int startingrow = 0;
//     int endingcol = 2;
//     int endingrow = 2;
//     int totalelements = 3*3;
//     int count = 0;
//     //complexity of code = O(m*n),

//     while (count < totalelements)
//     {
//         //printing starting row
//         for (int index = startingcol; count < totalelements && index <= endingcol; index++)
//         {
//             cout<<arr[startingrow][index]<<" ";
//             count++;
//         }
//         startingrow++;
//         //printing ending column
//         for (int index = startingrow; count<totalelements && index <= endingrow; index++)
//         {
//             cout<<arr[index][endingcol]<<" ";
//             count++;
//         }
//         endingcol--;
//         //printing ending row
//         for (int index = endingcol; count<totalelements && index >=startingcol ; index--)
//         {
//             cout<<arr[endingrow][index]<<" ";
//             count++;
//         }
//         endingrow--;
//         //printing starting column
//         for (int index = endingrow; count<totalelements && index >= startingrow; index--)
//         {
//             cout<<arr[index][startingcol]<<" ";
//             count++;
//         }
//         startingcol++;
//     }
    
// }
// int main()
// {
//     int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
//     spiral(arr);
// }

//----PROBLEM - 3-----
// #include<iostream>
// using namespace std;
// bool searchmatrix(int arr[3][4],int target)
// {
//     int column = 4;
//     int s = 0;
//     int e = 3*4 - 1;
//     int mid = s + (e-s)/2;
//     while (s<=e)
//     {
//         int element = arr[mid/column][mid%column];
//         if (element == target)
//         {
//             return 1;
//         }
//         else if (element > target)
//         {
//             e = mid - 1;
//         }
//         else
//         {
//             s = mid + 1;
//         }
//         mid = s + (e-s)/2;
//     }
//     return 0;
// }
// int main()
// {
//     int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
//     cout<<searchmatrix(arr,7)<<endl;
// }

//-----PROBLEM - 4------
//ROTATING A MATRIX BY 90 DEGREES
#include<iostream>
using namespace std;

void rotatematrix(int transpose[3][3])
{
    int startingcol = 0;
    int endingcol = 3-1;
    while (startingcol < endingcol)
    {
        for (int i = 0; i < 3; i++)
        {
            swap(transpose[i][startingcol],transpose[i][endingcol]);
        }
        startingcol++;
        endingcol--;
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<transpose[i][j]<<"  ";
        }
        cout<<endl;
    }
    
}
void transpose(int mat[3][3])
{
    int mat2[3][3] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat2[i][j] = mat[j][i];
        }
    }
    rotatematrix(mat2);
}
int main()
{
    int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    transpose(mat); 
}