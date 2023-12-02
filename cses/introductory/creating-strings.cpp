#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<string> vs;
typedef vector<pair<char, ll>> vpcll;
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
 
ll fact(ll n) {
    return n > 1 ? n * fact(n - 1) : 1;
}

void rec(vpcll v, string w, ll n) {
    if (n > 0) {
        string t = w;
        rforn(i, sz(v) - 1) {
            if (v[i].se > 0) {
                t = w;
                t.pb(v[i].fi);
                v[i].se--;
                rec(v, t, n - 1);
                v[i].se++;
            }
        }
    } else cout << w << ln;
}

void solve(){
    string s;
    cin >> s;
    vpcll v;
    bool b;
    for (char c : s) {
        b = false;
        ll n = sz(v);
        forn (i, n) {
            if (v[i].fi == c) {
                v[i].se++;
                b = true;
                break;
            } else if (v[i].fi < c) {
                v.insert(v.begin() + i, mp(c, 1));
                b = true;
                break;
            }
        }
        if (!b) v.pb(mp(c, 1));
    }
    //for (pair p : v) cout << p.fi << " " << p.se << ln;
    ll m = fact(sz(s));
    forn (i, sz(v)) m /= fact(v[i].se);
    cout << m << ln;
    rec(v, "", sz(s));
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