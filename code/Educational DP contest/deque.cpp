#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int MxN = 3005;

ll dp[MxN][MxN];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<ll> a(n);
  for(auto& it : a) cin >> it;

  for(int i = n-1; i >= 0; i--){
    for(int j = i; j < n; j++){
      if(i == j){
        dp[i][j] = a[i];
      }
      else{
        dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
      }
    }
  }

  cout << dp[0][n-1];
  return 0;
}