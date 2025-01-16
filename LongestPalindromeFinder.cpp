#include "LongestPalindromeFinder.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int findLongestPalindrome() {
    ifstream inFile("BigData.txt");

    if (!inFile.is_open()) {
        cerr << "Unable to open file." << endl;
        return -1;
    }

    string text, line;
    while (getline(inFile, line)) text += line;
    inFile.close();

    auto expandAroundCenter = [&text](int left, int right) {
        while (left >= 0 && right < text.length() && text[left] == text[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    };

    int maxLength = 0;

    for (int i = 0; i < text.length(); ++i) {
        int len1 = expandAroundCenter(i, i);
        int len2 = expandAroundCenter(i, i + 1);
        maxLength = max(maxLength, max(len1, len2));
    }

    return maxLength;
}
