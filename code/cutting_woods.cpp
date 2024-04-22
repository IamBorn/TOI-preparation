#include <bits/stdc++.h>

using namespace std;
#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main(){
  ll l, q;
  cin >> l >> q;
  int c, x;
  set<int> s;
  s.insert(0);
  s.insert(l);
  for(int i = 0; i < q; i++){
    cin >> c >> x;
    if(c == 1){
      s.insert(x);
    }
    else{
      auto itl = s.lower_bound(x);
      auto itr = s.upper_bound(x);
      itl--;
      cout << *itr - *itl << '\n';
      //cout << distance(itl, itr) << '\n';
    }
  }
}