// problem statement:
// Given an even number A ( greater than 2 ), return two prime numbers whose sum will be equal to the given number.
// If there is more than one solution possible, return the lexicographically smaller solution.

// Note: every even number can be expressed in sum of two prime numbers
vector<int> Solution::primesum(int A) {
    int isPrime[A+1]={0};
    isPrime[0]=1;
    isPrime[1]=1;
    // for(int i=0;i<=A;i++){
    //     cout<<isPrime[i]<<" ";
    // }
     for (int i = 2; i <= A; i++) { 
        if (isPrime[i] == 0) { 
            for (int j = 2*i; j <= A; j += i) 
                isPrime[j] = 1; 
        } 
    } 
    vector<int> v;
    for(int i=0;i<=A;i++){
        if(isPrime[i]==0 && isPrime[A-i]==0)
        {
            v.push_back(i);
            v.push_back(A-i);
            break;
        }
    }
    return v;
}
