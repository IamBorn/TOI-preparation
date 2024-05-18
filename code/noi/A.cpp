// source : 
// status : incomplete
// date : 
// problem tags : 

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
  
  int n, a, b;
  cin >> n >> a >> b;
  vector<pii> diff(n);
  vi ai(n);
  vi bi(n);
  for(int i = 0; i < n; i++){
    cin >> ai[i];
  } 
  int in;
  for(int i = 0; i < n; i++){
    cin >> bi[i];
    diff[i].first = ai[i] - bi[i];
    diff[i].second = i;
  }

  sort(all(diff));
  int ans = 0;
  for(int i = 0; i < b; i++){
    ans += bi[diff[i].second];
  }
  for(int i = b; i < n; i++){
    ans += ai[diff[i].second];
  }
  cout << ans;
  return 0;
}