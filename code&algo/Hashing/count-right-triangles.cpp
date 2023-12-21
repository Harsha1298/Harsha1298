// Problem Statement
// Given two arrays of integers A and B of size N each, 
// where each pair (A[i], B[i]) for 0 <= i < N represents a unique point (x, y) in 2D Cartesian plane.
// Find and return the number of unordered triplets (i, j, k) 
// such that (A[i], B[i]), (A[j], B[j]) and (A[k], B[k]) form a right-angled triangle 
// with the triangle having one side parallel to the x-axis and one side parallel to the y-axis.
// NOTE: The answer may be large so return the answer modulo (109 + 7).

const int MOD = 1000000007;

int Solution::solve(vector<int> &A, vector<int> &B) {
    unordered_map<int, int> x_count, y_count;
    for (int i = 0; i < A.size(); ++i) {
        x_count[A[i]]++;
        y_count[B[i]]++;
    }
    int count = 0;
    for (int i = 0; i < A.size(); ++i) {
        count += (x_count[A[i]] - 1) * (y_count[B[i]] - 1);
        count %= MOD;
    }

    return count;
}
