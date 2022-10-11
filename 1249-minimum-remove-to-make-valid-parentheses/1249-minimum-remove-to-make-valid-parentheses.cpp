class Solution {
public:
    string remove_invalid(string s, char open, char close) {
        int count = 0;
        string ans;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == close && count == 0) continue;
            if (s[i] == open) 
                ++count;
            else if (s[i] == close && count != 0) 
                --count;
            ans.push_back(s[i]);
        } 
        return ans;
    }
    string minRemoveToMakeValid(string s) {
        string str = remove_invalid(s,'(',')');
        reverse(str.begin(), str.end());
        str = remove_invalid(str, ')', '(');
        reverse(str.begin(), str.end());
        return str;
    }
};