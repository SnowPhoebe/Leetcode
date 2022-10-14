class Solution {
public:
    string decodeString(string s) {
        stack<string> str_stk;
        stack<int> num_stk;
        string curr_str = "";
        string curr_num = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                curr_str += s[i];
            }
            else if (isdigit(s[i])) {
                curr_num += s[i];
            }
            else if (s[i] == '[') {
                str_stk.push(curr_str);
                num_stk.push(stoi(curr_num));
                curr_str = "";
                curr_num = "";
            }
            else {
                int number = num_stk.top();
                num_stk.pop();
                string temp_str = str_stk.top();
                str_stk.pop();
                for (int m = 0; m < number; ++m) {
                    temp_str += curr_str;
                }
                curr_str = temp_str;
            }
        }
        return curr_str;
        
    }
};