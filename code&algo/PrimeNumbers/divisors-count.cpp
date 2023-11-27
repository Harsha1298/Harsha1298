// problem statement:
// Given an array of integers A, find and return the count of divisors of each element of the array.
// NOTE: The order of the resultant array should be the same as the input array.

vector<int> Solution::solve(vector<int> &A) {
    vector<int> v;
    int maxinte = 0;
    for(int i=0;i<A.size();i++){
        if(A[i]>maxinte)
        maxinte=A[i];
    }
    int arr[maxinte+1]={0};
    for(int i=1;i<=maxinte;i++){
        for(int j=i;j<=maxinte;j+=i){
            arr[j]+=1;
        }
    }
    for(int i=0;i<A.size();i++){
        v.push_back(arr[A[i]]);
    }
    return v;
}
