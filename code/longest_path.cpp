#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int x, y;
  vector<vi> adj(n);
  vi par(n, 0);
  for(int i = 0; i < m; i++){
    cin >> x >> y;
    adj[--x].push_back(--y);
    par[y]++;
  }
  vi dist(n, INT_MAX);
  queue<pii> q;
  for(int i = 0; i < n; i++){
    if(par[i] == 0){
      dist[i] = 0;
      q.push({0, i});
    }
  }
  while(!q.empty()){
    auto [di, ui] = q.front();
    q.pop();

    if(di < dist[ui]) continue;

    for(auto vi : adj[ui]){
      if(dist[vi] < di+1 || dist[vi] == INT_MAX){
        q.push({dist[vi] = di+1, vi});
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(dist[i] != INT_MAX){
      ans = max(ans, dist[i]);
    }
  }

  cout << ans;
  return 0;
}