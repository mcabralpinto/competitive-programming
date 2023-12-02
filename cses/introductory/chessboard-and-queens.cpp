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

ll w = 0;       // ways to place the queens

vvb change_board(vvb at, ll row, ll col) {
    forn (i, 8) {
        at[row][i] = false;
        at[i][col] = false;
    }
    //ll a = min(row, col), b = max(row, col);

    // direction: /.
    if (row + col <= 7) forn (i, row + col + 1) at[i][row + col - i] = false;
    else forsn (i, row + col - 7, 8) at[i][row + col - i] = false;

    // direction: \.
    if (((7 - row) + col) <= 7) forn (i, (7 - row) + col + 1) at[7 - i][(7 - row) + col - i] = false;
    else forsn (i, (7 - row) + col - 7, 8) at[7 - i][(7 - row) + col - i] = false;
    return at;
}

void nqueens(vvb at, ll row) {
    if (row == 8) w++;
    else {
        forn (i, 8) {
            if (at[row][i]) {
                nqueens(change_board(at, row, i), row + 1);
            } 
        }
    }
}

void solve(){
    string s;
    vvb at (8, vb (8, true));     // available tiles
    forn (i, 8) {
        cin >> s;
        forn (j, 8) if (s[j] == '*') at[i][j] = false;
    }
    nqueens(at, 0);
    cout << w << ln;
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