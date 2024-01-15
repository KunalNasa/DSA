#include<iostream>
#include <vector>
using namespace std;
vector<int> getMoreAndLess(int arr[], int n, int x)
 {
	    vector<int> finalans;
	    vector<int> array;
	    // int small, large;
	    for(int i = 0; i < n; i++)
	    {
	        array.push_back(arr[i]);
	    }
	    auto small = lower_bound(array.begin(),array.end(), x);
	    auto large = upper_bound(array.begin(), array.end(), x);
        int x1 = distance(array.begin(), small);
        int x2 = distance(array.begin(), large) ;
        cout<< x1<<" "<< x2;
	    finalans.push_back(x1);
	    finalans.push_back(n-x1);
	    return finalans;
	}

inline int getMax(int& a, int& b)
{
    return (a > b) ? a:b;
}

void print(int arr[], int n, int start = 0)
{
    for (int i = start; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
int main()
{
    int a = 1, b = 3;
    int ans = 0;
    ans  = (a > b) ? a:b;
    cout<<ans<<endl;
    int arr[5] = {1, 2, 3, 5, 10};
    print(arr, 5, 3);
    print(arr, 5);
    int Arr[7] = {1, 2, 8, 10, 11, 12, 19};
    getMoreAndLess(Arr,7,5);

}