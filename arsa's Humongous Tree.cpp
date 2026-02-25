/**
 *    author:  Meet
 *    created: 23.02.2026 14:54:42
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)

#define ll long long int
const ll INF = 4e18;
const ll MINF = -4e18;
const ll M = 1e9 + 7;
//const ll M = 998244353;
const ll M1 = 111053273;
const ll M2 = 4011052531;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define minus cout << -1 << "\n"

vector<vector<ll>> adj;
vector<ll> l,r;
vector<vector<ll>> dp;

void dfs(ll ver, ll par) {
    for(auto& child : adj[ver]) {
        if(child == par) continue;

        dfs(child, ver);

        dp[ver][0] += max(dp[child][0] + abs(l[child] - l[ver]), dp[child][1] + abs(r[child] - l[ver]));
        dp[ver][1] += max(dp[child][0] + abs(l[child] - r[ver]), dp[child][1] + abs(r[child] - r[ver]));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        l.assign(n+1, 0);
        r.assign(n+1, 0);
        dp.assign(n+1, vector<ll>(2,0));

        for(ll i=1; i<=n; ++i) {
            cin >> l[i] >> r[i];
        }

        adj.assign(n+1, {});

        for(ll i=0; i<n-1; ++i) {
            ll u,v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, -1);

        cout << max(dp[1][0], dp[1][1]) << "\n";
    }
    return 0;
}