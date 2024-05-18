// source : https://atcoder.jp/contests/dp/tasks/dp_s

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 1e17;
const int MOD = 1e9+7;

ll dp[10005][105][2];

ll f(string& lim, int n, int sum, bool tight, int d)
{
  if(n == 0){
    return (sum == 0);
  }

  if(dp[n][sum][tight] != -1) return dp[n][sum][tight];

  int ub = tight ? (lim[lim.length() - n] - '0') : 9;
  ll ans = 0;
  for(int i = 0; i <= ub; i++){
    ans += (f(lim, n-1, (sum+i) % d, tight&&(i==ub), d) % MOD);
    ans %= MOD;
  }
  return dp[n][sum][tight] = ans;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  string k;
  int d;
  cin >> k >> d;
  memset(dp, -1, sizeof(dp));
  ll ans = f(k, k.length(), 0, true, d);
  cout << ((ans-1) % MOD + MOD) % MOD;
  return 0;
}