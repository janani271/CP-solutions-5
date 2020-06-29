#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 200009

ll MOD=1e9+7;
ll n , i , b[MAX], a[MAX], x[MAX];
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	x[0]=0;
	for(i=1;i<=n;i++)
	{
		x[i] = max(x[i-1],x[i-1]+b[i]);
		a[i-1] = x[i-1] + b[i];
		cout<<a[i-1]<<" ";
	}
	return 0;
}