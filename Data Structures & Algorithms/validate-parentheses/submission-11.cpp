class Solution {
public:
    bool isValid(string s) {
        vector<char> opening_brackets;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' or s[i] == '[' or s[i] == '{') {
                opening_brackets.push_back(s[i]);
            } else {
                if (opening_brackets.empty()) {
                    return false;
                }

                char check = opening_brackets.back();

                if (s[i] == ')' and check == '(')
                    opening_brackets.pop_back();
                else if (s[i] == ']' and check == '[')
                    opening_brackets.pop_back();
                else if (s[i] == '}' and check == '{')
                    opening_brackets.pop_back();
                else
                    return false;
            } 
        }   
        return opening_brackets.empty();
    }
};
