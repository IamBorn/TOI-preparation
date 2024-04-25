#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = int64_t;
using pii = pair<int, int>;
using vi = vector<int>;

const int MOD = 1e9+7;
typedef vector<vector<int>> matrix;

matrix iden(int n){
  matrix ret(n, vector<int>(n));
  for(int i = 0; i < n; i++){
    ret[i][i] = 1;
  }
  return ret;
}

matrix multi(matrix a, matrix b){
  int n = a.size();
  matrix ret(n, vector<int>(n));

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < n; k++){
        ret[i][j] = (ret[i][j] + (int64_t) a[i][k] * b[k][j]) % MOD;
      }
    }
  }

  return ret;
}

matrix pow(matrix a, int64_t k){
  matrix ret = iden(a.size());
  while(k){
    if(k & 1) ret = multi(ret, a);

    a = multi(a, a);
    k /= 2;
  }

  return ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  ll k;
  cin >> n >> k;
  matrix a(n, vector<int>(n));
  matrix dp;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }
  dp = pow(a, k);

  ll sum = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      sum += dp[i][j];
      sum %= MOD;
    }
  }

  cout << sum;
  return 0;
}