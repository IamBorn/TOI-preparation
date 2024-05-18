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

void init(string a, string b);
int get_distance(int x, int y);

int psa[100005][3]; // A = 0, T = 1, C = 2
int psb[100005][3];
int diff[100005];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  init("ATACAT", "ACTATA");
  cout << get_distance(3, 5);
  return 0;
}

void init(string a, string b){
  int n = a.size();
  a = " " + a;
  b = " " + b;
  for(int i = 1; i <= n; i++){
    diff[i] = diff[i-1] + (a[i] != b[i]);
  }

  for(int i = 1; i <= n; i++){
    if(a[i] == 'A'){
      psa[i][0] = psa[i-1][0]+1;
      psa[i][1] = psa[i-1][1];
      psa[i][2] = psa[i-1][2];
    }
    else if(a[i] == 'T'){
      psa[i][0] = psa[i-1][0];
      psa[i][1] = psa[i-1][1]+1;
      psa[i][2] = psa[i-1][2];
    }
    else{
      psa[i][0] = psa[i-1][0];
      psa[i][1] = psa[i-1][1];
      psa[i][2] = psa[i-1][2]+1;
    }

    if(b[i] == 'A'){
      psb[i][0] = psb[i-1][0]+1;
      psb[i][1] = psb[i-1][1];
      psb[i][2] = psb[i-1][2];
    }
    else if(b[i] == 'T'){
      psb[i][0] = psb[i-1][0];
      psb[i][1] = psb[i-1][1]+1;
      psb[i][2] = psb[i-1][2];
    }
    else{
      psb[i][0] = psb[i-1][0];
      psb[i][1] = psb[i-1][1];
      psb[i][2] = psb[i-1][2]+1;
    }
  }
}

int get_distance(int x, int y){
  x++;
  y++;
  int numAa = psa[y][0] - psa[x-1][0];
  int numTa = psa[y][1] - psa[x-1][1];
  int numCa = psa[y][2] - psa[x-1][2];

  int numAb = psb[y][0] - psb[x-1][0];
  int numTb = psb[y][1] - psb[x-1][1];
  int numCb = psb[y][2] - psb[x-1][2];
  if((numAa != numAb) || (numTa != numTb) || (numCa != numCb)) return -1;

  return diff[y] - diff[x-1] - 1;
}