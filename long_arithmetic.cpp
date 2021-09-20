#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;



struct long_arif {
    vector<int> a;
    bool znak = false;
    ll size_tmp = (unsigned long)(1e+5);

    long_arif(){
        // a.resize(size_tmp + 1, 0);
        a.assign(size_tmp+1, 0);
    }

    void  init(string s){
        a[0] = (ll)s.size();

        for(int i = 1; i <= a[0]; ++i){
            a[a[0] - i + 1] = s[i - 1] -'0';
        }
    }

    void add(long_arif b) {
        vector<int> c(1e+5 + 1, 0);
        c[0] = max(a[0], b.a[0]);

        for(int i = 1; i <= c[0]; ++i){
            c[i] = a[i] + b.a[i] + c[i];
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }

        if(c[c[0] + 1] != 0)
            ++c[0];

        a = c;
    }



    int complong(long_arif b){
        if(b.a[0] > a[0])
            return 1;

        if(b.a[0] < a[0])
            return -1;

        for(int i = a[0]; i > 0; --i){
            if(b.a[i] > a[i])
                return 1;
            if(b.a[i] < a[i])
                return -1;
        }
        return 0;
    }

    void multiplication_int(int b){

        int c = 0;
        for (int i = 1; i <= a[0]; ++i){
            a[i] = a[i] * b + c;

            c = a[i] / 10;
            a[i] = a[i] % 10;
        }

        while(c > 0){
            a[0] = a[0]+1;
            a[a[0]] = c % 10;
            c = c / 10;
        }

        while(a[a[0]] == 0 && a[0] > 1)
            --a[0];


    }

    void minus(long_arif b){

        vector<int> mx, mn;
        if(complong(b) == 1){
            mx = b.a;
            mn = a;
            znak = true;
        }else if(complong(b) == -1){
            mx = a;
            mn = b.a;
            znak = false;
        }else{
            znak = false;
            a[0] = 1;
            for(int i = 1; i <= size_tmp; ++i)
                a[i] = 0;
            return;
        }

        vector<int> c(size_tmp + 1, 0);
        c[0] = max(mx[0], mn[0]);
        int x = 0;
        for(int i = 1; i <= c[0]; ++i){
            x = x + mx[i] - mn[i] + 10;
            c[i] = x % 10;

            x = ((x < 10) ? -1:0);
        }

        while(c[c[0]] == 0 && c[0] > 1)
            --c[0];

        a = c;
    }

    void write(){
        if(znak)
            cout << "-";
        for(int i = a[0]; i > 0; --i)
            cout << a[i];
    }
};


int main() {
    int n;
    cin >> n;
    long_arif a;
    a.init("1");


    for(int i = 2; i <= n; i += 1)
        a.multiplication_int(i);


    a.write();


    return 0;
}
