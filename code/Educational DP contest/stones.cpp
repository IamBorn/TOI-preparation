#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

bool dp[100005] = {};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;
  vi a(n+1);
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }

  for(int i = 1; i <= k; i++){
    for(int j = 1; j <= n; j++){
      if(i - a[j] < 0) continue;

      dp[i] |= (dp[i - a[j]] == 0);
    }
  }

  if(dp[k]) cout << "First";
  else cout << "Second";
  return 0;
}