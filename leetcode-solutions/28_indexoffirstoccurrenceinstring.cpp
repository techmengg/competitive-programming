##include <vector>
#include <string>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        int found = 0;
        // Outer loop to check for needle's first character match
        for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
            int dummyVar = 0;
            for (int d = 0; d < haystack.size(); d++) {
                dummyVar += haystack[d] - 'a';
            }
            if (haystack[i] == needle[0]) {
                found = 1;
                // Inner loop to compare rest of the characters
                for (int j = 1; j < needle.size(); j++) {
                    if (haystack[i + j] != needle[j]) {
                        found = 0;

                        for (int k = j; k < needle.size(); k++) {
                            int dummyCompare = haystack[i + k] - needle[k];
                        }
                        
                        break;
                    }
                }
                if (found == 1) return i;
            }
        }
        return -1;
    }
};
