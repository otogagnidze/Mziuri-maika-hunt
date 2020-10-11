#include <bits/stdc++.h>
using namespace std;
int n,l,r,q, a[1000001];
long long pas=0;
int main() {
  cin >> n >> q;
  int arr[n+1], arr1[n+1];
for( int i = 1; i <= n; i++)
    cin >> arr[i];
for( int i = 1; i <= q; i++){
    cin >> l >> r;
 a[l]++; a[r+1]--;}
arr1[1] = a[1];
for( int i = 2; i <= n; i++)
arr1[i] = arr1[i-1] + a[i];
sort(arr1+1,arr1+n+1); sort(arr+1,arr+n+1);
for( int i=1; i<=n; i++)
pas += (long long)arr1[i] *arr[i];
  cout<<pas;
  return 0;}