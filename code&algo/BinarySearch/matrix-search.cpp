// Problem Statement:
// Given a matrix of integers A of size N x M and an integer B. Write an efficient algorithm that searches for integer B in matrix A.

// This matrix A has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than or equal to the last integer of the previous row.
// Return 1 if B is present in A, else return 0.

// NOTE: Rows are numbered from top to bottom, and columns are from left to right.


int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int rows = A.size();
    int cols = A[0].size();
    int low = 0, high = rows * cols - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int mid_element = A[mid / cols][mid % cols];
        
        if (mid_element == B) {
            return 1;
        } else if (mid_element < B) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
}
