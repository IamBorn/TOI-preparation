// source : 

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 2e9+7;
const int MOD = 1e9+7;

vector<vi> adj;
vector<int> dp;
vector<int> par;
vector<int> dp2;

int dfs(int i, vector<bool>& isV){
  int win = 0;
  isV[i] = true;
  for(auto j : adj[i]){
    if(isV[j]) continue;
    par[j] = i;
    win += (dfs(j, isV) == 0);
  }
  return dp[i] = win;
}

void dfs2(int i, vector<bool>& isV){
  isV[i] = true;
  for(auto j : adj[i]){
    if(isV[j]) continue;

    dp2[j] = dp[j];
    dp2[j] += ((dp2[i] - (dp[j] == 0)) == 0);
    dfs2(j, isV);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, t;
  cin >> n >> t;
  adj.resize(n+1);
  dp.resize(n+1);
  par.resize(n+1);
  dp2.resize(n+1);
  int u, v;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int st;
  cin >> st;
  vector<bool> isV(n+1);
  if(dfs(st, isV) > 0) cout << "Ron";
  else cout << "Hermione";

  cout << '\n';
  if(t > 1){
    isV.clear();
    isV.resize(n+1, false);
    dp2[st] = dp[st];
    dfs2(st, isV);
  }
  for(int i = 1; i < t; i++){
    cin >> st;
    if(dp2[st] > 0) cout << "Ron";
    else cout << "Hermione";

    cout << "\n";
  }


  return 0;
}