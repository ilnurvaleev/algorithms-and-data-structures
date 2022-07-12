// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<ll> sieve(ll n){
    bool pr[n + 1];
    for(int i = 0; i < n + 1; ++i)
        pr[i] = true;

    vector<ll> prime;
    pr[0] = pr[1] = false;
    for(ll i = 2; i <= n; ++i){
        if(!pr[i]) continue;

        prime.push_back(i);
        for(ll j = i * i; j <= n; j += i)
            pr[j] = false;
    }
    return prime;
}

int main() {
    for(auto i : sieve(100))
        cout << i << ' ';
    return 0;
}
