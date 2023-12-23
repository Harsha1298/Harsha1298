// Problem Statement:
// Given two arrays of integers A and B describing a pair of (A[i], B[i]) coordinates in a 2D plane. 
// A[i] describe x coordinates of the ith point in the 2D plane, 
// whereas B[i] describes the y-coordinate of the ith point in the 2D plane.

// Find and return the maximum number of points that lie on the same line.
int Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    if (n <= 2) return n;
    int maxPoints = 2;
    for(int i=0;i<n-1;i++){
        unordered_map<double,int> slopeCount;
        int duplicatePoints = 1; 
        int verticalPoints = 0;
        for (int j = i + 1; j < n; ++j) {
            if (A[i] == A[j]) {
                if (B[i] == B[j]) {
                    duplicatePoints++;
                } else {
                    verticalPoints++;
                }
                continue;
            }

            double slope = (B[j] - B[i]) * 1.0 / (A[j] - A[i]);
            slopeCount[slope]++;
        }
        int currentMax = verticalPoints + duplicatePoints;
        for (const auto& pair : slopeCount) {
            currentMax = max(currentMax, pair.second + duplicatePoints);
        }

        maxPoints = max(maxPoints, currentMax);
    }
    return maxPoints;
}
