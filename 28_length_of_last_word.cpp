// Problem: 58. Length of Last Word
// Difficulty: Easy
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int i = s.length() - 1;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }
        return count;
    }
};
