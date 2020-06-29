#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 500003

ll MOD=1e9+7;
ll t , n , i , s[MAX], a[MAX], b[MAX],g; 
string str;

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
		cin>>str;
		for(i=0;i<n;i++)
		{
			s[i] = str[i]-'0';
		}

		a[0]=1;
		b[0]=1;

		g = 0;

		for(i=1;i<n;i++)
		{
			if(s[i]==0)
			{
				a[i]=0; b[i]=0;
			}
			else if(s[i]==2)
			{
				if(g==0)
				{
					a[i]=1; b[i]=1;
				}
				else
				{
					a[i]=0; b[i]=2;
				}
			}
			else
			{
				if(g==0)
				{
					a[i]=1; b[i]=0;
					g=1;
				}
				else
				{
					a[i]=0; b[i]=1;
				}
			}
		}

		for(i=0;i<n;i++) cout<<a[i];
			cout<<"\n";
		for(i=0;i<n;i++) cout<<b[i];
			cout<<"\n";
	}
	return 0;
}