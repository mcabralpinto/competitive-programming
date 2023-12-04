#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<pll>> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<vs> vvs;
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
#define split(vecstr, ss, delim, tmp) while (getline(ss, tmp, delim)) vecstr.pb(tmp)

ll len = 140, sum = 0;

void solve() {
    vs lines;
    string line;
    forn (i, len) {
        cin >> line;
        lines.pb(line);
    }
    forn (i, len) {
        forn (j, len) {
            if (lines[i][j] == '*') {
                vll factors;
                vvb usable (len, vb(len, true));
                forsn (k, max((int)(i - 1), 0), min(i + 2, len)) {
                    forsn (l, max((int)(j - 1), 0), min(j + 2, len) && usable[k][l]) {
                        if (48 <= lines[k][l] && lines[k][l] <= 57) {
                            ll num = lines[k][l] - 48, mult = 10;
                            rforsn (m, l - 1, 0) {
                                if (48 <= lines[k][m] && lines[k][m] <= 57) {
                                    num += (lines[k][m] - 48) * mult; 
                                    mult *= 10; 
                                    usable[k][m] = false;
                                } else break; 
                            }
                            forsn (m, l + 1, len) {
                                if (48 <= lines[k][m] && lines[k][m] <= 57) {
                                    num *= 10; 
                                    num += (lines[k][m] - 48);
                                    usable[k][m] = false;
                                } else break; 
                            }
                            factors.pb(num);
                        }
                    }
                }
                if (sz(factors) == 2) sum += factors[0] * factors[1];
            }
        }
    }
    cout << sum << ln;
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