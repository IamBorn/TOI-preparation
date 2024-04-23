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

  string s, t;
  cin >> s >> t;
  int si = s.size();
  int ti = t.size();
  
  vector<vector<int>> dp(si+1, vector<int>(ti+1, 0));

  for(int i = 1; i <= si; i++){
    for(int j = 1; j <= ti; j++){
      if(s[i-1] == t[j-1]){
        dp[i][j] = dp[i-1][j-1] + 1;
      }
      else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  string ans = "";
  int i = si;
  int j = ti;
  while(i >= 1 && j >= 1){
    if(dp[i][j] == dp[i][j-1]){
      j--;
    }
    else if(dp[i][j] == dp[i-1][j]){
      i--;
    }
    else{
      i--;
      j--;
      ans += s[i];
    }
  }
  reverse(all(ans));
  cout << ans;
  return 0;
}