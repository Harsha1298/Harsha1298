// Problem Statement:
// Given an array of integers A, we call (i, j) an important reverse pair if i < j and A[i] > 2*A[j].
// Return the number of important reverse pairs in the given array A.

int mergeAndCount(vector<int>& nums, int left, int mid, int right) {
    int count = 0;
    int j = mid + 1;
    
    for (int i = left; i <= mid; ++i) {
        while (j <= right && nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }
    
    vector<int> temp;
    int leftIdx = left, rightIdx = mid + 1;
    
    while (leftIdx <= mid && rightIdx <= right) {
        if (nums[leftIdx] <= nums[rightIdx]) {
            temp.push_back(nums[leftIdx++]);
        } else {
            temp.push_back(nums[rightIdx++]);
        }
    }
    
    while (leftIdx <= mid) {
        temp.push_back(nums[leftIdx++]);
    }
    while (rightIdx <= right) {
        temp.push_back(nums[rightIdx++]);
    }
    
    for (int i = left, k = 0; i <= right; ++i, ++k) {
        nums[i] = temp[k];
    }
    
    return count;
}

int mergeSortAndCount(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return 0;
    }
    
    int mid = left + (right - left) / 2;
    int count = mergeSortAndCount(nums, left, mid) + mergeSortAndCount(nums, mid + 1, right);
    count += mergeAndCount(nums, left, mid, right);
    
    return count;
}

int Solution::solve(vector<int> &A) {
    return mergeSortAndCount(A, 0, A.size() - 1);
}
