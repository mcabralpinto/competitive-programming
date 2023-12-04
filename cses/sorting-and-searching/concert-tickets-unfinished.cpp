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
    ll t, c;
    vll tv;         // tickets
    vpll cv;
    cin >> t >> c;
    vll pv(c, -1);  // prices
    ll k;
    forn (i, t) {cin >> k; tv.pb(k);}
    forn (i, c) {cin >> k; cv.pb(mp(k, i));}
    sort(all(tv));
    sort(all(cv));
    //forn(i, c) cout << cv[i].fi << " " << cv[i].se << ln;
    ll idx = t - 1;
    rforsn (i, c - 1, 0) {
        //cout << i << " " << idx << " " << c << ln;
        while (idx >= 0 ? tv[idx] > cv[i].fi : false) idx--;
        if (idx < 0) break;
        pv[cv[i].se] = tv[idx]; 
        idx--;
    }
    for (ll p : pv) cout << p << ln;
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