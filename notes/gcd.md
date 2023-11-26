# Greatest Common Divisor

gcd(a,b) -> will always lie between 1 and min(a,b)
gcd can be performed in any sequence in an array as gcd is commutative
gcd(a,b,c) = gcd(gcd(a,b),c);
gcd(a,b)=gcd(a,b%a);  b>a -> tc: o(logn)