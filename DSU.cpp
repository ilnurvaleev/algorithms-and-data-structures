#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>


using namespace std;

struct DSU{
    int n;
    vector<int> parent;
    vector<int> rang;

    DSU(int n){
        this->n = n;

        parent.assign(n, -1);
        for(int i = 0; i < n; ++i)
            parent[i] = i;
        rang.assign(n, 1);
    }

    int get(int x){
        if(parent[x] == x)
            return x;

        parent[x] = get(parent[x]);
        return parent[x];
    }

    void merge(int x, int y){
        x = get(x);
        y = get(y);

        if(x == y)
            return;

        if(rang[x] < rang[y])
            swap(x, y);

        parent[y] = x;
        rang[x] = max(rang[x], rang[y] + 1);
    }
};

int main() {

    return 0;
}

