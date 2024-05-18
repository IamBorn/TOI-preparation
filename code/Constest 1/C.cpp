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
  int n, q;
  cin >> n >> q;
  //cout << n << " " << q << "\n";
  int u, v, x;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
  }
  for(int i = 0; i < q; i++){
    cin >> u >> v >> x;
  }

  int a = n - q - 1;

  //a = 4;

  if(a == 0){
    cout << "1\n";
    return;
  }
  ll ans = 2;
  int i = 1;
  while(i < a){
    ans *= 2;
    ans %= MOD;
    i++;
  }
  cout << ans << "\n";
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