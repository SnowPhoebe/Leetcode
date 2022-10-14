class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        string original_str = str;
        reverse(str.begin(), str.end());
        return original_str == str;
    }
};