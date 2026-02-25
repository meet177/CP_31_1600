/**
 *    author:  Meet
 *    created: 03.11.2025 19:59:35
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

vector<ll> a, b;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        a.assign(n,0);
        b.assign(n,0);
        for(ll i=0; i<n; ++i) cin >> a[i] >> b[i];
        
        auto check = [&] (ll x) -> bool {
            //c is the cth poorer person we currently have then as we are selecting x persons we will have x-1-c richer persons than the current person
            ll c = 0;
            for(ll i=0; i<n; ++i) {
                if(c <= b[i] && (x-1-c) <= a[i]) {
                    ++c;
                }
            }
            return c >= x;
        };

        ll lo = 0, hi = n;
        ll ans = lo;

        //TTTTTTTTTTTFFFFFFFFFFF
        while(lo <= hi) {
            ll mid = (lo+hi)/2;
            if(check(mid)) {
                ans = mid;
                lo = mid+1;
            }else { 
                hi = mid-1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}