#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll MINF = -1e18;
const ll M = 1e9 + 7;
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
ll n,x;
vector<ll> arr;

ll sumof(ll j, ll i) {
    ll tot = i*(i+1)*(2*i+1)/6;
    ll ext = j*(j-1)*(2*j-1)/6;
    return tot - ext;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ll dup = n;
        ll i = 1;
        while((n - i) > 0) {
            n -= i;
            ++i;
        }
        --i;
        ll l = n, r = n;
        ll ans = dup*dup;
        while(i >= 1) {
            l = max(l-1,1LL);
            r = min(r,i);
            ll numL = i*(i-1)/2 + l;
            ll numR = i*(i-1)/2 + r;
            ll curr = sumof(numL,numR);
            ans += curr;
            --i;
        }
        cout << ans << "\n";
    }
    return 0;
}