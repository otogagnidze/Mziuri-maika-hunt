#include <bits/stdc++.h>
using namespace std;
int dp[20001],s;
int main(){
cin>>s;
dp[0]=1;dp[1]=0;dp[2]=0;
 for(int i=3;i<=s;i++){
 dp[i]=dp[i-1]+dp[i-3];
 dp[i]=dp[i]%1000000007;}	
 cout<<dp[s];
return 0;}