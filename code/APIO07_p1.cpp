// source : https://dmoj.ca/problem/apio07p1

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 2e9+7;
const int MOD = 1e9+7;

vector<pii> adj;
vector<bool> diff;

bool f_diff(int i){
  if(adj[i].first == -1 && adj[i].second == -1) return diff[i] = false;

  if(adj[i].first == -1){
    f_diff(adj[i].second);
    return diff[i] = true;
  }

  if(adj[i].second == -1){
    f_diff(adj[i].first);
    return diff[i] = true;
  }


}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  adj.resize(n+1);
  diff.resize(n+1);
  int a, b;
  for(int i = 1; i <= n; i++){
    cin >> a >> b;
    adj[i] = {a, b};
  }

  return 0;
}