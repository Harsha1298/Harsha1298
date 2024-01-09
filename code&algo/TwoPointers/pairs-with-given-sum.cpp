// Problem Statement:
// Given a sorted array of distinct integers A and an integer B, 
// find and return how many pair of integers ( A[i], A[j] ) such that i != j have sum equal to B.

int Solution::solve(vector<int> &A, int B) {
    int count = 0;
    int left = 0, right = A.size() - 1;

    while (left < right) {
        int sum = A[left] + A[right];
        
        if (sum == B) {
            count++;
            left++;
            right--;
        } else if (sum < B) {
            left++;
        } else {
            right--;
        }
    }
    
    return count;
}
