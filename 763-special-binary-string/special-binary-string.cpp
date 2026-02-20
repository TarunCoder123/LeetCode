#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> specialBlocks;
        int count = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            // Increase for '1', decrease for '0'
            if (s[i] == '1')
                count++;
            else
                count--;

            // When count becomes 0, we found a special substring
            if (count == 0) {
                // Remove outer 1 and 0 and solve recursively
                string inner = s.substr(start + 1, i - start - 1);
                string processed = "1" + makeLargestSpecial(inner) + "0";
                specialBlocks.push_back(processed);
                start = i + 1;
            }
        }

        // Sort in descending lexicographical order
        sort(specialBlocks.begin(), specialBlocks.end(), greater<string>());

        // Combine all blocks
        string result;
        for (string &block : specialBlocks) {
            result += block;
        }

        return result;
    }
};
