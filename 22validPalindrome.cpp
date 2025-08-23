/*
125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/

#include<iostream>
#include<string>
#include <cctype>

using namespace std;

bool isPalindrome(string str){
    int i = 0, j = str.length() - 1;

    while(i <= j) {
        if(!isalnum(str[i])) {
            i++;
            continue;
        }
        if(!isalnum(str[j])) {
            j--;
            continue;
        }
        if(tolower(str[i]) != tolower(str[j])) {
            return false;
        }
        i++, j--;
    }
    return true;
}    

int main() {
    string str= "2$1racecar1$2";
    
    if(isPalindrome(str)) {
        cout << "PALINDROME";
    } else {
        cout << "NOT PALINDROME";
    } 

    return 0;
}
