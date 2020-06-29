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

ll t,n,k,i,flag;
string s,res[MAX],ans;
map<char,ll>m;

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
		cin>>s;
		sort(s.begin(),s.end());
		flag=0;
		m[s[0]] = 1;
		for(i=1;i<n;i++)
		{
			m[s[i]]++;
			if(s[i]!=s[i-1])
			{
				flag++;
			}
		}
		if(!flag)
		{
			res[0] = s.substr(0,n/k);
			if(n%k!=0) res[0] += s[0];
			cout<<res[0]<<"\n";
		}
		else
		{
			ll check=0,cur,pos=k;
			for(i=0;i<k;i++)
			{
				res[i] = s[i];
				if(i!=0 && s[i]!=s[i-1] && !check)
				{
					pos = i;
					check = 1;
				}
			}

			if(flag==1 && m[s[0]]<=k)
			{
				cur = 0;
				for(i=k;i<n;i++)
				{
					res[cur++] += s[i];
					if(cur==pos || cur==k) cur=0;
				}
			}
			else
			{
				res[0] += s.substr(k,n-k+1);
			}	
			
			ans = res[0];

			for(i=1;i<k;i++)
			{
				// cout<<res[i]<<"\n";
				ans = max(ans,res[i]);
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}