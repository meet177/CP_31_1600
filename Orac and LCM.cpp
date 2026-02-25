/**
 *    author:  Meet
 *    created: 25.02.2026 15:38:22
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

vector<ll> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        arr.assign(n,0);
        for(ll i=0; i<n; ++i) cin >> arr[i];
        
        map<ll, vector<ll>> mpp;

        for(auto& a : arr) {
            ll p = 0;
            while(a % 2 == 0) {
                ++p;
                a /= 2;
            }
            if(p != 0) {
                mpp[2].push_back(p);
            }

            for(ll i=3; i*i<=a; i+=2) {
                p = 0;
                while(a % i == 0) {
                    ++p;
                    a /= i;
                }
                if(p != 0) {
                    mpp[i].push_back(p);
                }
            }

            if(a > 1) {
                mpp[a].push_back(1);
            }
        }

        ll ans = 1;
        for(auto& [prime, vec] : mpp) {
            if(vec.size() < n-1) {
                continue;
            }
            ll pos = min_element(whole(vec)) - vec.begin();
            if(vec.size() == n-1) {
                ll p = vec[pos];
                for(ll i=0; i<p; ++i) ans *= prime;
            }else {
                vec.erase(vec.begin() + pos);
                pos = min_element(whole(vec)) - vec.begin();
                ll p = vec[pos];
                for(ll i=0; i<p; ++i) ans *= prime;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}