#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 200003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll t,n,i,a[MAX],flag,cur,temp;
map<ll,ll>m;

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
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		m.clear(); flag=1;
		for(i=0;i<n;i++)
		{n
			cur = i + a[i];
			cur = cur%n;
			cur = (cur+n)%n;
			if(m[cur]!=0)
			{
				flag=0; break;
			}
			m[cur]=1;
		}
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}