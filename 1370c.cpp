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


ll t,n,flag,i;

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
		if(n&1 || n==2)
		{
			if(n==1) cout<<"FastestFinger\n";
			else cout<<"Ashishgup\n";
			continue;
		}
		flag=0;
		for(i=3;(i*i)<=n;i++)
		{
			if(n%i==0 && (n/i)!=2 && (i&1 || (n/i)&1))
			{
				flag = 1;
				break;
			}
		}
		if(flag) cout<<"Ashishgup\n";
		else cout<<"FastestFinger\n";
	}
	return 0;
}