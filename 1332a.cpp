#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 100003
#define INF 1000000000000000005

using namespace std;

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

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;
	ll t , a , b , c , d , x , y , x1 , y1 , x2 , y2;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>d;
		cin>>x>>y>>x1>>y1>>x2>>y2;

		if((x1-x2 == 0 &&(a!=0 || b!=0))||(y1-y2 == 0 && (c!=0 || d!=0)))
		{
			cout<<"NO\n"; continue;
		}
		x = x + b - a;
		y = y + d - c;
		// cout<<"x : "<<x<<"\ty: "<<y<<"\n";
		if(x1<=x && x<=x2 && y1<=y && y<=y2)
			cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}