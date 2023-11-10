#include <bits\stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 400100;
ll tree[MAXN];

void build(int node, int l, int r, vector<int>& a){
	if(l == r){
		tree[node] = a[l];
		return;
	}

	int m = (l + r) >> 1;

	build(node<<1, l, m, a);
	build(node<<1|1, m+1, r, a);

	tree[node] = tree[node<<1] + tree[node<<1|1];
}

// tree[node] - [l, r]
void update(int node, int l, int r, int pos, ll v){
	if(l == pos && r == pos){
		tree[node] = v;
		return;
	}

	// int m = (l + r) / 2;
	int m = (l + r) >> 1;

	// tree[node*2] - [l, m]
	// tree[node*2 + 1] - [m+1, r]
	if(pos <= m)
		update(node<<1, l, m, pos, v);
	else
		update(node<<1|1, m+1, r, pos, v);

	tree[node] = tree[node<<1] + tree[node<<1|1];	
}


ll get(int node, int l, int r, int lq, int rq){
	if(lq <= l && r <= rq)
		return tree[node];
	
	if(r < lq ||  l > rq)
		return 0;

	int m = (l + r) >> 1;
	return get(node<<1, l, m, lq, rq) 
			+ get(node<<1|1, m+1, r, lq, rq);
}

int main(){
	// freopen("sum.in", "r", stdin);
	// freopen("sum.out", "w", stdout);

	int n, q;
	cin >> n >> q;

	while(q--){
		char c;
		cin >> c;

		if(c == 'A'){
			int pos, val;
			cin >> pos >> val;
			--pos;

			update(1, 0, n-1, pos, val);
		}else{
			int l, r;
			cin >> l >> r;
			--l, --r;
			cout << get(1, 0, n-1, l, r) << '\n';
		}
	}


	return 0;
}
