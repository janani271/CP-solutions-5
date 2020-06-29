#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 100003

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

ll t , n , k , i, pos , pos2, f , s,temp;

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
		cin>>n>>k;
		for(i=1;i<=n;i++)
		{
			if((i*(i+1))/2 >= k)
			{
				pos = i;
				break;
			}
		}

		f = n-pos;
		// cout<<"F : "<<f<<"\n";

		temp = (i*(i-1))/2;
		for(i=1;i<=n;i++)
		{
			if(i+temp == k)
			{
				pos2 = i;
				break;
			}
		}

		s = n-pos2+1;
		// cout<<"s : "<<s<<"\n";
		for(i=1;i<=n;i++)
		{
			if(i==f || i==s)
				cout<<"b";
			else cout<<"a";
		}

		cout<<"\n";	
			
	}
	return 0;
}