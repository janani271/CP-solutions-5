#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 100003

ll MOD=998244353;

ll n,po,diff,sum,i,tot,cur;
vector<ll>ans;

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

	cin>>n;
	po = 1;
	diff = 0; sum=0;
	for(i=1;i<=n;i++)
	{
		po = mul(po,10);
		tot = mul(po,i);
		cur = sub(tot,diff);
		ans.pb(cur);
		diff = add(add(diff,sum),(2*cur));
		sum = add(sum,cur); 
	}
	reverse(ans.begin(),ans.end());
	for(auto it:ans)cout<<it<<" ";
	return 0;
}