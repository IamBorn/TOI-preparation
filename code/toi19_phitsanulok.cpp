// source : https://programming.in.th/tasks/toi19_phitsanulok
// status : incomplete
// date : 25/4/2024
// problem tags : bitmask, dp, graph

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
  
  int n, s;
  cin >> n >> s;
  vi med[(1 << s)];
  vi poi[(1 << s)];
  for(int i = 0; i < n; i++){
    int me = 0;
    int po = 0;
    int in;
    for(int j = 0; j < s; j++){
      cin >> in;
      
      if(in > 0){
        me |= (1 << in);
      }
      else if(in < 0){
        po |= (1 << in);
      }
    }
    med[me].push_back(in);
    poi[po].push_back(in);
  }

  auto f = [&](int v){
    
  };
  return 0;
}