/**
 *    author:  Meet
 *    created: 23.02.2026 15:11:56
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

const ll N = 1010;
ll dp[N][N][2];

// ll rec(ll i, ll k, ll dir, ll n) {
//     if(i == 0 || i == n+1 || k == 1) {
//         return 1;
//     }

//     if(dp[i][k][dir] != -1) return dp[i][k][dir];

//     ll ans = 0;

//     if(dir == 0) {
//         ans = (rec(i-1, k, 0, n)%M + rec(i+1, k-1, 1, n)%M) % M;
//     }else {
//         ans = (rec(i+1, k, 1, n)%M + rec(i-1, k-1, 0, n)%M) % M;
//     }

//     return dp[i][k][dir] = ans;
// }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n,k;
        cin >> n >> k;

        memset(dp, -1, sizeof(dp));

        // cout << rec(1, k, 1, n) << "\n";

        for(ll i=0; i<=n+1; ++i) {
            for(ll d=0; d<2; ++d) dp[i][1][d] = 1;
        }

        for(ll x=1; x<=k; ++x) {
            dp[0][x][0] = dp[0][x][1] = 1;
            dp[n+1][x][0] = dp[n+1][x][1] = 1;
        }

        for(ll x=2; x<=k; ++x) {

            for(ll i=1; i<=n; ++i) {
                dp[i][x][0] = (dp[i-1][x][0] + dp[i+1][x-1][1]) % M;
            }

            for(ll i=n; i>=1; --i) {
                dp[i][x][1] = (dp[i+1][x][1] + dp[i-1][x-1][0]) % M;
            }

        }

        cout << dp[1][k][1] << "\n";
    }
    return 0;
}