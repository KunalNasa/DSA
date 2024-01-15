// #include<iostream>
// using namespace std;
// int reverse(int arr[],int n, int m)
// {
//     int temp;
//     for (int i = 0; i < (n-m)/2; i++)
//     {
//         // temp = arr[i+m];
//         // arr[i+m] = arr[n-i-1];
//         // arr[n-i-1] = temp;
//         swap(arr[i+m],arr[n-i-1]);
//     }
//     return 0;
// }

// int reversebytwopointer(int arr[], int n)
// {
//     int s = 0, e = n-1;
//     while(s<=e)
//     {
//         swap(arr[s], arr[e]);
//         s++;
//         e--;
//     }
//     return 0;
// }

// int main()
// {
//     int m;
//     cout<<"Enter the index number: ";
//     cin>>m;
//     int arr[6] = {1,2,3,4,5,6};
//     reverse(arr,6,m);
//     for (int i = 0; i < 6; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;

// }
// ------PROBLEM - 2-------
// #include <iostream>
// #include <vector>
// using namespace std;

// void sortedarray(int arr1[], int n, int arr2[], int m, int arr3[])
// {

//     int i = 0, j = 0, k = 0;
//     while (i < n && j < m)
//     {
//         if (arr1[i] < arr2[j])
//         {
//             arr3[k] = arr1[i];
//             k++;
//             i++;
//         }
//         else
//         {
//             arr3[k] = arr2[j];
//             j++;
//             k++;
//         }
//     }
//     //-----the written below code is for copying the elements of array with larger size-----
//         // copy kardo bache hue first array ko
//         // remember : i ki value yaha zero nahi hai. upper vaale loop se increment ho chuki hai
//         while (i < n)
//         {
//             arr3[k] = arr1[i];
//             k++;
//             i++;
//         }
//         // copy kardo bache hue second array ko
//         // remember : j ki value yaha zero nahi hai.....
//         while (j < m)
//         {
//             arr3[k] = arr2[j];
//             k++;
//             j++;
//         }
// }
// void print(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }
// int main()
// {
//     int arr1[3] = {1, 3, 7};
//     int arr2[5] = {2, 4, 5, 6, 8};
//     int arr3[8] = {0};
//     sortedarray(arr1, 3, arr2, 5, arr3);
//     print(arr3, 8);
// }

// -------PROBLEM - 3--------
// #include<iostream>
// using namespace std;
// void sortit(int arr[], int n)
// {
//     int k = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == 0)
//         {
//             k++;
//         }
//     }

//         for(int i = 1; i < n; i++)
//         {
//             for (int j = 0; j < n-i; j++)
//             {
//                 if(arr[j+1] >= arr[j])
//                 {
//                     swap(arr[j+1],arr[j]);
//                 }

//             }
//         }

//     for (int i = 0; i < n-k; i++)
//     {
//         for (int j = i+1; j < n-k; j++)
//         {
//             if(arr[i] > arr[j])
//             {
//                 swap(arr[i],arr[j]);
//             }
//         }

//     }
// }
// int main()
// {
//     int arr[8] = {0,2,5,0,12,0,0,20};
//     sortit(arr,8);
//     for (int i = 0; i < 8; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// ----- PROBLEM - 3 ALTERNATE -----
// #include<iostream>
// using namespace std;
// void shiftnonzero(int arr[], int n)
// {
//     int nonzero = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if(arr[i] != 0)
//         {
//             swap(arr[i],arr[nonzero]);
//             nonzero++;
//         }
//     }

// }
// int main()
// {
//     int arr[8] = {0,2,5,0,12,0,0,20};
//     shiftnonzero(arr,8);
//     for (int i = 0; i < 8; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

//------PROBLEM - 4-------
// ROTATED ARRAY
// arr[5] = {1,2,3,4,5}; k = 2
// rot[5] = {4,5,1,2,3}; 2 place aage shift kardo elements ko.
// #include <iostream>
// #include<vector> 
// using namespace std;
// void betterans(vector<int> &nums, int k)
// {
//     vector<int> temp(nums.size());
//     for (int i = 0; i < nums.size(); i++)
//     {
//         temp[(i + k) % nums.size()] = nums[i];
//     }
//     nums = temp;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         cout << nums[i] << " ";
//     }
//     cout << endl;
// }
// void rotatearray(int arr[], int n, int k)
// {
//     int num = k;
//     int sortedarray[5] = {0};
//     int i = 0;
//     while (k > 0)
//     {
//         sortedarray[i] = arr[n - k];
//         i++;
//         k--;
//     }

//     for (int l = num, j = 0; l < n; l++, j++)
//     {
//         sortedarray[l] = arr[j];
//     }
//     for (int z = 0; z < n; z++)
//     {
//         cout << sortedarray[z] << " ";
//     }
//     cout << endl;
// }
// int main()
// {
//     int arr[6] = {1, 2, 3, 4, 5};
//     rotatearray(arr, 5, 2);
//     vector<int> p;
//     p.push_back(1);
//     p.push_back(2);
//     p.push_back(3);
//     p.push_back(4);
//     p.push_back(5);
//     betterans(p, 2);
// }

//------PROBLEM - 5-------
// #include <iostream>
// using namespace std;
// int ifrotated(vector<int> &arr)
// {
//     vector<int> b(arr.size());
//     vector<int> c(arr.size());
//     b = arr;
//     for (int i = 0; i < b.size() - 1; i++)
//     {
//         for (int j = i + 1; j < b.size(); j++)
//         {
//             if (b[i] > b[j])
//             {
//                 swap(b[i], b[j]);
//             }
//         }
//     }
//     c = b;
//     for (int j = 1; j < c.size(); j++)
//     {
//         for (int i = 0; i < c.size(); i++)
//         {
//             c[(i + j) % arr.size()] = b[i];
//         }

//         if (c == arr)
//         {
//             return 1;
//         }
//     }

//     return 0;
// }

// bool betterans(vector<int> &arr)
// {
//     int count = 0;
//     int n = arr.size();
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i - 1] > arr[i])
//         {
//             count++;
//             // Agar array rotated hai to count 1 se bada nahi ho payega.
//             // Sorted array ko rotate karke sochna agar na samajh aaye to.
//         }
//     }
//     if (arr[n - 1] > arr[0]) // When array is rotated by 1.
//     {
//         count++;
//     }
//     return count <= 1;
// }
// int main()
// {
//     vector<int> p;
//     p.push_back(4);
//     p.push_back(5);
//     p.push_back(1);
//     p.push_back(2);
//     p.push_back(3);

//     cout << ifrotated(p) << endl;
//     cout << betterans(p) << endl;
// }

