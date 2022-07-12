// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b){
    while(b > 0){
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    cout << gcd(14, 5) << '\n';
    cout << gcd(3, 15) << '\n';
    cout << gcd(18, 6) << '\n';
    return 0;
}
