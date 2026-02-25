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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        string s;
        ll pos;
        cin >> s >> pos;
        ll block = 0;
        ll n = s.size();
        ll curr = n;
        //O(n)
        while((pos - curr) > 0) {
            pos -= curr;
            --curr;
            ++block;
        }
        //whatever will be the block we have to remove that much from the current string in order to get the desired string
        //we are removing the block chars from string so that at the end lexicographical smallest remains this is the same as remove k digits from a number in order to get minimal expression
        unordered_set<ll> deleted_occs;
        stack<pair<char,ll>> stk;
        for(ll i=0; i<n; i++) {
            if(stk.empty()) {
                stk.push({s[i], i});
            }else {
                while(block && !stk.empty() && stk.top().first > s[i]) {
                    deleted_occs.insert(stk.top().second);
                    stk.pop();
                    --block;
                }
                stk.push({s[i], i});
            }
        }
        while(block && !stk.empty()) {
            deleted_occs.insert(stk.top().second);
            stk.pop();
            --block;
        }
        char ans;
        curr = 0;
        for(ll i=0; i<n; i++) {
            if(!deleted_occs.count(i)) {
                ++curr;
                if(curr == pos) {
                    ans = s[i];
                    break;
                }
            }
        }
        cout << ans;
    }
    return 0;
}