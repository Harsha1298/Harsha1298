// Problem Statement:

// Given three sorted arrays A, B and Cof not necessarily same sizes.

// Calculate the minimum absolute difference between the maximum and minimum number
// from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
// i.e. minimize | max(a,b,c) - min(a,b,c) |.

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int minDiff = INT_MAX;
    int i = 0, j = 0, k = 0;
    int aSize = A.size(), bSize = B.size(), cSize = C.size();

    while (i < aSize && j < bSize && k < cSize) {
        int minVal = min(A[i], std::min(B[j], C[k]));
        int maxVal = max(A[i], std::max(B[j], C[k]));

        minDiff = min(minDiff, maxVal - minVal);

        if (minDiff == 0)
            break;

        if (A[i] == minVal) i++;
        else if (B[j] == minVal) j++;
        else k++;
    }

    return minDiff;
}
