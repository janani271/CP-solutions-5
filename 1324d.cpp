#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 200005

ll MOD=1e9+7;
ll n,f,i,a[MAX],b[MAX],x,pos,c,ans,val;
vector<ll>v;
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	f=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>b[i];
		x = a[i]-b[i];
		v.pb(x);
		if(x>0) f=1;
	}
	if(f==0)
	{
		cout<<"0";
		return 0;
	}

	sort(v.begin(),v.end());

	pos = upper_bound(v.begin(),v.end(),0)-v.begin();
	
	c = n-pos;
	ans = (c*(c-1))/2;
	c=pos;
	for(i=c;i<n;i++)
	{
		val = v[i];
		pos = upper_bound(v.begin(),v.end(),-val) - v.begin();
		if(pos < i)
		{
			ans += (c-pos);
		}
	}
	cout<<ans<<"\n";
	return 0;
}