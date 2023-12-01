// problem statement:
// Given three integers A, B, and C, where A represents n, B represents r, and C represents p and p is a prime number greater than equal to n, find and return the value of nCr % p where nCr % p = (n! / ((n-r)! * r!)) % p.

// x! means factorial of x i.e. x! = 1 * 2 * 3... * x.

// NOTE: For this problem, we are considering 1 as a prime.

typedef long long ll;

ll exp(ll a, ll b, ll c){
    if(b==0)
    return 1;
    if(b==1)
    return a;
    ll half = exp(a,b/2,c);
    ll ans = (half*half)%c;
    if(b&1){
        ans*=a;
        ans%=c;
    }
    return ans;
}

int Solution::solve(int A, int B, int C) {
    ll f[A+1]={0};
    f[0]=f[1]=1;
    for(int i=2;i<A+1;i++){
        f[i] = (i*f[i-1])%C;
    }
    return ((f[A]*exp(f[B],C-2,C))%C * (exp(f[A-B],C-2,C))%C)%C;
}
