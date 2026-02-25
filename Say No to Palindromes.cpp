/**
 *    author:  Meet
 *    created: 04.11.2025 23:28:04
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)

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

// vector<ll> arr;

// vector<string> perm = {"abc", "acb", "bac", "bca", "cab", "cba"};

// void fill(vector<ll>& dp, string& s, string& p) {
//     ll n = s.size();
//     string t;

//     for(ll i=0; i<n; ++i) {
//         t.push_back(p[0]);
//         ++i;
//         if(i < n) t.push_back(p[1]);
//         ++i;
//         if(i < n) t.push_back(p[2]);
//     }
//     for(ll i=0; i<n; ++i) {
//         dp[i+1] = dp[i] + (s[i] != t[i]);
//     }
// }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n,m;
        cin >> n >> m;
        string s;
        cin >> s;

        // vector<ll> dp1(n+1,0), dp2(n+1,0), dp3(n+1,0), dp4(n+1,0), dp5(n+1,0), dp6(n+1,0);
        // fill(dp1,s,perm[0]);
        // fill(dp2,s,perm[1]);
        // fill(dp3,s,perm[2]);
        // fill(dp4,s,perm[3]);
        // fill(dp5,s,perm[4]);
        // fill(dp6,s,perm[5]);

        vector<vector<ll>> dp(6, vector<ll>(n+1,0));

        string t = "abc";
        ll curr = 0;
        do {
            for(ll i=0; i<n; ++i) {
                dp[curr][i+1] = dp[curr][i] + (s[i] != t[i%3]);
            }
            ++curr;

        }while(next_permutation(whole(t)));

        while(m--) {
            ll l,r;
            cin >> l >> r;

            ll ans = INF;
            for(ll i=0; i<6; ++i) {
                ans = min(ans, dp[i][r] - dp[i][l-1]);
            }

            cout << ans << "\n";
        }
    }
    return 0;
}