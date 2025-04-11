#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

__float128 f(__float128 n) {
    return cos((long double) n) + 1.0;
}

__float128 f_prime(__float128 n) {
    return -sin((long double) n);
}

int main() {
    __float128 n = 3.0; // initial guess
    cout << setprecision(50) << endl;

    while (true) {
        n = (n - (f(n) / f_prime(n)));
        cout << endl;
        cout << M_PI << endl;
        cout << (long double) n << endl;
    }
}



