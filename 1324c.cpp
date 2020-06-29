#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 100003

ll MOD=1e9+7;
ll t , n, cl, mcl,i;
string s;
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
		cin>>s;
		n = s.length();
		cl=0; mcl=0;
		for(i=0;i<n;i++)
		{
			if(s[i]=='L')
			{
				cl++;
				if(cl>mcl)
					mcl = cl;
			}
			else cl=0;
		}
		cout<<mcl+1<<"\n";
	}	
	return 0;
}