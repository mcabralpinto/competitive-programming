#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,string> pls;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pls> vpls;
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
#define cut(str, s, f) string(str.begin() + s, str.begin() + f)
#define split(vecstr, ss, delim, tmp) while (getline(ss, tmp, delim)) vecstr.pb(tmp)


ll solve() {
    string s;
    vs u, v;
    ll r = 0, g = 0, b = 0;
    vpls w;
    getline(cin, s);
    s = cut(s, s.find(':') + 1, sz(s));
    stringstream sss(s); 
    string tmp;
    split(u, sss, ',', tmp);
    for (string a : u) {
        stringstream ass(a); 
        split(v, ass, ';', tmp);
    }
    for (string a : v) {
        vs aux;
        stringstream ass(a);
        split(aux, ass, ' ', tmp);
        w.pb(mp(stoi(aux[1]), aux[2]));
    }
    for (pls p : w) {
        //cout << p.fi << " " << p.se << ln;
        if (p.se == "red" && p.fi > r) r = p.fi;
        else if (p.se == "green" && p.fi > g) g = p.fi;
        else if (p.se == "blue" && p.fi > b) b = p.fi;
    }
    //cout << r << " " << g << " " << b << ln;
    return r * g * b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1, f = 0;
    cin >> t;
    cin.ignore();
    for(int it=1; it<=t; it++) {
     //cout << "Case #" << it+1 << ": ";
        f += solve();
    }
    cout << f << ln;
    return 0;
}