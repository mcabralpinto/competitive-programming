#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,string> pis;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int> > vv;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pii> > vvpii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<pis> vpis;
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
#define cut(str, s, e) string(str.begin() + s, str.begin() + e)

ll f = 0;
vpis v {mp(0, "zero"), mp(1, "one"), mp(2, "two"), mp(3, "three"), mp(4, "four"),
        mp(5, "five"), mp(6, "six"), mp(7, "seven"), mp(8, "eight"), mp(9, "nine")};

void solve() {
    string s;
    bool b = false;
    cin >> s;
    ll idx = 0;
    while (idx != sz(s)) {
        if (48 <= s[idx] && s[idx] <= 57) {
            //cout << (s[idx] - 48) * 10 << ln;
            f += (s[idx] - 48) * 10;
            b = true;
        } else {
            for (pis ns : v) {
                if (cut(s, idx, min(idx + sz(ns.se), sz(s) - 1)) == ns.se) {
                    //cout << ns.fi * 10 << ln;
                    f += ns.fi * 10;
                    b = true;
                    break;
                }
            }
        }
        if (b) break;
        idx++;
    }
    b = false;
    idx = sz(s) - 1;
    while (idx >= 0) {
        if (48 <= s[idx] && s[idx] <= 57) {
            //cout << (s[idx] - 48) << ln;
            f += (s[idx] - 48);
            b = true;
        } else {
            for (pis ns : v) {
                if (cut(s, max((int)(idx - sz(ns.se)) + 1, 0), idx + 1) == ns.se) {
                    //cout << ns.fi << ln;
                    f += ns.fi;
                    b = true;
                    break;
                }
            }
        }
        if (b) break;
        idx--;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case #" << it+1 << ": ";
        solve();
    }
    cout << f << ln;
    return 0;
}