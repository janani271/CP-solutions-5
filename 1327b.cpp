#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 100003

ll MOD=1e9+7;
ll t , n , c , i , k , f[MAX], j , x, pos;
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;
	cin>>t;
	while(t--)
	{
		cin>>n;
		c=0;
		map<ll,ll>taken;
		for(i=1;i<=n;i++)
		{
			cin>>k; f[i]=0;
			for(j=1;j<=k;j++)
			{
				cin>>x;
				// a[i].pb(x);
				if(!taken[x] && f[i]==0)
				{
					taken[x]=1; f[i]=1;
				}
			}
			if(f[i]==0) c++;
		}
		if(c==0) cout<<"OPTIMAL\n";
		else
		{
			for(i=1;i<=n;i++)
			{
				if(!taken[i])
				{
					pos = i; break;
				}
			}
			for(i=1;i<=n;i++)
			{
				if(f[i]==0)
				{
					cout<<"IMPROVE\n";
					cout<<i<<" "<<pos<<"\n";
					break;
				}
			}
		}
	}
	return 0;
}