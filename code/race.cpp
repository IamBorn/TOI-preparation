// source : https://usaco.org/index.php?page=viewproblem2&cpid=989

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 2e9+7;
const int MOD = 1e9+7;

int solve(int k, int mxspeed){
  int ans = 0;
  int spdist = 0;
  int sldist = 0;
  for(int cur = 1; ; cur++){
    spdist += cur;
    ans++;
    if(spdist + sldist >= k) return ans;

    if(cur >= mxspeed){
      sldist += cur;
      ans++;

      if(spdist + sldist >= k) return ans;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("race.in", "r", stdin);
  freopen("race.out", "w", stdout);
  
  int k, n;
  cin >> k >> n;
  int in;
  for(int i = 0; i < n; i++){
    cin >> in;
    cout << solve(k, in) << "\n";
  }
  return 0;
}