#include <bits/stdc++.h>
using namespace std;
int j[10000001], h[10000001],v[10000001],jami[10000001];
int main() {
  int n;
  scanf("%d", &n);
  int a;
  for(int i=1;i<=n;i++){
scanf("%d", &a);
h[a]++;}
  for(int i=2;i<=10000000;i++){
if(v[i]==0)
for(int f=i;f<=10000000;f+=i){
v[f]++;
j[i]+=h[f];}}
  jami[1]=0;
  for(int i=2;i<=10000001;i++)
    jami[i]=jami[i-1]+j[i];
  int y;
  scanf("%d", &y);
  int l,r;
  for(int i=1;i<=y;i++){
scanf("%d %d",&l,&r);
if(l>10000000)
printf("0\n");
else
if(r>10000000)
printf("%d\n",(jami[10000000]-jami[l-1]));
else
printf("%d\n",(jami[r]-jami[l-1]));}
return 0;}