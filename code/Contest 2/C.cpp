// source : 

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = int64_t;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 1e17;
const int MOD = 1e9+7;

void solve(){
  int n;
  cin >> n;
  vi a(n);
  for(auto &it : a) cin >> it;

  int mx = -1;
  int idx;
  for(int i = 0; i < n; i++){
    if(a[i] >= mx){
      mx = a[i];
      idx = i;
    }
  }
  //cout << mx << "\n";

  ll mt = 1;
  for(int i = 1; i <= mx; i++){
    mt *= 2;
  }
  ll m1 = mt - 1 - idx;
  
  bool can = true;
  for(int j = 0; j < n; j++){
    ll temp = m1 + j;
    cout << temp << " ";
    if(__builtin_popcount(temp) != a[j]){
      can = false;
      break;
    }
  }
  if(idx == n-1){
    can = true;
    ll m2 = mt*2;
    m2 = m2 - 1 - idx;
    for(int j = 0; j < n; j++){
      ll temp = m2 + j;
      //cout << temp << " ";
      if(__builtin_popcount(temp) != a[j]){
        can = false;
        break;
      }
    }
  }
  if(can){
    cout << mt << "\n";
  }
  else{
    cout << "-1\n";
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