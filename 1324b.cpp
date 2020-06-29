#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 100003

ll MOD=1e9+7;
ll t , n , f , i , a;
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
		f=0;
		map<ll,ll>m;
		cin>>n;
		// cout<<"n : "<<n<<"\n";
		for(i=1;i<=n;i++)
		{
			cin>>a;
			// cout<<"a : "<<a<<"\tm[a] : "<<m[a]<<"\n";
			if(m[a]!=0)
			{
				if(i-m[a]>1)
				{
					f=1;
				}
			}
			else m[a] = i;
		}
		if(f==1) cout<<"YES\n";
	else cout<<"NO\n";
	}
	return 0;
}