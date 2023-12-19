// Problem Statement
// You are given a sorted array A of size N and a target value B.
// Your task is to find the index (0-based indexing) of the target value in the array.

// If the target value is present, return its index.
// If the target value is not found, return the index of least element greater than equal to B.
// Your solution should have a time complexity of O(log(N)).

int Solution::searchInsert(vector<int> &A, int B) {
    int low = 0;
    int high = A.size()-1;
    int index = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (A[mid] == B) {
            return mid;
        } else if (A[mid] < B) {
            low = mid + 1;
        } else {
            index = mid;
            high = mid - 1;
        }
    }
    return (index == -1) ? low : index;
}
