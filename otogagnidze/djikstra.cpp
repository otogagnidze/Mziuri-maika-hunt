#include <bits/stdc++.h>
using namespace std;
long long a[100001];
int p[100001];
vector< pair < int, long long > > g[100001];
set< pair< long long, int > > s;
void  Dijkstra( pair < long long, int > n ){
  long long w = n.first;
  int v = n.second;
  for( int i = 0; i < g[v].size(); i++ ){
    int w1 = g[v][i].second;
    int v1 = g[v][i].first;
    if( w + w1 < a[v1] ){
      s.erase( { a[v1], v1 } );
      s.insert( {  w + w1, v1 } );
      a[v1] = w + w1;
      p[v1] = v;
    }
  }
}
int main() {
  int n, m, b, c, w;
  cin >> n >> m;
  p[1] = 0;
  for( int i = 2; i <=n; i++)
    p[i] = -1;
  for( int i = 1; i <= n; i++ )
    a[i] = 1e18;
  for( int i = 1; i <= m; i++ ){
    cin >> b >> c >> w;
    g[b].push_back({c,w});
    g[c].push_back({b,w});
  }
  for ( int i = 1; i <= n; i++)
    s.insert( { a[i], i } );
  while(s.size() > 0){
     Dijkstra( *s.begin( ) );
     s.erase(s.begin());
  }
  for( int i = 2; i  <= n; i++ ){
    if(p[n] == -1){
        cout << -1;
        return 0;
    }
    if(p[i] == 0 ){
        cout << -1;
        return 0;
    }
  }
  vector < int > ans;
  int i = n;
  ans.push_back(i);
  while( i > 1 ){
    ans.push_back( p [ i ] );
    i = p[i];
  }
  for( int i = ans.size()-1; i >= 0; i-- )
    cout << ans[i] << " ";
}
