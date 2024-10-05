
#include <vector>
#include <string>
#include <algorithm> 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Pointer for the last element in nums1's valid part
        int j = n - 1; // Pointer for the last element in nums2
        int k = m + n - 1; // Pointer for the last position in nums1
        
        // Merge from the back of nums1
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i]; // Place nums1's element
                i--;
            } else {
                nums1[k] = nums2[j]; // Place nums2's element
                j--;
            }
            k--;
        }
        
        // If there are remaining elements in nums2, place them in nums1
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
        
        // No need to check for nums1, since it's already in place.
    }
};
