// Problem Statement:
// On the first row, we write a 0. 
// Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01,
//  and each occurrence of 1 with 10.
// Given row number A and index B, return the Bth indexed symbol in row A. (The values of B are 1-indexed.).

int Solution::solve(int A, int B) {
    if(A==0)
    return 0;
    int res = solve(A-1,(B/2+B%2));
     if(res==1)
    {
        if(B%2==1)
        return 1;
        return 0;
    }
    else{
        if(B%2==0)
        return 1;
        return 0;
    }
}
