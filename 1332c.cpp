#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 200003
#define INF 1000000000000000005

using namespace std;

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

ll t,n,k,s[MAX],i,j,cur,h,ans[MAX],temp[MAX],res;
map<pairs,ll>m;
string str;
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
		cin>>str;
		m.clear(); res=0;
		for(i=0;i<n;i++) s[i] = str[i]-'a';
		for(i=0;i<n;i++)
		{
			m[{i%k,s[i]}]++;
		}
		for(i=0;i<(k/2)+(k%2);i++)
		{
			j = k-1-i;
			cur = 0;
			for(h=1;h<26;h++)
			{
				if(m[{i%k,h}]+m[{j%k,h}] > m[{i%k,cur}]+m[{j%k,cur}])
				{
					cur = h;
				}
			}
			ans[i]=cur;
		}
		// cout<<"\n";
		// cout<<"first half : "<<"\n";
		for(i=0;i<(k/2)+(k%2);i++)
		{
			temp[i]=ans[i];
			// cout<<temp[i]<<" ";
		}
		// cout<<"\n";
		// cout<<"second half : \n";
		for(i=0;i<k/2;i++)
		{
			temp[k-i-1]=ans[i];
			// cout<<temp[i]<<" ";
		}
		// for(i=0;i<k;i++) cout<<temp[i]<<" ";
		for(i=0;i<n;i+=k)
		{
			for(j=0;j<k;j++)
			{
				// cout<<"s : "<<s[i+j]<<"\ttemp : "<<temp[j]<<"\n";
				if(s[i+j]!=temp[j])
					res++;
			}
		}
		cout<<res<<"\n";	
	}
	return 0;
}