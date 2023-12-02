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
 
ll t = INF;
vll v;

void rec(vb u, ll c) {
    t = min(c, t);
    forn (i, sz(v)) {
        if (u[i] && c - v[i] >= 0) {
            u[i] = false;
            rec(u, c - v[i]);
            u[i] = true;
        }
    }
}

void solve(){
    ll n, m, s = 0;
    cin >> n;
    forn (i, n) {
        cin >> m; 
        v.pb(m); 
        s += m;
    }
    if (n > 1) {
        vb u(sz(v), true);
        rec(u, s / 2);
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