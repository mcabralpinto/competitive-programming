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
typedef vector<vb> vvb;
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

ll paths = 0;
string s;

void find_paths(int idx, int x, int y) {
    if (idx < 47) {
        idx++;
        if (s[idx] == '?') {
            if (x > 1) find_paths(idx, x - 1, y);
            if (x < 7) find_paths(idx, x + 1, y);
            if (y > 1) find_paths(idx, x, y - 1);
            if (y < 7) find_paths(idx, x, y + 1);
        } else if (s[idx] == 'L') {
            if (x > 1) find_paths(idx, x - 1, y);
        } else if (s[idx] == 'R') {
            if (x < 7) find_paths(idx, x + 1, y);
        } else if (s[idx] == 'D') {
            if (y > 1) find_paths(idx, x, y - 1);   
        } else {
            if (y < 7) find_paths(idx, x, y + 1);
        }
    } else paths++;
}

void solve(){
    cin >> s;
    find_paths(0, 1, 1);
    cout << paths << ln;
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