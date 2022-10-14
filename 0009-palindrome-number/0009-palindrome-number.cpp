class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        // if (x >= 0 && x < 10) return true;
        int sec_int = 0;
        while (sec_int < x) {
            int digit = x % 10;
            x = x / 10;
            sec_int = sec_int * 10 + digit;
        }
        
        return (sec_int == x) || (sec_int/10 == x);
    }
};