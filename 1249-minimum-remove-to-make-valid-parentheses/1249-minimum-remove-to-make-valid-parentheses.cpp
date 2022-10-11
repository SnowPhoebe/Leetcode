class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> set;
        stack<int> stk;
        string ans;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else if (s[i] == ')'){
                if (stk.size() == 0) set.insert(i);
                else stk.pop();
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