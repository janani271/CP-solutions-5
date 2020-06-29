#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 100003

ll MOD=1e9+7;
ll t , n;
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
		if(n==1)
		{
			cout<<"-1\n";
			continue;
		}
		n--;
		cout<<"8";
		while(n>0)
		{
			cout<<"9";
			n--;
		}
		cout<<"\n";
	}
	return 0;
}