class Solution {
public:
    int romanToInt(string s) {
        // Map each character to its corresponding value
        unordered_map<char, int> roman{
            {'I', 1}, {'V', 5}, {'X', 10}, 
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int result = 0;
        for (int i = 0; i < s.length(); ++i) {
            // Check if the current value is smaller than the next
            if (i + 1 < s.length() && roman[s[i]] < roman[s[i+1]]) {
                result -= roman[s[i]];
            } else {
                result += roman[s[i]];
            }
        }
        return result;
    }
};
