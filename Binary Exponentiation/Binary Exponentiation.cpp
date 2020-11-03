// Binary Exponentiation 
#include<bits/stdc++.h>
using namespace std;

class BinExpo {
public:
    int bs, exp; // bs = base, exp = exponent
    int mod; // Modulus when the power gets too large

    BinExpo(int a, int b, int md = INT_MAX) : bs(a), exp(b), mod(md) {} // Cunstructor Call to initialize Variables (Mod is initialize to maximum integer value in absence of any other modulus)

    int powerIter() { // Interative function for binary exponentiation
        int res(1), a(bs), b(exp); // res = variable to store result, a = base, b = exponent
        while (b) { // This loop is equivalent to while (b > 0) or "while b is greater than 0"
            if (b & 1) (res *= a) %= mod; // When b is odd, multiply the present value of a to the result
            (a *= a) %= mod; // Square the value of base in each iteration
            b >>= 1; // Half the value of exponent in each iteration
        }
        return res; // Return the result
    }

    int powerRecur(int a = 0, int b = 0) { // Recursive function for binary exponentiation
        a == 0 and a != bs? a = bs, b = exp : a = a; // If it is first call of function, initialize the values
        // Final return statement of the function is equivalent to
        /*
        if (b == 0) return 1;
        else {
            if (b & 1) return (power((a * a) % mod, b >> 1) * a) % mod;
            else return (power((a * a) % mod, b >> 1)) % mod;
        }
        */
        // Another easy way of doing this is 
        /*
        if (b == 0) return 1;
        else {
            int x = power(a, b >> 1) % mod;
            (x *= x) %= mod;
            if (b & 1) return x * a;
            else return x;
        }
        */
        // The Below statement is doing same as above codes.
        return b == 0? 1 : (powerRecur((a * a) % mod, b >> 1) * (b & 1 ? a : 1)) % mod; 
    }
};

int main() {
	int a, b;
	cin >> a >> b;
	BinExpo calc(a, b);
	cout << calc.PowerIter() << " " << calc.PowerRecur() << "\n";
	return 0;
}