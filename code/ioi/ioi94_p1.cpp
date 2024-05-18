// source : https://dmoj.ca/problem/ioi94p1

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
  cin >> n;
  int a[n][n] = {};
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= i; j++){
      cin >> a[i][j];
    }
  }

  
  for(int i = n-2; i >= 0; i--){
    for(int j = 0; j <= i; j++){
      a[i][j] += max(a[i+1][j], a[i+1][j+1]);
    }
  }
  cout << a[0][0];
  return 0;
}