// Problem Statement:
// Given a string A. Find the rank of the string amongst its permutations sorted lexicographically.
// Assume that no characters are repeated.

// Note: The answer might not fit in an integer, so return your answer % 1000003


const int MOD = 1000003;

long long factorial(int n) {
    if (n <= 1) return 1;
    long long fact = 1;
    for (int i = 2; i <= n; ++i) {
        fact = (fact * i) % MOD;
    }
    return fact;
}


long long findlongrank(string s){
   int n = s.size();
    vector<int> count(256, 0);

    for (char c : s) {
        count[c]++;
    }

    long long rank = 1;
    for (int i = 0; i < n; ++i) {
        
        for (char c = 0; c < s[i]; ++c) {
            if (count[c] > 0) {
                rank = (rank + (factorial(n - i - 1) * count[c]) % MOD) % MOD;
            }
        }
        count[s[i]]--;
    }

    return rank;
}


int Solution::findRank(string A) {
    long long res = findlongrank(A);
    return res%1000003;
}
