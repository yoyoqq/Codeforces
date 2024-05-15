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

void solve(){
    int n; cin >> n;
    int a[200005];
    map<int, int> mp;
    int maxx = -1e9;
    for (int i=1; i<=n; i++){
        cin >> a[i], maxx = max(maxx, a[i]), mp[a[i]]++;
    }
    if (n == 1){
        cout << 1 << nl; 
        return;
    }
    sort(a+1, a+1+n);
    // get gcd for all the array 
    int num = a[2] - a[1]; 
    for (int i=2; i<=n; i++){
        num = gcd(num, a[i] - a[1]);
    } 
    // count all with gcd 
    int ans = 0;
    for (int i=1; i<=n; i++){
        ans += (maxx-a[i])/num;
    }
    // incrase for X
    int cnt = 0;
    while (mp[maxx]){
        maxx -= num;
        cnt++;
    }
    cout << ans + cnt << nl;

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test = 1e9; cin >> test;
    while (test--) solve();
    return 0;
}

/*



*/