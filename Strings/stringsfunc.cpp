// getline() - take user input string with space as non terminating char.
// push_back() - add a character at end of a string.
// pop_back() - remove character from the end of a string.
// capacity() - This function returns the capacity allocated to the string, which can   be equal to or more than the size of the string. Additional space is allocated so that when the new characters are added to the string, the operations can be done efficiently.
// resize - This function changes the size of the string, the size can be increased or decreased.(we can use to remove whitespaces)
// length() - returns the length of the string.
// shrink_to_fit() - This function decreases the capacity of the string and makes it equal to the minimum capacity of the string. This operation is useful to save additional memory if we are sure that no further addition of characters has to be made.
// begin() - returns the iterator at the beginning of the string.
// end() - returns the iterator at the end of the string.

#include<iostream>
using namespace std;
// string longest(string names[], int n)
//     {
//         int *arr = new int[n];
//         for(int i = 0; i < n; i++)
//         {
//             arr[i] = names[i].length();
//         }
//         int value = INT16_MIN, getindex;
//         for (int i = 0; i < n; i++)
//         {
//             if(arr[i] > value)
//             {
//                 value = arr[i];
//                 getindex = i;
//             }
//         }
//         return names[getindex];
//     }
int main()
{

}