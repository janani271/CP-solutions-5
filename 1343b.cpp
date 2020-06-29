#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 100003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll t,n,mid,cnt,cur;

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
		if((n/2)%2)
		{
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		mid = (n/2) + 1;
		
		cnt = n/2; cur = 2;
		while(cnt>0)
		{
			if(cur==mid)
			{
				cur += 2;
				continue;
			}
			cout<<cur<<" ";
			cur += 2;
			cnt--;
		}
	
		cnt=(n/2); cur=1;
		while(cnt>0)
		{
			if(cur==mid)
			{
				cur += 2;
				continue;
			}
			cout<<cur<<" ";
			cur += 2;
			cnt--;
		}
		cout<<"\n";
	}

	return 0;
}