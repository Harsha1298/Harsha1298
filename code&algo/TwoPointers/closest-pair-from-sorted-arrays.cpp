// Problem Statement:
// Given two sorted arrays of distinct integers, A and B, and an integer C, 
// find and return the pair whose sum is closest to C and the pair has one element from each array.

// More formally, find A[i] and B[j] such that abs((A[i] + B[j]) - C) has minimum value.

// If there are multiple solutions find the one with minimum i and 
// even if there are multiple values of j for the same i then return the one with minimum j.

// Return an array with two elements {A[i], B[j]}.


vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int m = A.size();
    int n = B.size();
    
    int i = 0, j = n - 1;
    int minDiff = INT_MAX;
    vector<int> result;
    while (i < m && j >= 0) {
        int sum = A[i] + B[j];
        int diff = abs(sum - C);

        if (diff < minDiff) {
            minDiff = diff;
            result = {A[i], B[j]};
        } else if (diff == minDiff && A[i] < result[0]) {
            result = {A[i], B[j]};
        } else if (diff == minDiff && A[i] == result[0] && B[j] < result[1]) {
            result = {A[i], B[j]};
        }

        if (sum > C) {
            j--;
        } else {
            i++;
        }
    }

    return result;
}
