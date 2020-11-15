#include <bits/stdc++.h>
using namespace std;
int p[100001],d[1000001];
multiset< int > s;
int find_set(int i){
  while(i != p[i])
    i = p[i];
  return i;
}
void union_set( int a, int b){
  int A = find_set(a);
  int B = find_set(b);
  if(p[B] != p[A]){
    s.erase( s.find( d[ A ] ) );
    s.erase( s.find( d[ B ] ) );
    s.insert( d[A] + d[B] );
    p[B] = A;
    d[a] += d[b];
  }
}
int main() {
  int n, q, a, b;
  cin >> n >> q;
  for( int i = 1; i <= n; i++){
    p[i] = i;
    d[i] = 1;
    s.insert( d[i] );
  }
  for( int i = 1; i <= q; i++){
    cin >> a >> b;
    union_set( a, b );
    set< int > :: iterator  mn, mx;
    mn = s.begin();
    mx = s.end();
    mx --;
    cout << *mx - *mn << endl;
  }
}