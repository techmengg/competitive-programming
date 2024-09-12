#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Stack to hold the opening brackets
        stack<char> stk;

        // Map to match corresponding closing brackets
        unordered_map<char, char> matching_bracket = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        // Traverse each character in the string
        for (char c : s) {
            // If it's a closing bracket
            if (matching_bracket.count(c)) {
                // If the stack is not empty and top of the stack matches the corresponding opening bracket
                if (!stk.empty() && stk.top() == matching_bracket[c]) {
                    stk.pop();  // Pop the matching opening bracket
                } else {
                    return false;  // Mismatch or stack is empty
                }
            }
            // If it's an opening bracket, push it onto the stack
            else {
                stk.push(c);
            }
        }

        // If the stack is empty, it means all brackets were matched correctly
        return stk.empty();
    }
};
