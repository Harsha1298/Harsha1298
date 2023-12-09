// Problem Statement:
// Find the Bth smallest element in given array A .
// Selection Sort:
int Solution::kthsmallest(const vector<int> &A, int B) {
    int N = A.size();
    vector<int> A1(N);
    for(int i = 0; i < N; i++){
        A1[i] = A[i];
    }
    for(int i = 0; i < B; i++) {
        int min = A1[i];
        int idx = i;
        for(int j = i+1; j < N; j++) {
            if(A1[j] < min) {
                min = A1[j];
                idx = j;
            }
        }
        int temp = A1[i];
        A1[i] = A1[idx];
        A1[idx] = temp;
    }
    return A1[B-1];
}
