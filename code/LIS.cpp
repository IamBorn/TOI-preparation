// source : https://cses.fi/problemset/task/1145

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
  vi a;
  int in;
  int ans = 0;
  for(int i = 0; i < n; i++){
    cin >> in;
    auto idx = lower_bound(all(a), in);
    if(idx == a.end()){
      a.push_back(in);
      ans = max(ans, (int)a.size());
    }
    else{
      ans = max(ans, (int)(idx - a.begin()));
      *idx = in;
    }
  }
  cout << ans;
  return 0;
}