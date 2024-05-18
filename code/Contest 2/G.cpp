// source : 

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 1e17;
const int MOD = 1e9+7;

bool fast_v(string a, string b, int m, int k){
  for(int i = 0; i < m && k > 0; i++){
    if(a[i] != '.'){
      k -= (a[i] == b[i]);
    }
  }

  return (k == 0);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> s(n);
  for(auto &it : s) cin >> it;
 
  for(int i = 1; i < n; i++){
    for(int j = i-1; j >= 0; j--){
      if(fast_v(s[i], s[j], m, k)){
        cout << j+1 << " " << i+1;
        return 0;
      }
    }
  }
  cout << -1;
  return 0;
}