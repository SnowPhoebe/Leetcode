class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); ++i) {
            stk.push(s[i]);
            if (stk.top() == ']') {
                stk.pop();
                string temp_str;
                while (stk.top() >= 'a' && stk.top() <= 'z') {
                    temp_str.push_back(stk.top());
                    stk.pop();
                }
                reverse(temp_str.begin(), temp_str.end());
                stk.pop();
                int digit = 1;
                int num = 0;
                while (!stk.empty() && isdigit(stk.top())) {
                    num += digit*(stk.top()-'0');
                    digit *= 10;
                    stk.pop();
                }
                string ans;
                for (int m = 0; m < num; ++m) {
                    ans += temp_str;
                }
                for (int n = 0; n < ans.size(); ++n) {
                    stk.push(ans[n]);
                } 
            }
            
        }
        string res;
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};