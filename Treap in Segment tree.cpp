// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;

#define P pair
typedef P<int, int> Pii;
typedef P<ll, ll> Pll;
typedef P<string, string> Pss;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


#define add_fill(a, c) setw(a) << setfill(c)
// #define endl '\n'

#define slimming(a) a.shrink_to_fit()
#define len(a) (ll)a.size()

#define f first
#define s second

const ll INF = (ll) (1e9);
#define MOD 1000000009

#define yes "YES"
#define no "NO"
#define imp "impossible"

#define pb push_back
#define eb emplace_back

const int alpha = 256;
const char FirstSymbol = 'a';

bool bit(ll mask, ll k){
    return ((mask >> k)&1);
}

ll get_rand() {
   return (rand() << 16) ^ rand();
}

struct Node{
    ll x, y;
    ll len;

    Node *left, *right;

    Node(ll key){
        this->len = 1;
        this->x = key;
        this->y = get_rand();

        this->left = nullptr;
        this->right  = nullptr;
    }
};

struct Treap{
    Node* root;

    Treap(){
        this->root = nullptr;
    }

    ll GetLen(Node* t){
        return (t == nullptr ? 0:t->len);
    }

    void UpDate(Node* t){
        t->len = GetLen(t->left) + GetLen(t->right) + 1;
    }

    Node* merge(Node* t1, Node* t2){
        if(t1 == nullptr) return t2;
        if(t2 == nullptr) return t1;

        if(t1->y > t2->y){
            t1->right = merge(t1->right, t2);

            UpDate(t1);

            return t1;
        }else{
            t2->left = merge(t1, t2->left);

            UpDate(t2);

            return t2;
        }
    }

    P < Node*, Node* > split(Node* t, ll k){
        if(t == nullptr) return {nullptr, nullptr};

        if(t->x < k){
            auto [l, r] = split(t->right, k);
            t->right = l;

            UpDate(t);

            return {t, r};
        }else{
            auto [l, r] = split(t->left, k);
            t->left = r;

            UpDate(t);

            return {l, t};
        }
    }

    bool find(Node* t, ll k){
        if(t == nullptr) return false;

        if(t->x == k) return true;

        if(t->x < k)
            return find(t->right, k);
        return find(t->left, k);
    }

    ll GetLess(Node* t, ll val){
        if(t == nullptr) return 0;

        if(t->x < val)
            return GetLen(t->left) + 1 + GetLess(t->right, val);
        if(t->x == val)
            return GetLen(t->left);
        if(t->x > val)
            return GetLess(t->left, val);
    }

    ll GetLess(ll value){
        return GetLess(root, value);
    }

    ll GetGreat(ll value){
        return GetLen(root) - GetLess(value) - find(root, value);
    }

    Node* insert(Node* t, ll k){
        if(find(t, k)) return t;

        Node* o = new Node(k);
        auto [l, r] = split(t, k);

        t = merge(merge(l, o), r);
        return t;
    }

    Node* erase(Node* t, ll k){
        if(!find(t, k)) return t;

        auto [l, o] = split(t, k);
        auto [m, r] = split(o, k+1);

        t = merge(l, r);
        return t;
    }

    void insert(ll k){
        root = insert(root, k);
    }

    void erase(ll k){
        root = erase(root, k);
    }
};

struct SegmentTree{
    vector < Treap > t;
    
    SegmentTree(ll n, vector < ll > &a){
        t.resize(n*4);
        build(1, 0, n-1, a);
    }

    void build(ll node, ll l, ll r, vector < ll > &a){
        if(l == r){
            t[node].insert(a[l]);
            return;
        }

        ll m = (l + r) / 2;
        build(node*2, l, m, a);
        build(node*2+1, m+1, r, a);

        for(int i = l; i <= r; ++i)
            t[node].insert(a[i]);
    }

    void UpDateAdd(ll node, ll _l, ll _r, ll id, ll val){
        if(_l > id or _r < id)return;
        
        t[node].insert(val);
            
        if(_l == _r and _l == id)return;

        ll m = (_l + _r) / 2;

        UpDateAdd(node*2, _l, m, id, val);
        UpDateAdd(node*2+1, m+1, _r, id, val);
    }

    void UpDateErase(ll node, ll _l, ll _r, ll id, ll val){
        if(_l > id or _r < id) return;  

        ll m = (_l + _r) / 2;
 
        t[node].erase(val);

        if(_l == _r and _l == id)return;

        UpDateErase(node*2, _l, m, id, val);
        UpDateErase(node*2+1, m+1, _r, id, val);
    }

    ll GetLess(ll node, ll _l, ll _r, ll l, ll r, ll val){
        if(_l > r or _r < l) return 0;
        
        if(l <= _l and _r <= r)
            return t[node].GetLess(val);
        
        ll m = (_l + _r) / 2;

        return GetLess(node*2, _l, m, l, r, val) 
            + GetLess(node*2+1, m + 1, _r, l, r, val);
    }

    ll GetGreat(ll node, ll _l, ll _r, ll l, ll r, ll val){
        if(_l > r or _r < l) return 0;

        if(l <= _l and _r <= r)
            return t[node].GetGreat(val);

        ll m = (_l + _r) / 2;
        return GetGreat(node*2, _l, m, l, r, val) 
            + GetGreat(node*2+1, m + 1, _r, l, r, val);
    }
};

void solve(){
    ll n, q;

    cin >> n;
    cin >> q;

    vector < ll > a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];


    ll ans = 0;    
    SegmentTree sgt(n, a);
    --n;
    for(int i = 0; i <= n; ++i){
        ans += sgt.GetGreat(1, 0, n, 0, i, a[i]);
    }

    cout << endl;
    while(q--){
        ll t;
        cin >> t;
        if(t == 0){
            cout << ans << '\n';
        }else{

            ll l, r;
            cin >> l >> r;
            --l, --r;

            if(r < l)
                swap(l, r);

            ans -= sgt.GetLess(1, 0, n, l, r-1, a[l]);
            ans -= sgt.GetGreat(1, 0, n, l, r-1, a[r]);
            
            ans += sgt.GetLess(1, 0, n, l, r-1, a[r]);
            ans += sgt.GetGreat(1, 0, n, l, r-1, a[l]);

            sgt.UpDateErase(1, 0, n, l, a[l]);
            sgt.UpDateErase(1, 0, n, r, a[r]);

            swap(a[l], a[r]);

            sgt.UpDateAdd(1, 0, n, l, a[l]);
            sgt.UpDateAdd(1, 0, n, r, a[r]);
        }
    }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

   ll t = 1;
   // cin >> t;
   while (t--) {
        solve();
        cout << endl;
   }
   return 0;
}
