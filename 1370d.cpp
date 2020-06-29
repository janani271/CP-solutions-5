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

ll n,k,i,a[MAX],mid,l,r,ans,visited[MAX],b[MAX];

bool check(ll cur)
{
	ll cnt1,cnt2,turn;
	i = 1; turn=1; cnt1=0;
	while(i<=n)
	{
		if(turn==1)
		{
			cnt1++; turn = 1-turn;
		}
		else if(turn==0 && a[i]<=cur)
		{
			cnt1++; turn=1-turn;
		}
		i++;
	}
	i = 1; turn=0; cnt2=0;
	while(i<=n)
	{
		if(turn==1)
		{
			cnt2++; turn = 1-turn;
		}
		else if(turn==0 && a[i]<=cur)
		{
			cnt2++; turn=1-turn;
		}
		i++;
	}
	return (cnt1>=k || cnt2>=k);
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i] = a[i];
	}

	sort(b+1,b+n+1);
	l=1;r=n;
	ans = b[n];
	while(l<=r)
	{
		mid = (l+r)/2;
		if(check(b[mid]))
		{
			ans = min(ans,b[mid]);
			r = mid-1;
		}
		else l = mid+1;
	}
	cout<<ans;
	return 0;
}
