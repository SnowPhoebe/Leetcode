class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> set;
        stack<int> stk;
        int count = 0;
        string ans;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++count;
                stk.push(i);
            }
            else if (s[i] == ')'){
                if (count == 0) set.insert(i);
                else {
                    --count;
                    stk.pop();
                }
            }
        }
        while (!stk.empty()) {
            set.insert(stk.top());
            stk.pop();
        }
        for (int i = 0; i < s.size(); ++i) {
            if (set.find(i) == set.end()) 
                ans.push_back(s[i]);
        }
        return ans;
    }
};