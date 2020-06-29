#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 100003

ll MOD=1e9+7;
ll n ,m,k,i,j,x,y;
string ans;
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m>>k;
	for(i=0;i<k;i++)
		cin>>x>>y;
	for(i=0;i<k;i++)
		cin>>x>>y;


	ans="";
	for(i=0;i<n-1;i++) ans+='U';
	for(i=0;i<m-1;i++) ans+='L';

	for(i=0;i<n;i++)
	{
		for(j=0;j<m-1;j++)
		{
			if(i&1) ans+='L';
			else ans+='R';
		}
		if(i!=n-1)
		ans+='D';
	}

	cout<<ans.length()<<"\n"<<ans;

	return 0;
}