#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 200003

ll MOD=1e9+7;

ll add(ll a,ll b)
{
	return ((a%MOD) + (b%MOD))%MOD;
}
ll mul(ll a,ll b)
{
	return ((a%MOD) * (b%MOD))%MOD;
}
ll sub(ll a,ll b)
{
	return ((a%MOD) - (b%MOD) + MOD)%MOD;
}

ll q, n , i ,cnt, t[MAX], ans[MAX],k,flag;
map<ll,ll>m;
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>q;
	while(q--)
	{
		cin>>n;
		m.clear();
		for(i=1;i<=n;i++)
		{
			cin>>t[i];
			m[t[i]]=1;
		}
		cnt = m.size();
		if(cnt==1)
		{
			cout<<"1\n";
			for(i=1;i<=n;i++) cout<<"1 ";
			cout<<"\n";
			continue;
		}
		if(n%2==0)
		{
			cout<<"2\n";
			for(i=1;i<=n;i++)
			{
				if(i&1) cout<<"1 ";
				else cout<<"2 ";
			}
			cout<<"\n";
			continue;
		}
		ans[1]=1;
		k=1; flag=0;
		for(i=2;i<=n;i++)
		{
			if(t[i]==t[i-1] && !flag)
			{
				flag=1;
				ans[i]=ans[i-1];
			}
			else if(i!=n || (i==n && flag))
			{
				if(ans[i-1]==1) ans[i]=2;
				else ans[i]=1;
			}
			else
			{
				if(t[i]!=t[1]) ans[i]=3;
				else ans[i]=1;
			}
			k = max(k,ans[i]);
		}
		cout<<k<<"\n";
		for(i=1;i<=n;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
	}
	return 0;
}