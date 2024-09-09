#include <vector>
#include <string>
#include <algorithm> // For min()

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Sort the array
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            // Avoid duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Move the left pointer to the right and skip duplicates
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    
                    // Move the right pointer to the left and skip duplicates
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    
                    // Move both pointers
                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;  // Increase sum by moving left pointer to the right
                }
                else {
                    right--;  // Decrease sum by moving right pointer to the left
                }
            }
        }
        
        return result;
    }
};
