// Problem Statement:
// Given an integer A pairs of parentheses, 
// write a function to generate all combinations of well-formed parentheses of length 2*A.
// Input 1:
// A = 3
// Output 1:
// [ "((()))", "(()())", "(())()", "()(())", "()()()" ]



void generateParentheses(int open, int close, string current, vector<string>& result, int n) {
    if (current.size() == n) {
        result.push_back(current);
        return;
    }
    if (open < n / 2) {
        generateParentheses(open + 1, close, current + '(', result, n);
    }
    if (close < open) {
        generateParentheses(open, close + 1, current + ')', result, n);
    }
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> result;
    if (A > 0) {
        generateParentheses(0, 0, "", result, 2 * A);
    }
    return result;
}
