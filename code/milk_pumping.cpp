// source : https://usaco.org/index.php?page=viewproblem2&cpid=969

#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 1e17;
const int MOD = 1e9+7;

void setIO(string name = "") {

	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io

	if (sz(name)) {

		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output

		freopen((name + ".out").c_str(), "w", stdout);

	}

}

struct edge{
  int v, c, fl;
};
int n, m;

vector<vector<edge>> adj;

int dijk(int mn_flow){
  priority_queue<pii> pq;
  vi cost(n, INT32_MAX);
  cost[0] = 0;
  pq.push({0, 0});

  while(!pq.empty()){
    auto [u, d] = pq.top();
    pq.pop();

    if(d != cost[u]) continue;

    for(auto v : adj[u]){
      int ct = v.c + d;

      if(v.fl < mn_flow) continue;

      if(cost[v.v] > ct){
        cost[v.v] = ct;
        pq.push({v.v, ct});
      }
    }
  }

  return cost[n-1] == INT32_MAX ? -1 : cost[n-1];
}

int main(){
  setIO("pump");
  
  cin >> n >> m;
  adj.resize(n);
  vi flows;
  int a, b, c, f;
  for(int i = 0; i < m; i++){
    cin >> a >> b >> c >> f;

    flows.push_back(f);
    adj[--a].push_back({--b, c, f});
    adj[b].push_back({a, c, f});
  }
  int ans = 0;
  for(auto cur_f : flows){
    int temp = dijk(cur_f);
    ans = max(ans, cur_f * 1000000 / temp);
  }
  cout << ans;
  return 0;
}