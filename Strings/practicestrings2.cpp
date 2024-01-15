// #include<iostream>
// #include<string>
// using namespace std;
// void modifystring(string s)
// {
//     string newstring;

//   for (int i = 0; i < s.size(); i++)
//   {
//     if(s[i] != ' ')
//     {
//         newstring.push_back(s[i]);
//     }
//     else
//     {
//        newstring.append("@40");
//     }
//   }
//   cout<<newstring<<endl;
// }

// void removechar(string s)
// {
//     string newstring;

//   for (int i = 0; i < s.size(); i++)
//   {
//     if(s[i] == 'a' && s[i+1] == 'a' && s[i+2] == 'b')
//     {
//         i = i+2;
//     }
//     else
//     {
//        newstring.push_back(s[i]);
//     }
//   }
//   cout<<newstring<<endl;
// }
// string removeoccurence(string s, string part)
// {
//     // find function returns iterator of the beggining of string which we have to find
// while (s.length() != 0 && s.find(part) < s.length())
//     {
//         s.erase(s.find(part), part.length());//path ke first iterator se part ki length tak
//     }
//     return s;
    
// }
// int main()
// {
//     string fullname;
//     cout<<"Enter your full name: ";
//     getline(cin, fullname);
//     cout<<"Your full name is: "<<fullname<<endl;
//     // modifystring(fullname);
//     // removechar(fullname);
//     cout<<removeoccurence(fullname,"abc")<<endl;
// }

//-----PROBLEM - 2------
// #include<iostream>
// #include <string>
// using namespace std;
// string removeadjacent(string s)
// {
//     for (int j = 0; j < s.size(); j++)
//     {
//         for (int  i = 0; i < s.size() - 1; i++)
//     {
//         if (s[i] == s[i+1])
//         {
//             s.erase(i,2);
//         }
//     }
//     }
//     return s;
    
// }
// int main()
// {
//     string takeinp;
//     cout<<"Enter your sentence: ";
//     cin>>takeinp;
//     cout<<removeadjacent(takeinp)<<endl;
// }

//-----PROBLEM - 3------
#include<iostream>
#include<string>
using namespace std;
string modifystring(string s)
{
    int index[26] = {0};
    string finalstring; 
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i] - 'a';
        index[ch]++;
    }

    for (int i = 0; i < 26; i++)
    {
        char ch = i + 'a';
        if(index[i]>1)
        {
            finalstring.push_back(ch);
            // finalstring.push_back((char)index[i]); 
            finalstring += to_string(index[i]);
        }
        else if(index[i] == 1)
        {
            finalstring.push_back(ch);
        }
    }
    return finalstring;
    
}
int main()
{
    string s;
    cout<<"Enter your string: ";
    cin>>s;
    cout<<modifystring(s)<<endl;
}