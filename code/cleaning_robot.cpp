// https://www.spoj.com/problems/CLEANRBT/

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int dist[12][12];
vector<pii> dirty;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int w, h;
  cin >> w >> h;
  string s[25];
  int x, y;
  for(int i = 0; i < h; i++){
    cin >> s[i];
    for(int j = 0; j < w; j++){
      if(s[i][j] == 'o'){
        x = i;
        y = j;
      }
      else if(s[i][j] == '*'){
        dirty.push_back({i, j});
      }
    }
  }

  return 0;
}