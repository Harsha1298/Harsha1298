// Problem Statement:
// Given two integer arrays, A and B of size N and M, respectively. 
// Your task is to find all the common elements in both the array.

// NOTE:

// Each element in the result should appear as many times as it appears in both arrays.
// The result can be in any order.


vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    unordered_map<int,int> mpA;
    unordered_map<int,int> mpB;
    for(int i=0;i<A.size();i++){
        mpA[A[i]]++;
    }
    for(int i=0;i<B.size();i++){
        mpB[B[i]]++;
    }
    vector<int> result;
    for(int i=0;i<A.size();i++){
        if(mpA[A[i]]!=0&&mpB[A[i]]!=0){
            result.push_back(A[i]);
            mpA[A[i]]--;
            mpB[A[i]]--;
        }
    }
    return result;
}
