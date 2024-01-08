// Problem Statement:
// Given an one-dimensional integer array A of size N and an integer B.

// Count all distinct pairs with difference equal to B.

// Here a pair is defined as an integer pair (x, y), where x and y are both numbers in the array and their absolute difference is B.

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> numCount;
    unordered_set<int> uniquePairs;
    int count =0;
    for (int i = 0; i < A.size(); i++) {
        numCount[A[i]]++;
    }
    if (B == 0) {
        for (auto &[num, freq] : numCount) {
            if (freq > 1) {
                count++;
            }
        }
        return count;
    } else {
        for (int i = 0; i < A.size(); i++) {
            int x = A[i] - B;
            if (numCount.find(x) != numCount.end()) {
                int smaller = min(A[i], x);
                int larger = max(A[i], x);
                int combined = smaller * A.size() + larger;
                if (uniquePairs.find(combined) == uniquePairs.end()) {
                    uniquePairs.insert(combined);
                    count++;
                }
            }
        }
    }
    return count;
}
