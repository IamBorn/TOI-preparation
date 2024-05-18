// source : https://dmoj.ca/problem/ioi00p1

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
  
  int n;
  string s;
  cin >> n >> s;
  string a = s;
  reverse(all(a));
  a = " " + a;
  s = " " + s;

  vi dp(n+1);
  vi prev;
  for(int i = 1; i <= n; i++){
    prev = dp;
    for(int j = 1; j <= n; j++){
      if(s[i] == a[j]){
        dp[j] = prev[j-1] + 1;
      }
      else{
        dp[j] = max(prev[j], dp[j-1]);
      }
    }
  }

  cout << n - dp[n];
  return 0;
}