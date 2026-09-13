class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> bracketMap = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            // If opening bracket
            if (bracketMap.find(c) == bracketMap.end()) {
                st.push(c);
            } 
            // If closing bracket
            else {
                // Check if stack is empty or mismatch
                if (st.empty() || st.top() != bracketMap[c]) {
                    return false;
                }
                st.pop();
            }
        }
        
        // Valid only if all opened brackets were closed
        return st.empty();
    }
};
