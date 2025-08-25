/*
151. Reverse Words in a String

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
*/

#include<iostream>
#include <algorithm>

using namespace std;

string reverseWords(string str) {
    int N = str.length();

    reverse(str.begin(), str.end());

    string ans = "";
    
    for (int i = 0; i < N; i++) {
        string currWord = "";

        while(str[i] != ' ' && i < N) {
            currWord += str[i];
            i++;
        }

        reverse(currWord.begin(), currWord.end());

        if(currWord.length() > 0) {
            ans += " " + currWord;
        }
    }
    
    return ans.substr(1);
}

int main() {
    string str = "Hello World";

    cout<< reverseWords(str);

    return 0;
}
