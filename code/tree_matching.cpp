// source : https://cses.fi/problemset/task/1130
// status : incomplete
// date : 29/4/2024
// problem tags : dp, tree

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int MxN = 2e5+5;

int dp[MxN][2];
vi adj[MxN];

void dfs(int i, int p){
  for(int j : adj[i]){
    if(j != p){
      dfs(j, i);
      dp[i][0] += max(dp[j][0], dp[j][1]);
    }
  }
  for(int j : adj[i]){
    if(j != p){
      dp[i][1] = max(dp[i][1], 
      dp[j][0] + 1 + dp[i][0] - max(dp[j][0], dp[j][1]));
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  int u, v;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }

  dfs(0, -1);
  cout << max(dp[0][0], dp[0][1]);
  return 0;
}