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


ll t,n,i,j,k,x,o,e;
vector<pairs> even,odd;

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
		even.clear(); odd.clear();

		for(i=0;i<(2*n);i++)
		{
			cin>>x;
			if(x&1) odd.pb({x,i+1});
			else even.pb({x,i+1});
		}
		e = even.size(); o = odd.size();
		
		i=0;j=0;
		for(k=0;k<n-1;k++)
		{
			if(i+1<e)
			{
				cout<<even[i].second<<" "<<even[i+1].second<<"\n";
				i += 2;
			}
			else
			{
				cout<<odd[j].second<<" "<<odd[j+1].second<<"\n";
				j += 2;
			}
		}
	}
	return 0;
}