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

const ll N = 1e3 + 1;
ll min_ops[N];

void pre_compute() {
    //min no of ops needed to make i
    min_ops[1] = 0;
    queue<ll> q;
    q.push(1);
    while(!q.empty()) {
        ll curr = q.front(); q.pop();
        for(ll x=1; x<=curr; x++) {
            ll nxt = curr + curr/x;
            if(min_ops[nxt] == -1 && nxt < N) {
                min_ops[nxt] = min_ops[curr] + 1;
                q.push(nxt);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(min_ops, -1, sizeof(min_ops));
    pre_compute();
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n,k;
        cin >> n >> k;
        vector<ll> b(n), c(n);
        for(ll i=0; i<n; i++) cin >> b[i];
        for(ll i=0; i<n; i++) cin >> c[i];
        //each time we can at max double any value so we will be having at most 20 minops for any value less than 1000
        for(ll i=0; i<n; i++) {
            b[i] = min_ops[b[i]];
        }
        //we need at most 20*1000 ops to make all same as bi not exactly k
        k = min(k, 20*1000LL);
        vector<ll> dp(k+1,0);
        for(ll i=0; i<n; i++) {
            for(ll j=k; j>=b[i]; j--) {
                dp[j] = max(dp[j], c[i] + dp[j-b[i]]);
            }
        }
        cout << dp[k] << "\n";
    }
    return 0;
}