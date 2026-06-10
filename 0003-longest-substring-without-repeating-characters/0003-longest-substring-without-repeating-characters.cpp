class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> longest;
        int right;
        int left = 0;
        int maxLength = 0; 

        for (right = 0; right < s.size(); right++)
        {
            if (!longest.contains(s[right]))
            {
                longest.insert(s[right]);
                
                
                maxLength = max(maxLength, (int)longest.size());
            }
            
            
            else
            {
                while (longest.contains(s[right]))
                {
                    longest.erase(s[left]); 
                    left++;                 
                }
                
                longest.insert(s[right]); 
            }
        }

        return maxLength; 
    }
};