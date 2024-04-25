// source : https://atcoder.jp/contests/abc350/tasks/abc350_d
// status : complete
// date : 25/4/2024
// problem tags : 

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
  vector<vi> adj(n);
  int x, y;
  for(int i = 0; i < m; i++){
    cin >> x >> y;
    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }

  ll ans = 0;
  vector<bool> isV(n, false);
  for(int i = 0; i < n; i++){
    if(isV[i] == false){
      ll si = 0;
      stack<int> s;
      s.push(i);
      isV[i] = true;
      while(!s.empty()){
        int now = s.top();
        s.pop();
        si++;

        for(auto j : adj[now]){
          if(!isV[j]){
            s.push(j);
            isV[j] = true;
          }
        }
      }

      ans += (si * (si - 1)) / 2;
    }
  }

  ans -= m;
  cout << ans;
  return 0;
}