// Problem Statement:
// Given an expression string A, examine whether the pairs and the orders of “{“,”}”, ”(“,”)”, ”[“,”]” are correct in A.

int Solution::solve(string A) {
    stack<char> s;
    unordered_map<char, char> mapping = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char c : A) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.empty() || s.top() != mapping[c]) {
                return 0;
            }
            s.pop();
        }
    }

    return s.empty() ? 1 : 0;
}
