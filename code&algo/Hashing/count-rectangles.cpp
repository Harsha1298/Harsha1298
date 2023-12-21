// Problem Statement:
// Given two arrays of integers A and B of size N each, where each pair (A[i], B[i]) 
// for 0 <= i < N represents a unique point (x, y) in a 2-D Cartesian plane.

// Find and return the number of unordered quadruplet (i, j, k, l) such that 
// (A[i], B[i]), (A[j], B[j]), (A[k], B[k]) and (A[l], B[l]) form a rectangle with the rectangle 
// having all the sides parallel to either x-axis or y-axis.

int Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    if (n < 4) return 0;

    unordered_map<int, unordered_map<int, int>> pointsMap;

    for (int i = 0; i < n; ++i) {
        pointsMap[A[i]][B[i]]++;
    }

    int count = 0;


    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (A[i] != A[j] && B[i] != B[j]) { 
                if (pointsMap[A[i]][B[j]] > 0 && pointsMap[A[j]][B[i]] > 0) { 
                    count += (pointsMap[A[i]][B[j]] * pointsMap[A[j]][B[i]]); 
                }
            }
        }
    }

    return count / 2;
}
