// source : https://codeforces.com/contest/868/problem/F
// status : incomplete
// date : 24/4/2024
// problem tags : dp, divide and conquer

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int dp[10005][22];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k;
  cin >> n >> k;
  vi a(n+1);
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }

  dp[1][1] = 0;
  for(int i = 2; i <= n; i++){
    for(int j = n; j > 0; j--){
      int ans = INT_MAX;
      int cost = 0;
      map<int, int> ma;
      for(int k = j; k > 0; k--){
        ma[a[k]]++;
      }
    }
  }
  return 0;
}