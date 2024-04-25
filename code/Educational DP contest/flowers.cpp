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
  int n;
  cin >> n;
  vi h(n);
  vi a(n);
  set<array<int, 2>> dp;
  for(auto& it : h) cin >> it;
  for(auto& it : a) cin >> it;
  int ans = 0;
  for(int i = 0; i < n; i++){
    auto it = dp.upper_bound({h[i], 0});
    int v = a[i];
    if(it != dp.begin()){
      it--;
      v = (*it)[1] + a[i];
    }

    auto [cur, succ] = dp.insert({h[i], v});
    ans = max(ans, v);
    vector<array<int, 2>> del;
    while(++cur != dp.end()){
      if((*cur)[1] <= v){
        del.push_back(*cur);
      }
      else{
        break;
      }
    }
    for(auto d : del){
      dp.erase(d);
    }
  }

  cout << ans;
  return 0;
}