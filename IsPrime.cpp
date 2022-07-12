// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool IsPrime(ll x){
    for(ll i = 2; i*i <= x; ++i){
        if(x % i == 0) return false;
    }
    return true;
}

int main() {
    cout << IsPrime(5) << '\n';
    cout << IsPrime(18) << '\n';
    cout << IsPrime(19);
    return 0;
}
