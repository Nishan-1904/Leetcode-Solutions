class Solution {
public:
    long long pow(long long n,long long x,long long mod){
        if (x == 0) return 1;
        if (x == 1) return n % mod;

        long long half = pow(n, x / 2, mod);
        long long res = (half * half) % mod;

        if (x % 2 == 1) {
            res = (res * n) % mod;
        }

        return res;
    }
    int countGoodNumbers(long long n) {
        const long long mod = 1000000007;
        long long even = (n + 1) / 2;  
        long long odd = n / 2;         
        return (pow(5,even,mod)*pow(4,odd,mod))% mod;
    }
};