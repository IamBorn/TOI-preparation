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

map<vi, int[20]> dp[2];
map<vi, int[20]> pass[2];

ll f(string& lim, int n, vi a, bool tight){
  if(n == 0){
    for(int i = 0; i <= 9; i++){
      if(a[i] == 0){
        return 0;
      }
    }
    return 1;
  }
  //cout << n << " " << tight << "\n";
  

  if(pass[tight][a][n]){
    return dp[tight][a][n];
  }

  int ub = tight ? (lim[(lim.length() - n)] - '0') : 9;
  ll ans = 0;
  if(n != lim.length()){
    a[0]--;
    ans += f(lim, n-1, a, 0);
    a[0]++;
  }
  for(int i = 1; i <= ub; i++){
    a[i]--;
    ans += f(lim, n-1, a, (tight&(i == ub)));
    a[i]++;
  }
  pass[tight][a][n] = true;
  //cout << ans << "\n";
  return dp[tight][a][n] = ans;
}

ll brute(ll l, ll r, vi a){
  ll ans = 0;
  for(int i = l; i <= r; i++){
    vi temp = a;
    string s = to_string(i);
    for(auto j : s){
      temp[j-'0']--;
    }
    bool can = true;
    for(auto j : temp){
      if(j == 0){
        can = false;
        break;
      }
    }
    if(can){
      ans++;
    }
  }
  return ans;
}

void solve(){
  pass[0].clear();
  pass[1].clear();
  ll l, r;
  cin >> l >> r;
  vi a(10);
  for(int i = 0; i <= 9; i++) cin >> a[i];

  string rs = to_string(r);
  ll res = f(rs, rs.length(), a, 1);
  pass[0].clear();
  pass[1].clear();
  string ls = to_string(l-1);
  ll les = f(ls, ls.length(), a, 1);
  cout << res - les << "\n";
  //cout << brute(l, r, a) << "\n";
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