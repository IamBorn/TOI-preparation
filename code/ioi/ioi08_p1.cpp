// source : https://dmoj.ca/problem/ioi08p1

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
  vector<string> a(n);
  for(auto &it : a) cin >> it;

  sort(all(a));
  int k = -1;
  int mx = 0;
  for(int i = 0; i < n; i++){
    if(a[i].size() > mx){
      mx = a[i].size();
      k = i+1;
    }
  }
  k %= n;
  vector<char> ans;
  for(auto it : a[k]){
    ans.push_back(it);
  }
  ans.push_back('P');
  for(int l = 1; l < n; l++){
    int i = (l + k) % n;
    int sa = a[i].size();
    int sb = a[(i+n-1) % n].size();
    int sm = min(sa, sb);
    int st;
    for(st = 0; st < sm; st++){
      if(a[i][st] != a[(i+n-1) % n][st]){
        break;
      }
    }
    for(int j = st; j < sb; j++) ans.push_back('-');
    for(int j = st; j < sa; j++) ans.push_back(a[i][j]);
    
    ans.push_back('P');
  }
  cout << ans.size() << "\n";
  for(auto it : ans) cout << it << "\n";
  return 0;
}