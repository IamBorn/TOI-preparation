// source : https://usaco.org/index.php?page=viewproblem2&cpid=694

#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 1e17;
const int MOD = 1e9+7;

void setIO(string name = "") {

	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io

	if (sz(name)) {

		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output

		freopen((name + ".out").c_str(), "w", stdout);

	}

}

const int mx = 1e5+5;

int dp[mx][25][3];
int a[mx];

int main(){
  setIO("hps");
  int n, k;
  cin >> n >> k;
  char in;
  for(int i = 0; i < n; i++){
    cin >> in;
    if(in == 'H'){
      a[i] = 0;
    }
    else if(in == 'P'){
      a[i] = 1;
    }
    else{
      a[i] = 2;
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j <= k; j++){
      for(int l = 0; l < 3; l++){
        if(l == a[i]) dp[i][j][l]++;

        dp[i+1][j+1][0] = max(dp[i+1][j+1][0], dp[i][j][l]);
        dp[i+1][j+1][1] = max(dp[i+1][j+1][1], dp[i][j][l]);
        dp[i+1][j+1][2] = max(dp[i+1][j+1][2], dp[i][j][l]);
        dp[i+1][j][l] = max(dp[i+1][j][l], dp[i][j][l]);
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < 3; i++){
    ans = max(ans, dp[n][k][i]);
  }
  cout << ans;
  return 0;
}