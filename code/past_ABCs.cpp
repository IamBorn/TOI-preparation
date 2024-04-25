// source : https://atcoder.jp/contests/abc350/tasks/abc350_a
// status : done
// date : 25/4/2024
// problem tags : string

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
  
  string s;
  cin >> s;
  string temp = s.substr(3);
  int a = stoi(temp);
  if(a <= 349 && a > 0 && a != 316) cout << "Yes";
  else cout << "No";
  return 0;
}