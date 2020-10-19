mod=10**9+7
#nCr with respect to modulo 10^9+7
def ncr(n, r): 
    num = den = 1 
    for i in range(r): 
        num = (num * (n - i)) % mod
        den = (den * (i + 1)) % mod 
    return (num * pow(den,mod - 2, mod)) % mod
