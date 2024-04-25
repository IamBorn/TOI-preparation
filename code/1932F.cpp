// source : https://codeforces.com/problemset/problem/1932/F
// status : complete
// date : 24/4/2024
// problem tags : 

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()
#define x first
#define y second

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    vector<int> op(n + 1);
    vector<vector<int>> del(n + 1);
    for(auto &e: a) {
        cin >> e.x >> e.y;
        op[e.x]++;
        del[e.y].emplace_back(e.x);
    }
    multiset<int> cur;
    vector<int> dp(n + 1);
    for(int i = 1; i <= n; ++i){
        dp[i] = dp[i - 1];
        for(int j = 0; j < op[i]; ++j){
            cur.insert(i);
        }
        if(!cur.empty()){
            dp[i] = max(dp[i], int(dp[*cur.begin() - 1] + cur.size()));
        }
        for(int e: del[i]){
            cur.erase(cur.find(e));
        }
    }
    cout << dp[n] << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}