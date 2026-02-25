/**
 *    author:  Meet
 *    created: 03.11.2025 17:10:03
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

vector<ll> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        arr.assign(n,0);
        for(ll i=0; i<n; ++i) cin >> arr[i];
        
        ll mxprod = 0;
        ll l = 0, r = n;
        
        ll i = 0;
        while(i < n) {
            ll leftnegprod = -1, rightnegprod = 0;
            ll leftnegind = 0, rightnegind = 0;
            ll totalneg = 0;
            ll prod = 0;
            ll j = i;
            while(i < n && arr[i]) {
                if(abs(arr[i]) == 2) ++prod;
                if(arr[i] < 0) {
                    ++totalneg;
                    if(leftnegprod == -1) {
                        leftnegprod = prod;
                        leftnegind = i+1;
                    }
                    rightnegprod = 0;
                    rightnegind = i;
                }
                if(abs(arr[i]) == 2) ++rightnegprod;
                ++i;
            }
            
            if(totalneg & 1) {
                if((prod - leftnegprod) > mxprod) {
                    mxprod = prod - leftnegprod;
                    l = leftnegind;
                    r = n - i;
                }
                if((prod - rightnegprod) > mxprod) {
                    mxprod = prod - rightnegprod;
                    l = j;
                    r = n - rightnegind;
                }
            }else {
                if(prod > mxprod) {
                    mxprod = prod;
                    l = j;
                    r = n - i;
                }
            }
            ++i;
        }

        cout << l << " " << r << "\n";
    }
    return 0;
}