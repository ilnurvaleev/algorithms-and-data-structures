// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<ll> factorize(ll x){
    vector<ll> factors;
    ll x2 = x;
    for(ll i = 2; i*i <= x && i <= x2; ++i){
        while(x2 % i == 0){
            factors.push_back(i);
            x2 /= i;
        }
    }
    if(x2 > 1)
        factors.push_back(x2);
    return factors;
}

int main() {
    for(auto i : factorize(27000))
        cout << i << ' ';
    return 0;
}
