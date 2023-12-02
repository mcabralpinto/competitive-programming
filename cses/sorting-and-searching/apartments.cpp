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
    ll p, a, d, c = 0; //people, apartments, difference, count
    vll pv, av;
    cin >> p >> a >> d;
    ll k;
    forn (i, p) {cin >> k; pv.pb(k);}
    forn (i, a) {cin >> k; av.pb(k);}
    sort(all(pv));
    sort(all(av));
    ll idx = 0;
    forn (i, p) {
        //cout << i << " " << idx << " " << c << ln;
        while (idx != a ? av[idx] < pv[i] - d : false) idx++;
        if (idx == a) break;
        if (abs(av[idx] - pv[i]) <= d) {c++; idx++;}
    }
    cout << c << ln;

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