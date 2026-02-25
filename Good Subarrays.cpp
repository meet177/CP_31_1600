/**
 *    author:  Meet
 *    created: 23.02.2026 17:38:22
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        vector<ll> pf(n+1, 0);
        for(ll i=1; i<=n; ++i) pf[i] = pf[i-1] + (s[i-1] - '0');
        //pf[r] - pf[l-1] = r - l + 1
        //pf[r] - r = pf[l-1] - (l-1)

        //so we can start from any of the previous same pf[i] - i and end at this i, then it will be good subarray

        map<ll,ll> cnt;
        cnt[0] = 1;

        ll ans = 0;

        for(ll i=1; i<=n; ++i) {
            ans += cnt[pf[i] - i];

            ++cnt[pf[i] - i];
        }

        cout << ans << "\n";
    }
    return 0;
}