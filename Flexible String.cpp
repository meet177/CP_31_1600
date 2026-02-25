#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll MINF = -1e18;
const ll M = 1e9 + 7;
//const ll M = 998244353;
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
ll n,m,q,x,k,u,v;
string s,s1,s2;
vector<ll> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        cin >> s1 >> s2;
        vector<bool> flag(26,0);
        for(ll i=0; i<n; i++) {
            if(!flag[s1[i] - 'a']) {
                flag[s1[i] - 'a'] = 1;
            }
        }
        vector<ll> diffs;
        for(ll i=0; i<26; i++) {
            if(flag[i]) diffs.push_back(i);
        }
        ll ans = 0;
        if(k >= diffs.size()) {
            ans = n*(n+1)/2;
        }else {
            for(ll mask=0; mask<(1<<diffs.size()); mask++) {
                ll on = 0;
                vector<bool> have(26,0);
                for(ll i=0; i<diffs.size(); i++) {
                    if((mask >> i) & 1) have[diffs[i]] = 1, ++on;
                }
                if(on != k) continue;
                ll len = 0, currAns = 0;
                for(ll i=0; i<n; i++) {
                    if(have[s1[i] - 'a'] || s1[i] == s2[i]) {
                        ++len;
                    }else {
                        currAns += (len*(len+1))/2;
                        len = 0;
                    }
                }
                currAns += (len*(len+1))/2;
                ans = max(ans, currAns);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}