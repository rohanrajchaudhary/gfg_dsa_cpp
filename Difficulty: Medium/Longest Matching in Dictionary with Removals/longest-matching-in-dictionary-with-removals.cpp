class Solution {
    // Check if word is a subsequence of s using precomputed character indices
    bool isSubsequence(const string& word, const vector<vector<int>>& pos) {
        int last_idx = -1;
        for (char c : word) {
            int char_id = c - 'a';
            const auto& indices = pos[char_id];

            // Find the first occurrence after last_idx
            auto it = upper_bound(indices.begin(), indices.end(), last_idx);
            if (it == indices.end()) {
                return false;
            }
            last_idx = *it;
        }
        return true;
    }

public:
    string findLongestWord(string &s, vector<string> &d) {
        // Store indices of each character in s
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.length(); ++i) {
            pos[s[i] - 'a'].push_back(i);
        }

        string result = "";

        for (const string& word : d) {
            if (isSubsequence(word, pos)) {
                // Pick longer word, or lexicographically smaller if lengths match
                if (word.length() > result.length() || 
                   (word.length() == result.length() && word < result)) {
                    result = word;
                }
            }
        }

        return result;
    }
};