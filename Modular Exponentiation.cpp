#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	if (n == 0)
        return 1;

    long long result = modularExponentiation(x, n / 2, m);
    result = (result * result) % m;

    if (n % 2 == 1)
        result = (result * x) % m;

    return result;
}