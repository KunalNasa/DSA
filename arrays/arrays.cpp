#include <iostream>
using namespace std;
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void maxarray(int arr[], int n)
{
    int maxelement = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        maxelement = max(maxelement, arr[i]); //function for finding max element
        // if(arr[i]>maxelement)
        // {
        //      maxelement = arr[i];
        // }
    }
    cout << maxelement << endl;
}
void minarray(int arr[], int n)
{
    int minelement = INT16_MAX;
    for (int i = 0; i < n; i++)
    {
        minelement = min(minelement, arr[i]);
        // if (arr[i] < minelement)
        // {
        //     minelement = arr[i];
        // }
    }
    cout << minelement << endl;
}
int main()
{
    // int array[10];
    // for assigning value 1 to every index of array we use this fill_n function.
    // fill_n(array,10,1);
    // for (int i = 0; i < 10; i++)
    // {
    //     cout<<array[i]<<endl;
    // }
    /*
    int hurray[15] = {1,2};
    for (int i = 0; i < 15; i++)
    {
        cout<<hurray[i]<<endl;
    }
    */
    /*
    int first[5] = {1,2,3,4,5};
    printarray(first, 5);
    */
    int sample[5] = {4, 3, 10, 40, 1};
    maxarray(sample, 5);
    minarray(sample, 5);
}