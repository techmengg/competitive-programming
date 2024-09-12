#include <vector>
#include <string>
#include <algorithm> 

using namespace std;


class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int k = 0; // Pointer for the position of the next valid element

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // Place the valid element at the current position of k
                k++; // Move the position of k to the next index
            }
        }

        return k; // Return the number of elements that are not equal to val
    }
};
