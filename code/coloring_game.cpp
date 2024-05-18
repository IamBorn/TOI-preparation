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

void solve(){
  int n;
  string s;
  cin >> n >> s;
  
  int r = 0, b = 0;
  for(int i = 0; i < n; i++){
    if(s[i] == 'R') r++;
    else b++;
  }
  if(r > b) cout << "Alice\n";
  else if(b > r) cout << "Bob\n";
  else{
    
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}