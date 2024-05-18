// source : 

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const ll INF = 1e17;
const int MOD = 1e9+7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> adj(n);
  ll u, v, t;
  for(int i = 0; i < m; i++){
    cin >> u >> v >> t;
    adj[--u].push_back({--v, t});
    adj[v].push_back({u, t});
  }

  vector<ll> dist1(n, INF);
  vector<ll> dist2(n, INF);
  vi par(n, -1);
  queue<pair<ll, ll>> q;
  q.push({0, 0});
  dist1[0] = 0;
  while(!q.empty()){
    auto [u, d] = q.front();
    q.pop();
    if(d > dist1[u]){
      continue;
    }

    for(auto [v, vd] : adj[u]){
      if(dist1[v] > d + vd){
        par[v] = u;
        dist1[v] = d + vd;
        q.push({v, dist1[v]});
      }
    }
  }
  if(dist1[n-1] == INF){
    cout << "-1";
    return 0;
  }

  q.push({n-1, 0});
  dist2[n-1] = 0;
  while(!q.empty()){
    auto [u, d] = q.front();
    q.pop();
    if(d > dist2[u]){
      continue;
    }

    for(auto [v, vd] : adj[u]){
      if(dist2[v] > d + vd){
        dist2[v] = d + vd;
        q.push({v, dist2[v]});
      }
    }
  }
  /*for(auto i : dist1) cout << i << " ";
  cout << "\n";
  for(auto i : dist2) cout << i << " ";
  cout << "\n";*/

  vector<bool> inS(n, false);
  int x = n-1;
  while(x != -1){
    inS[x] = true;
    //cout << x+1 << " ";
    x = par[x];
  }

  ll ans = INF;
  bool can = false;
  for(int i = 0; i < n; i++){
    for(auto [j, d] : adj[i]){
      if(inS[i] && inS[j]) continue;
      if(dist1[i] == INF || dist2[j] == INF) continue;

      ans = min(ans, dist1[i] + d + dist2[j]);
      can = true;
    }
  }
  if(!can){
    cout << "-1";
  }
  else{
    cout << ans + dist1[n-1];
  }
  return 0;
}