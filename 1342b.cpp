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

string t,res;
ll q,n,flag;
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
		cin>>t;
		n = t.length();
		flag=1;
		for(ll i=1;i<n;i++)
		{
			if(t[i]!=t[i-1])
			{
				flag=0; break;
			}
		}
		if(flag)
		{
			cout<<t<<"\n";
			continue;
		}
		res="";
		for(ll i=1;i<=(2*n);i++)
		{
			if(i%2==0) res += '0';
			else res += '1';
		}
		cout<<res<<"\n";
	}
	return 0;
}