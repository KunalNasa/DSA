#include<iostream>
using namespace std;
int getlength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
void reversestring(char arr[])
{
    int s = 0, e = getlength(arr) - 1;
    while (s<e)
    {
        swap(arr[s++],arr[e--]);
    }

}
int main()
{
    char name[10];
    cout<<"Enter your name "<<endl;
    cin>>name;
    cout<<"Your name is "<<name<<endl;
    reversestring(name);
    cout<<"Length of your name: "<<getlength(name)<<endl;
    cout<<"Your reversed name is "<<name<<endl;
}