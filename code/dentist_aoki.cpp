// source : https://atcoder.jp/contests/abc350/tasks/abc350_b
// status : complete
// date : 25/4/2024
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
  
  int n, q;
  cin >> n >> q;
  vector<int> a(n+1, 1);
  for(int i = 0; i < q; i++){
    int in;
    cin >> in;
    if(a[in] == 1){
      a[in] = 0;
    }
    else{
      a[in] = 1;
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++){
    ans += a[i];
  }

  cout << ans;
  return 0;
}