class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int>freq;

        for(char ch: word) {
            freq[ch]++;
        }

        int count = 0;
        for(auto it: freq) {
            char ch = it.first;

            if(islower(ch)) {
                if(freq.find(ch - 32) != freq.end())
                count++;
            } else {
                if(freq.find(ch + 32) != freq.end())
                count++;
            }
        }

        return count / 2;
    }
};