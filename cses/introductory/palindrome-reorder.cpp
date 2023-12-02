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
 

void solve() {
    ll n = 0, idx = -1;
    string s;
    vector<pair<char, ll>> v;
    cin >> s;
    for (char c : s) {
        bool b = false;
        forn (i, (int)v.size()) { 
            if (v[i].fi == c) {
                b = true;
                v[i].se++; 
                break;
            }
        }
        if (!b) v.pb(mp(c, 1));
    }
    //for (pair p : v) cout << p.fi << " " << p.se << ln;
    forn (i, (int)v.size()) 
        if (v[i].se % 2) {
            n++;
            idx = i;
        }
    if (n < 2) {
        forn (i, (int)v.size()) if (i != idx) forn (j, v[i].se / 2) cout << v[i].fi;
        if (idx >= 0) forn(i, v[idx].se) cout << v[idx].fi;
        rforn (i, (int)v.size() - 1) if (i != idx) forn (j, v[i].se / 2) cout << v[i].fi;
        cout << ln;
    } else cout << "NO SOLUTION" << ln;
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