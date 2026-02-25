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
ll n,x,k;
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
    cin >> t;
    while(t--) {
        cin >> n >> k;
        arr.assign(n,0);
        for(ll i=0; i<n; i++) cin >> arr[i];
        sort(whole(arr), greater<ll>());
        ll ele = arr[k-1];
        ll i = k-1;
        while(i >= 0 && arr[i] == ele) {
            --i;
        }
        ll r = (k - 1 - i);
        ll m = 0;
        ++i;
        while(i < n && arr[i] == ele) {
            ++m;
            ++i;
        }
        cout << comb(m,r) << "\n";
    }
    return 0;
}