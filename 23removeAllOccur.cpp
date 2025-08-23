/*
1910. Remove All Occurrences of a Substring

Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.
*/

#include<iostream>
#include<string>

using namespace std;

string removeOccurrences(string str, string part) {
    while (str.length() > 0 && str.find(part) < str.length()) 
    {
        str.erase(str.find(part), part.length());
    }

    return str;
}

int main() {
    string str = "daabcbaabcbc";
    string part = "abc";

    cout << removeOccurrences(str, part);

    return 0;
}
