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

ll t,n,i,z;
string s,str;

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
		s="";
		for(i=n-1;i>=0;i--)
		{
			if(str[i]=='0') break;
			s += str[i];
		}
		ll len = i;
		for(i=0;i<n;i++)
		{
			if(str[i]=='1') break;
			s += str[i];
		}
		if(i-1!=len) s+='0';
		reverse(s.begin(),s.end());
		cout<<s<<"\n";
	}
	return 0;
}