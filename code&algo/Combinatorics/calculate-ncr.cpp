// Problem statement
// Given three integers A, B, and C, where A represents n, B represents r, and C represents m, 
// find and return the value of nCr % m where nCr % m = (n!/((n-r)!*r!))% m.

int Solution::solve(int n, int r, int m) {
    
    int arr[n+1][r+1];
    for(int i=0;i<=n;i++){
        arr[i][0]=1;
    }
    for(int j=1;j<=r;j++){
        arr[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=r;j++){
            arr[i][j]=(arr[i-1][j]%m+arr[i-1][j-1]%m)%m;
        }
    }
    return arr[n][r]%m;
}
