class Solution {
public:
    bool isPalindrome(string s) {

        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            if (isalnum(s[left]) && isalnum(s[right]))
            {
                if (s[left] != s[right])
                {
                    return false;
                }
                left++;
                right--;
            }
            else if (isalnum(s[left]) && !isalnum(s[right]))
            {
                right--;
            }
            else if (isalnum(s[right]) && !isalnum(s[left]))
            {
                left++;
            }
            else if (!isalnum(s[left]) && !isalnum(s[right]))
            {
                left++;
                right--;
            }
            
        }
        return true;
    }
};