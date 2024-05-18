// source : 
// status : complete
// date : 26/4/2024
// problem tags : greedy, dfs

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int MxN = 1e5+5;

ll dp[MxN];
vector<ll> a;
vector<vi> adj;
bool isV[MxN];
ll ans = 0;

void dfs(int i){
  if(isV[i]) return;

  isV[i] = true;
  vector<ll> t;
  ll cnt = 0;
  ll l = 1;
  for(auto j : adj[i]){
    if(isV[j]) continue;

    dfs(j);
    l = lcm(l, dp[j]);
    t.push_back(a[j]);
    cnt += (adj[j].size() < 2);
  }
  if(t.empty()) return;

  ll mn = LLONG_MAX;
  for(auto it : t) mn = min(mn, it);

  if(l == 0) l = 1;
  ll x = (mn / l) * l;
  for(auto it : t){
    ans += it - x;
  }
  l *= (t.size());
  dp[i] = l;
  a[i] = x*t.size();
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  adj.resize(n);
  a.resize(n);
  for(auto& it : a) cin >> it;
  int x, y;
  for(int i = 0; i < n-1; i++){
    cin >> x >> y;
    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }
  for(int i = 0; i < n; i++){
    dp[i] = (a[i] != 0);
  }
  dfs(0);
  cout << ans;
  return 0;
}