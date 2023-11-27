// problem description:

// You are given two positive numbers A and B . You need to find the maximum valued integer X such that:

// X divides A i.e. A % X = 0
// X and B are co-prime i.e. gcd(X, B) = 1


int gcd(int a, int b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}

int Solution::cpFact(int x, int y) {
    while (gcd(x, y) != 1) {
        x = x / gcd(x, y);
    }
    return x;
}
