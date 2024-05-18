// source : https://usaco.org/index.php?page=viewproblem2&cpid=1088
// status : complete
// date : 26/4/2024
// problem tags : greedy

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
  
  int n;
  cin >> n;
  int a[n][n];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }

  int r_max = 0, c_max = 0;
  for(int i = 0; i < n; i++){
    int sum[2] = {};
    for(int j = 0; j < n; j++){
      sum[j % 2] += a[i][j];
    }
    r_max += max(sum[0], sum[1]);
  }
  for(int i = 0; i < n; i++){
    int sum[2] = {};
    for(int j = 0; j < n; j++){
      sum[j % 2] += a[j][i];
    }
    c_max += max(sum[0], sum[1]);
  }

  cout << max(r_max, c_max);
  return 0;
}