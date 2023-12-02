#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int> > vv;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pii> > vvpii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<bool> vb;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
ll n, t = INF;
vll v;
//vvll memo;

void rec(ll k, ll c) {
    t = min(c, t);
    if (k != n /*|| t == 0*/) {
        if (c - v[k] >= 0) rec(k + 1, c - v[k]);
        rec(k + 1, c);
    }
}

void solve(){
    ll m, s = 0;
    cin >> n;
    forn (i, n) {
        cin >> m; 
        v.pb(m); 
        s += m;}
    //memo.resize(n + 1, vll(s + 1, 0));
    if (n > 1) {
        rec(0, s / 2);
        cout << (s & 1 ? (2 * t) + 1 : 2 * t) << ln;
    } else cout << m << ln;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}