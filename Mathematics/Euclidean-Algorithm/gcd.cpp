#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }

    return gcd(b % a, a);
}

int main() {
    int a = 308, b = 4368;

    cout << "mdc = " << gcd(a, b) << endl;
    cout << "mmc = " << a * b / gcd(a, b) << endl; // minimo multiplo comum

    cout << gcd(7129, 983) << endl; // primos

    return 0;
}