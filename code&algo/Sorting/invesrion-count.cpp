// Problem Statement:
// Given an array of integers A. If i < j and A[i] > A[j], then the pair (i, j) is called an inversion of A. 
// Find the total number of inversions of A modulo (109 + 7).


int merge(vector<int> &arr, int l, int mid, int r) {
    int inversions = 0;
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inversions += (n1 - i);
            inversions %= 1000000007;
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    return inversions;
}

int mergeSort(vector<int> &arr, int l, int r) {
    int inversions = 0;
    if (l < r) {
        int mid = l + (r - l) / 2;
        inversions += mergeSort(arr, l, mid);
        inversions %= 1000000007;
        inversions += mergeSort(arr, mid + 1, r);
        inversions %= 1000000007;
        inversions += merge(arr, l, mid, r);
        inversions %= 1000000007;
    }
    return inversions;
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    int inversions = mergeSort(A, 0, n - 1);
    return inversions;
}
