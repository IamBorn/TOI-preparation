// source : https://codeforces.com/problemset/problem/1955/G
// status : complete
// date : 24/4/2024
// problem tags : dp, dfs, math, number theory

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int MxN = 105;

void solve(){
  int n, m;
  cin >> n >> m;
  int a[MxN][MxN];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }

  int g = __gcd(a[0][0], a[n-1][m-1]);
  int ii[2] = {1, 0};
  int jj[4] = {0, 1};
  vector<int> cand;
  for(int k = 1; k*k <= g; k++){
    if(g % k > 0) continue;

    cand.push_back(k);
    cand.push_back(g/k);
  }

  sort(all(cand));
  int si = cand.size();
  for(int i = si-1; i >= 0; i--){
    int k = cand[i];
    bool b[MxN][MxN];
      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
          b[i][j] = (a[i][j] % k == 0);
        }
      }

      stack<pii> s;
      s.push({0, 0});
      b[0][0] = false;
      while(!s.empty()){
        auto [x, y] = s.top();
        s.pop();
        for(int l = 0; l < 2; l++){
          int xi = x + ii[l];
          int yi = y + jj[l];

          if(xi >= n|| yi >= m) continue;
          else{
            if(b[xi][yi]){
              s.push({xi, yi});
              b[xi][yi] = false;
            } 
          }
        }
      }
      if(!b[n-1][m-1]){
        cout << k << '\n';
        return;
      }
  }
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