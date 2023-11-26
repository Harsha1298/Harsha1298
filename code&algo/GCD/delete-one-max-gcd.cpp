// Problem Statement:
// Given an integer array A of size N. 
//You have to delete one element such that the GCD(Greatest common divisor) of the remaining array is maximum.

// Approach:  

// Idea is to find the GCD value of all the sub-sequences of length (N – 1) 
// and removing the element which is not present in the sub-sequence with that GCD. The maximum GCD found would be the answer.
// To find the GCD of the sub-sequences optimally, 
// maintain a prefixGCD[] and a suffixGCD[] array using single state dynamic programming.
// The maximum value of GCD(prefixGCD[i – 1], suffixGCD[i + 1]) is the required answer.

int gcd(int A, int B){
    if (B == 0) 
        return A; 
    return gcd(B, A % B); 
}


int Solution::solve(vector<int> &A) {
    int n = A.size();
    int prefix[n+2] = {0};
    int suffix[n+2] = {0};
    prefix[1]=A[0];
    for(int i=2;i<=n;i++){
        prefix[i]=gcd(prefix[i-1],A[i-1]);
    }
    suffix[n] = A[n - 1];
    for (int i = n - 1; i >= 1; i--) {
        suffix[i] = gcd(suffix[i + 1], A[i - 1]);
    }
    int ans = max(suffix[2], prefix[n - 1]);
    for (int i = 2; i < n; i++) {
        ans = max(ans, gcd(prefix[i - 1], suffix[i + 1]));
    }
    return ans;
}
