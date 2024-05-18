// source : https://cses.fi/problemset/task/1097

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 1e17;
const int MOD = 1e9+7;

ll dp[5005][5005];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  for(ll &it : a){
    cin >> it;
    sum += it;
  } 

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

  cout << (sum + dp[0][n-1]) / 2;
  return 0;
}