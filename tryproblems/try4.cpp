// #include<iostream>
// using namespace std;
// int factorial(int n)
// {
//     if(n == 0)
//     {
//         return 1;
//     }
    
//     return n * factorial(n - 1);
// }

// int fibonacci(int n)
// {
//     if(n == 0)
//     {
//         return 0;
//     }
//     if(n == 1)
//     {
//         return 1;
//     }
//     return fibonacci(n - 1) + fibonacci(n - 2);
// }

// int sumofnumber(int number, int sum = 0)
// {
//     if(number == 0)
//     {
//         return sum;
//     }
//     sum += number;
//     return sumofnumber(number - 1, sum);
// }

// int sumofdigits(int number, int sum = 0)
// {

//     if(number == 0)
//     {
//         return sum;
//     }
//     sum += number % 10;
//     number /= 10;

//     return sumofdigits(number, sum);
// }

// void countingnumbersreverse(int num)
// {
//     if(num == 0)
//     {
//         return;
//     }
//     cout << num << " ";
//     countingnumbersreverse(num - 1);
// }

// void countingnumbers(int num)
// {
//     if(num == 0)
//     {
//         return ;
//     }
//     countingnumbers(num - 1);
//     cout << num << " ";
// }

// int apowerb(int a, int b, int ans = 1)
// {
//     if(b == 0)
//     {
//         return ans;
//     }
//     ans = ans * a;
    
//     return apowerb(a,b - 1, ans);
// }
// int ApowerB(int a, int b)
// {
//     if(b == 0)
//     {
//         return 1;
//     }
//     if(b == 1)
//     {
//         return a;
//     }
//     if(b % 2 == 0)
//     {
//         return ApowerB(a, b/2) * ApowerB(a, b/2);
//     }
//     else
//     {
//         return a * ApowerB(a, b/2) * ApowerB(a, b/2);
//     }
// }
// int stringpalindrome(string str, int s, int e)
// {
 
//     if(s >= e)
//     {
//         return 1;
//     }
//     if(str[s] == str[e])
//     {
//         return stringpalindrome(str, s + 1, e - 1);
//     }
//     else
//     {
//         return 0;
//     }
// }

// int arraysum(int *arr, int n, int sum = 0)
// {
//     if(n == 0)
//     {
//         return sum;
//     }
    
//     sum += arr[0];
//     return arraysum(arr + 1, n - 1, sum);
// }

// int binarysearch(int *arr, int s, int e, int key)
// {
//     int mid = s + (e - s) / 2;
//     if(arr[mid] == key)
//     {
//         return mid;
//     }

//     else if(arr[mid] > key)
//     {
//         return binarysearch(arr, s, mid - 1, key);
//     }

//     else
//     {
//        return binarysearch(arr, mid + 1, e, key);
//     }
// }
// int main()
// {
//     cout<< factorial(5) << endl;
//     cout<< fibonacci(5) << endl;
//     cout<< sumofnumber(5) << endl;
//     cout<< sumofdigits(15) << endl;
//     countingnumbers(5);
//     cout << endl;
//     countingnumbersreverse(5);
//     cout << endl;
//     cout << apowerb(2,4) << endl;
//     cout << ApowerB(2,4) << endl;
//     cout << stringpalindrome("abba", 0, 3) << endl;
//     int arr[5] = {5, 2, 3, 4, 5};
//     cout<<arraysum(arr, 5) << endl;
//     cout << binarysearch(arr, 0, 4, 3) << endl;
// }

#include<iostream>
using namespace std;
void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }
    
    int index1 = 0, index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}
void mergeSort(int *arr, int s, int e)
{
    if(s >= e)
    {
        return ;
    }
    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);

    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}
int main()
{
    int arr[5] = {2,10,4,30,5};
    mergeSort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}