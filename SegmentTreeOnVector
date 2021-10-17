#include <bits/stdc++.h>

using namespace std;
  
typedef long long ll;
typedef double ld;
  
#define P pair
typedef P < int, int > Pii;
typedef P < ll, ll > Pll;
typedef P < string, string > Pss;
  
#define all(a) (a).begin(), (a).end()
#define len(a) (ll)(a.size())
#define f first
#define s second
  
#define yes "Yes"
#define no "No"  
#define pb push_back

#define INF (ll)(1e9)


ll mx(ll a, ll b){
    if(a == -INF) return b;
    if(b == -INF) return a;
    if(a < b) return b;
    return a;
}

ll mn(ll a, ll b){
    if(a == -INF) return b;
    if(b == -INF) return a;
    if(a > b) return b;
    return a;
}

struct SegmentTree{
    function<ll(ll, ll)> f;
    vector < ll > tree;
    vector < ll > a;

    SegmentTree(vector < ll > _a, function<ll(ll, ll)> g){
        this->f = g;
        this->a = _a;
        tree.assign(len(_a)*4, -INF);

        build(1, 0, len(_a)-1);
    }

    void build(ll node, ll l, ll r){
        if(l == r){
            tree[node] = a[l];
            return;
        }

        ll m = (l + r) / 2;
        build(node*2, l, m);
        build(node*2+1, m + 1, r);
        tree[node] = f(tree[node*2], tree[node*2+1]);
    }

    void UpDate(ll node, ll l, ll r, ll id, ll x){
        if(l > r) return;
        if(l > id || r < id) return;

        if(l == id and r == id){
            tree[node] = x;
            return;
        }

        ll m = (l + r) / 2;
        UpDate(node*2, l, m, id, x);
        UpDate(node*2+1, m+1, r, id, x);

        tree[node] = f(tree[node*2], tree[node*2+1]);
    }

    ll get(ll node, ll l, ll r, ll lq, ll rq){
        if(l > r) return -INF;
        if(l > rq or r < lq) return -INF;

        if(lq <= l and r <= rq)
            return tree[node];

        ll m = (l + r) / 2;
        return f(
            get(node*2, l, m, lq, rq),
            get(node*2+1, m+1, r, lq, rq));
    }
};
// n^2 mod 12345 + n^3 mod 23456

void solve(){
    vector < ll > a;
    for(ll i = 1; i <= 100000; ++i)
        a.pb((i*i)%12345 + (((i*i)%23456)*i)%23456);

    SegmentTree sgtMX(a, mx);
    SegmentTree sgtMN(a, mn);


    ll k;
    cin >> k;
    while(k--){
        ll l, r;
        cin >> l >> r;

        if(l > 0){
            --l, --r;
            cout << sgtMX.get(1, 0, len(a)-1, l, r) - sgtMN.get(1, 0, len(a)-1, l, r) << endl;
        }else{
            l = -l;
            --l;
            // r = -r;
            sgtMN.UpDate(1, 0, len(a)-1, l, r);
            sgtMX.UpDate(1, 0, len(a)-1, l, r);
        }
    }
	return;
}	


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
     
    ll t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
