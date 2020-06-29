#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 100003

ll MOD=1e9+7;
ll t , n , i , a , o , e;
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
		o=0;e=0;
		for(i=0;i<n;i++)
		{
			cin>>a;
			if(a%2==0) e++;
			else o++;
		}
		if(e!=0 && o!=0) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}