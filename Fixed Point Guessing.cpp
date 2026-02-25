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

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ll l = 1, r = n;
        ll cnt = 0;
        while(l < r) {
            ll mid = (l+r)/2;
            cout << "? " << l << " " << mid << "\n";
            cnt = 0;
            for(ll i=0; i<(mid-l+1); i++) {
                cin >> x;
                if(x >= l && x <= mid) ++cnt;
            }
            if(cnt & 1) r = mid;
            else l = mid+1;
        }
        cout << "! " << l << "\n";
    }
    return 0;
}