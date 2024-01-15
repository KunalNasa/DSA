// ------- CLIMBING N STAIRS --------
// #include<iostream>
// using namespace std;
// int stairs(int n)
// {
//     if(n == 0)
//     return 1;
    
//     if(n < 0)
//     return 0;

//     return stairs(n-1) + stairs(n-2);
// }
// int main()
// {
//     int steps;
//     cin >> steps;
//     cout<<"The possible number of ways of climbing " << steps << " stairs are " << stairs(steps) << endl;
// }

// ------Read out num-------
// #include<iostream>
// #include <queue>
// using namespace std;
// void read(int num)
// {
//     if(num == 0)
//     {
//         return;
//     }
//     string arr[10] = {"zero","one","two","three","four","five", "six", "seven", "eight", "nine"};
//     int readingNum = num%10;
//     num = num / 10;
//     read(num);
//     cout<<arr[readingNum]<<" ";
    
// }
// int main()
// {
//     read(402);
// }

// ------SORT ARRAY, SUM OF ELEMENTS OF ARRAY, LINEAR SEARCH USING RECURSION-------
// #include<iostream>
// using namespace std;
// int isSorted(int arr[], int index, int n)
// {
//     if(index == n - 1)
//     {
//         return 1;
//     }

//     if(arr[index] < arr[index + 1])
//     {
//         return isSorted(arr,++index,n);
//     }
//     else
//     {
//         return 0;
//     }
// }

// int isbabbarsorted(int arr[], int n)
// {
//     if(n == 0 || n == 1)
//     {
//         return true;
//     }

//     if(arr[0] < arr[1])
//     {
//         return isbabbarsorted(arr + 1, n - 1);
//     }
//     else
//     {
//         return false;
//     }
// }

// int linearSearch(int arr[], int n, int key, int index = 0)
// {
//     if(n == 0)
//     {

//         return -1;
//     }
    
//     if(arr[0] == key)
//     {
//         return index;
//     }
//     else
//     {
//         return linearSearch(arr + 1, n - 1, key, ++index);
//     }
// }

// int arrSum(int arr[], int n, int sum = 0)
// {
//     if(n == 0)
//     {
//         return sum;
//     }
//     else
//     {
//         sum += arr[0];
//         return arrSum(arr + 1, n - 1, sum);
//     }

// }
// int main()
// {
//     int array[5] = {1,2,3,4,5};
//     int ans = isSorted(array,0,1);
//     cout<<ans<<endl;

//     int ans2 = isbabbarsorted(array,5);
//     cout<<ans2<<endl;

//     int arr[1] = {4};
//     int sum = arrSum(arr,1);
//     cout<<sum<<endl;

//     int lineararr[4] = {0, 1, 2, 5};
//     cout<<linearSearch(lineararr,4,10)<<endl;
// }


// ------BINARY SEARCH USING RECURSION------
// #include<iostream>
// using namespace std;
// int binarySearch(int arr[], int s, int key, int e)
// {
//     if(s > e)
//     {
//         return 0;
//     }
//     int mid = s + (e-s)/2;
//     if(arr[mid] == key)
//     {
//         return mid;
//     }
//     else if(arr[mid] > key)
//     {
//         return binarySearch(arr, s, key, mid - 1);
//     }
//     else
//     {
//        return binarySearch(arr, mid + 1, key, e);
//     }
// }
// int main()
// {
//     int arr[5] = {1,4,5,7,9};
//     cout<<"The element is present at index " << binarySearch(arr,0,7,4) << endl;
// }

//  ------Lowest and Highest Occurence-------

// #include<iostream>
// using namespace std;
// int lowestoccurence(int arr[], int s, int key, int e, int ans = -1)
// {
    
//     if(s > e)
//     {
//         return ans;
//     }
//     int mid = s + (e-s)/2;
//     if(arr[mid] == key)
//     {
//         ans = mid;
//         return lowestoccurence(arr,s,key, mid - 1, ans);
//     }
//     else if(arr[mid] > key)
//     {
//         return lowestoccurence(arr, s, key, mid - 1,ans);
//     }
//     else
//     {
//        return lowestoccurence(arr, mid + 1, key, e, ans);
//     }
// }

// int highestoccurence(int arr[], int s, int key, int e, int ans = -1)
// {
//     if(s > e)
//     {
//         return ans;
//     }
//     int mid = s + (e-s)/2;
//     if(arr[mid] == key)
//     {
//         ans = mid;
//         return highestoccurence(arr,mid + 1,key, e, ans);
//     }
//     else if(arr[mid] > key)
//     {
//         return highestoccurence(arr, s, key, mid - 1, ans);
//     }
//     else
//     {
//         return highestoccurence(arr, mid + 1, key, e, ans);
//     }
// }

// int main()
// {
//     int arr[6] = {0, 1, 2, 2, 2, 5};
//     cout<<lowestoccurence(arr,0,2,5) << endl;   
//     cout<<highestoccurence(arr,0,2,5) << endl;   
// }

// -------Peak element in an array ---------

// #include<iostream>
// using namespace std;
// int binarySearch(int arr[], int s, int e)
// {
//     int mid = s + (e-s)/2;
//     if(s >= e)
//     {
//         return mid;
//     }
//     if(arr[mid] > arr[mid + 1])
//     {
//         return binarySearch(arr, s, mid);
//     }
//     else if(arr[mid] < arr[mid + 1])
//     {
//        return binarySearch(arr, mid + 1, e);
//     }
// }
// int main()
// {
//     int arr[5] = {0, 1, 4, 3, 2};
//     cout<<binarySearch(arr,0,4);
// }

// -----BUBBLE AND SELECTION SORT USING RECURSION------

// #include<iostream>
// using namespace std;
// void bubbleSort(int arr[], int n)
// {
//     if(n == 0)
//     {
//         return ;
//     }

//     for (int i = 0; i < n-1; i++)
//     {
//         if(arr[i] > arr[i+1])
//         {
//             swap(arr[i],arr[i+1]);
//         }
//     }

//     bubbleSort(arr, n - 1);
// }

// void selectionSort(int arr[], int n, int index = 0)
// {
//     if(n == 0)
//     {
//         return ;
//     }

//     for (int i = 0; i < n-1; i++)
//     {
//         if(arr[index] > arr[i+1])
//         {
//             swap(arr[index],arr[i+1]);
//         }
//     }
//     selectionSort(arr + 1, n - 1, index++);
// }
// int main()
// {
//     int array[5] = {3,10,2,49,4};
//     bubbleSort(array,5);
//     for (int i = 0; i < 5; i++)
//     {
//         cout<< array[i] << " ";
//     }
//     cout << endl;
    
//     selectionSort(array,5);
//     for (int i = 0; i < 5; i++)
//     {
//         cout<< array[i] << " ";
//     }
//     cout << endl;
// }
