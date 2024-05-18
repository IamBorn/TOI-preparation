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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n, k, t;
  cin >> n >> k >> t;

  vector<ll> a(n);
  vector<int> li(n);
  for(auto &it : a) cin >> it;

  for(int i = 0; i < n; i++){
    map<int, int> ma;
    int cnt = 0;
    int j;
    for(j = 0; cnt < t && j < n; j++){
      int ji = (j + i) % n;
      ma[a[ji]]++;
      if(ma[a[ji]] == 1) cnt++;
    }
    if(j == n){
      cout << 1;
      return 0;
    }

    li[i] = (i+j) % n;
  }
  return 0;
}