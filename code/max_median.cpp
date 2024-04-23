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

  int n, k;
  cin >> n >> k;
  vi a(n);
  for(auto& it : a) cin >> it;

  ll l = 1;
  ll r = n+1;
  while(r - l > 1){
    ll m = (l + r) / 2;
    vi b(n);
    for(int i = 0; i < n; i++){
      if(a[i] >= m){
        b[i] = 1;
      }
      else{
        b[i] = -1;
      }
    }
    for(int i = 1; i < n; i++){
      b[i] += b[i-1];
    }
    int mx = b[k-1];
    int mn = 0;
    for(int i = k; i < n; i++){
      mn = min(mn, b[i-k]);
      mx = max(mx, b[i] - mn);
    }

    if(mx > 0){
      l = m;
    }
    else{
      r = m;
    }
  }
  cout << l;
  return 0;
}