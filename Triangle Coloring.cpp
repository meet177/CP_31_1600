#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll MINF = -1e18;
// const ll M = 1e9 + 7;
const ll M = 998244353;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()
#define count_bits(x) 64 - __builtin_clzll(x);
#define set_bits(x) __builtin_popcountll(x);

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define minus cout << -1 << "\n"

vector<vector<ll>> graph;
vector<bool> vis;
ll t = 1;
ll n,m,q,x,k,u,v;
vector<ll> arr;

ll binExp(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}

ll comb(ll n, ll r) {
    ll num = 1, den = 1;
    for(ll i=0; i<r; i++) {
        num = (num * (n-i)) % M;
        den = (den * (i+1)) % M;
    }
    ll ans = (num * binExp(den,M-2)) % M;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // cin >> t;
    while(t--) {
        cin >> n;
        arr.assign(n,0);
        for(ll i=0; i<n; i++) cin >> arr[i];
        ll ans = comb(n/3,n/6);
        for(ll i=0; i<n; i+=3) {
            vector<ll> curr = {arr[i], arr[i+1], arr[i+2]};
            sort(whole(curr));
            if(curr[0] == curr[2]) {
                ans = (ans * 3) % M;
            }else if(curr[0] == curr[1]) {
                ans = (ans * 2) % M;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}