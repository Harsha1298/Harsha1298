# Combinatorics

To calculate nCr through n!/(n-r)!r! -> it is tough to calculate factorials as it will overflow. 
Hence we can use this equation
nCr = nC(r-1) + (n-1)C(r-1) 
we can either use recursion or dp -> dp is suggestible because of lesser iterations
