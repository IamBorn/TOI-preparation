// source : https://crackncode.contest.codeforces.com/group/rn8uJP8lA7/contest/520621/attachments/download/25391/Pre_TOI_20%20(4).pdf

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 2e9+7;
const int MOD = 1e9+7;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, q;
  cin >> n >> q;
  vi a(n);
  ll sum = 0;
  for(auto& it : a){
    cin >> it;
    sum += it;
  }
  ll ans = 0;
  ll cnt = 0;
  for(int i = 0; i < n; i++){
    ans += (cnt * a[i]);
    cnt += a[i];
  }
  if(q){
    int mx = (sum/2);
    vector<int> dp(mx + 1, 0);
    vector<int> prev;
    for(int i = 0; i < n; i++){
      prev = dp;
      for(int j = 0; j <= mx - a[i]; j++){
        dp[j+a[i]] = max(prev[j+a[i]], prev[j] + a[i]);
      }
    }
    ans -= ((sum - dp[mx]) * dp[mx]);
  }

  cout << ans;
  return 0;
}