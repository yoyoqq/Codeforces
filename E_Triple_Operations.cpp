#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// overload cout and return pair<A, B>
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// return generic container (vector, set, list) to output stream 
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// debugging
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
// generate random num
#define rng_init mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng_seed(x) mt19937 rng(x)
// shortcuts
#define all(x) (x).begin(), (x).end()   // sort(all(a))

using ll = long long;
typedef long double ld;
const char nl = '\n';
int A[200010];

const int MAX = 200007;
int a[MAX], psum[MAX];

void solve(){
    int l, r;
    cin >> l >> r;
    // prefix + 3x used at first 
    cout << psum[r] - psum[l-1] + a[l] << endl;
    
}

int f(int num){
    int count = 0;
    while (num){
        count++;
        num /= 3;
    }
    return count;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    // save in prefix to return faster 
    psum[0] = 0;
    for (int i=1; i<MAX; i++){
        a[i] = f(i);
        psum[i] = psum[i-1] + a[i];
    }
    
    int test = 1e9; cin >> test;
    while (test--) solve();
    return 0;
}

/*



*/