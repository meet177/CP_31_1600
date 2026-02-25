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

vector<ll> divisors(ll n) {
    vector<ll> ans;
    for(ll i=1; i*i<=n; i++) {
        if(n % i == 0) {
            ans.push_back(i);
            if(n/i != i) ans.push_back(n/i);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> freq(26,0);
        for(ll i=0; i<n; i++) freq[s[i] - 'a']++;
        // for(auto& f : curr_freq) cout << (char)(f.second+'a') << " " << f.first << "\n";
        ll len = INF;
        string ans;
        vector<ll> divs = divisors(n);
        for(auto& div : divs) {
            //will have k characters at the end for current div
            ll k = n/div;
            if(k > 26) continue;
            vector<pair<ll,ll>> curr_freq;
            for(ll i=0; i<26; i++) {
                curr_freq.push_back({freq[i], i});
            }
            sort(whole(curr_freq), greater<pair<ll,ll>>());
            unordered_set<char> will_have;
            for(ll i=0; i<k; i++) {
                will_have.insert((char)(curr_freq[i].second + 'a'));
            }
            ll changes = 0;
            string curr = s;
            for(ll i=0; i<k; i++) {
                ll f = curr_freq[i].first;
                char ch = (char)(curr_freq[i].second + 'a');
                if(f == div) continue;
                if(f > div) {
                    for(ll j=0; j<n; j++) {
                        if(curr[j] == ch) {
                            for(ll x=i+1; x<k; x++) {
                                if(curr_freq[x].first < div) {
                                    char ch = (char)(curr_freq[x].second + 'a');
                                    curr[j] = ch;
                                    changes++;
                                    f--;
                                    curr_freq[x].first++;
                                    break;
                                }
                            }
                        }
                        if(f == div) break;
                    }
                }else {
                    for(ll j=0; j<n; j++) {
                        if(!will_have.count(curr[j])) {
                            char ch = (char)(curr_freq[i].second + 'a');
                            curr[j] = ch;
                            changes++;
                            f++;
                            curr_freq[i].first++;
                        }
                        if(f == div) break;
                    }
                }
            }
            if(changes < len) {
                len = changes;
                ans = curr;
            }
        }
        cout << len << "\n";
        cout << ans << "\n";
    }
    return 0;
}