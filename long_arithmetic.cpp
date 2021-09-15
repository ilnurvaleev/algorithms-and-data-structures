#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define pb push_back
#define len(a) (ll)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

// #define f first
// #define s second

#define yes "Yes"
#define no "No"

#define Pll pair<ll, ll>
#define Pld pair<ld, ld>

const int block = 17;

string NumToString(ll a){
    string s = "";
    while(a){
        s += (a%10 + '0');
        a /= 10;
    }

    reverse(all(s));
    return s;
}


struct Number{
    vector < ll > a;
    bool flag;

    Number(){
        this->flag = false;
        this->a.assign(1, 0);
    }

    Number(string s){
        this->flag = (s[0] == '-');

        this->a.assign((len(s) + block - 1) / block, 0);

        reverse(all(s));

        ll tmp = 0;
        ll j = 0;
        ll step = 1;
        for(int i = 0; i < len(s); ++i){
            if(tmp + (s[i] - '0')*step < (ll)(1e17)){
                tmp = tmp + (s[i] - '0')*step;
                step *= 10;
                continue;
            }
            this->a[j] = tmp;
            ++j;
            step = 10;
            tmp = s[i]-'0';
        }

        if(tmp > 0){
            this->a[j] = tmp;
            tmp = 0;
            ++j;
        }

        // reverse(all(this->a));
    }

    string print(){
        string tmp = "";
        reverse(all(this->a));
        for(auto i : this->a)
            tmp += NumToString(i);
        reverse(all(this->a));
        if(flag)
            return "-"+tmp;
        return tmp;
    }

    Number operator+= (Number b){
        if(len(b.a) > len(this->a)){
            for(int i = 0; i < len(b.a) - len(this->a); ++i)
                this->a.pb(0);
        }

        if(len(b.a) < len(this->a)){
            for(int i = 0; i < len(this->a) - len(b.a); ++i)
                b.a.pb(0);
        }

        for(int i = 0; i < len(this->a); ++i){
            if(this->a[i] + b.a[i] > (ll)(1e17)){
                this->a[i+1] += (this->a[i] + b.a[i]) / ((ll)(1e17));
                this->a[i] = (this->a[i] + b.a[i]) % ((ll)(1e17));
            }else{
                this->a[i] = (this->a[i] + b.a[i]) % ((ll)(1e17));
            }
        }

        return *this;
    }

    Number operator+ (Number b){
        if(b.flag != this->flag){
            if(flag){

            }else{

            }
            return Number("0");
        }


        if(len(b.a) > len(this->a)){
            for(int i = 0; i < len(b.a) - len(this->a); ++i)
                this->a.pb(0);
        }

        if(len(b.a) < len(this->a)){
            for(int i = 0; i < len(this->a) - len(b.a); ++i)
                b.a.pb(0);
        }

        // cout << "check " << b.print() << endl;
        Number c;

        if(b.flag){
            c.flag = true;
        }

        c.a.assign(max(len(b.a) + 1, len(this->a) + 1), 0);
        for(int i = 0; i < len(this->a); ++i){
            // if(this->a[i] + b.a[i] + c.a[i] > (ll)(1e17)){
            c.a[i+1] += (this->a[i] + b.a[i] + c.a[i]) / ((ll)(1e17));
            c.a[i] = (this->a[i] + b.a[i] + c.a[i]) % ((ll)(1e17));
            // }else{
            // 	c.a[i] = (this->a[i] + b.a[i] + c.a[i]) % ((ll)(1e17));
            // }
        }

        return c;
    }

    bool operator< (Number b){
        string tmp1, tmp2;
        tmp1 = print();
        tmp2 = b.print();

        if(tmp1[0] == '-' and tmp2[0] == '-'){
            if(len(tmp1) == len(tmp2)){
                return (tmp1 > tmp2);
            }else if(len(tmp1) < len(tmp2)){
                return false;
            }else{
                return true;
            }
        }else if(tmp1[0] == '-' and tmp2[0] != '-'){
            return true;
        }else if(tmp1[0] != '-' and tmp2[0] == '-'){
            return false;
        }else{
            if(len(tmp1) == len(tmp2))
                return (tmp1 < tmp2);
            else if(len(tmp1) < len(tmp2))
                return true;
            else if(len(tmp1) > len(tmp2))
                return false;
        }
    }

    Number operator-= (Number b){
        if(b < *this){
            
        }else{

        }
    }
};


// a - b and a > b
Number substruct(Number a, Number b){

    for(int i = 0; i < len(a.a) - len(b.a); ++i)
        b.a.pb(0);


    Number c("0");
    c.a.assign(max(len(b.a) + 1, len(a.a) + 1), 0);

    for(int i = 0; i < len(a.a); ++i){
        if(a.a[i] - b.a[i] + c.a[i] < 0){
            c.a[i] = (ll)(1e17) - a.a[i] - b.a[i] + c.a[i];
            c.a[i+1] -= 1;
        }else{
            c.a[i] = a.a[i] - b.a[i] + c.a[i];
        }
    }
    return c;
}

void solve(){
    string s, t;
    cin >> s;
    cin >> t;
    Number a(s);
    Number b(t);

    return;
}



int main(){
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
