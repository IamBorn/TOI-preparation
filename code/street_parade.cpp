#include <bits/stdc++.h>

using namespace std;

int main(){
  int n = -1;
  while(true){
    cin >> n;
    if(n == 0) break;
    stack<int> s;

    int cnt = 1;
    int in;
    for(int i = 0; i < n; i++){
      cin >> in;
      if(in != cnt){
        while(!s.empty() && s.top() == cnt){
          s.pop();
          cnt++;
        }
        s.push(in);
      }
      else{
        cnt++;
      }
    }
    while(!s.empty() && s.top() == cnt){
      s.pop();
      cnt++;
    }

    if(s.empty()){
      cout << "yes\n";
    }
    else{
      cout << "no\n";
    }
  }
}