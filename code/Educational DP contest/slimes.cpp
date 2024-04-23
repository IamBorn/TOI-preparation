#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

ll dp[405][405];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector<ll> a(n+1);
  for(int i = 1; i <= n; i++) cin >> a[i];

  vector<ll> qs(n+1, 0);
  for(int i = 1; i <= n; i++){
    qs[i] = qs[i-1] + a[i];
    dp[i][i] = a[i];
  }

  for(int i = n; i > 0; i--){
    for(int j = i; j <= n; j++){
      if(i == j){
        dp[i][j] = 0;
      }
      else{
        ll mn = INT64_MAX;
        for(int k = i; k < j; k++){
          mn = min(mn, dp[i][k] + dp[k+1][j] + qs[j] - qs[i-1]);
        }
        dp[i][j] = mn;
      }
    }
  }

  cout << dp[1][n];
  return 0;
}