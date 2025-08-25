/*
567. Permutation in String

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.
*/

#include<iostream>
#include<vector>

using namespace std;

bool isFreqSame(int freq1[], int freq2[]) {
    for (int i = 0; i < 26; i++) {
        if(freq1[i] != freq2[i]) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int freq[26] = {0};
    for (int i = 0; i < s1.length(); i++) {
        freq[s1[i] - 'a']++;
    }

    int windowSize = s1.length();

    for (int i = 0; i < s2.length(); i++) {
        int windowIdx = 0, idx = i;
        int windowFreq[26] = {0};

        while(windowIdx < windowSize && idx < s2.length()) {
            windowFreq[s2[idx] - 'a']++;
            windowIdx++, idx++;
        }

        if(isFreqSame(freq, windowFreq)) {
            return true;
        }
    }
    return false;
}

bool checkInclusion1(string s1, string s2) {
    if(s2 < s1)
        return false;

    
    vector<int> freq1(26, 0), freq2(26, 0);
    for(char c : s1)
        freq1[c - 'a']++;

    int windowSize = s1.length();

    for (int i = 0; i < s2.length(); i++) {
        freq2[s2[i] - 'a']++;

        if(i >= windowSize) {
            freq2[s2[i - windowSize] - 'a']--;
        }

        if(freq1 == freq2)
            return true;
    }
    return false;
}

int main() {
    string s1 = "ab", s2 = "eidbaooo";

    if (checkInclusion1(s1, s2)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
