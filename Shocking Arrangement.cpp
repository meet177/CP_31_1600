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
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        arr.assign(n,0);
        for(ll i=0; i<n; i++) cin >> arr[i];
        if(all_of(whole(arr), [](ll x) {return x == 0;})) {
            no;
        }else {
            yes;
            ll allowed = *max_element(whole(arr)) - *min_element(whole(arr));
            sort(whole(arr));
            ll sum = 0;
            ll i = 0, j = n-1;
            while(i <= j) {
                if(abs(sum + arr[i]) < allowed) {
                    sum += arr[i];
                    cout << arr[i] << " ";
                    ++i;
                }else {
                    sum += arr[j];
                    cout << arr[j] << " ";
                    --j;
                }
            }
            cout << "\n";
        }
    }
    return 0;
}