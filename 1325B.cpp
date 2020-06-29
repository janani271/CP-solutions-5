#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 100003

ll MOD=1e9+7;
ll t , n , i , x , c;
map<ll,ll>m;
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
		m.clear(); c=0;
		for(i=0;i<n;i++)
		{
			cin>>x;
			if(m[x]!=1)
			{
				m[x]=1; c++;
			}
		}
		cout<<c<<"\n";
	}
	return 0;
}