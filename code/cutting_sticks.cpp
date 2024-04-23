#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

vi v;
int dp[55][55];

int func(int i, int j){
  if(j - i == 1) return 0;
  if(dp[i][j] != -1){
    return dp[i][j];
  }

  int mn = INT_MAX;

  for(int k = i+1; k < j; k++){
    mn = min(func(i, k) + func(k, j) + (v[j] - v[i]), mn);
  }

  return dp[i][j] = mn;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int l = -1;
  while(true){
    cin >> l;
    if(l == 0) break;

    int n;
    cin >> n;
    v.clear();
    v.push_back(0);
    int in;
    for(int i = 0; i < n; i++){
      cin >> in;
      v.push_back(in);
    }
    v.push_back(l);
    memset(dp, -1, sizeof(dp));

    cout << func(0, n+1) << '\n';
  }

  
  return 0;
}