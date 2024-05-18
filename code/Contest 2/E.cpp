// source : 

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 1e17;
const int MOD = 1e9+7;

void solve(){
  int n;
  cin >> n;
  int a[105][105];
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> a[i][j];
    }
  }

  vi row;
  vi col;
  for(int i = 1; i <= n; i++){
    set<int> r;
    set<int> c;
    for(int j = 1; j <= n; j++){
      r.insert(a[i][j]);
      c.insert(a[j][i]);
    }
    if(r.size() == n){
      row.push_back(i);
    }
    if(c.size() == n){
      col.push_back(i);
    }
  }
  cout << max(row.size(), col.size()) << "\n";

  int k;
  for(k = 0; k < min(row.size(), col.size()); k++){
    int temp = (a[row[k]][col[k]] == 1) ? 2 : 1;
    cout << row[k] << " " << col[k] << " " << temp << "\n";
  }

  if(k < row.size()){

  }
  else if(k < col.size()){
    
  }
  return;
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