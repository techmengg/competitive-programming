#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the end of the array
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0; // Set current digit to 0 and continue to carry
        }
        
        // If all digits were 9, we need to add 1 at the beginning
        vector<int> result(n + 1, 0);
        result[0] = 1; // Set the first digit to 1
        return result;
    }
};
