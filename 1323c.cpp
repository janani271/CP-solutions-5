#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 1000003
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
ll len,s[MAX],i,res,n,pos;
string str;
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>len;
	cin>>str;
	res=0;
	s[0]=0;
	for(i=1;i<=len;i++)
	{
		if(str[i-1]=='(')
		{
			res++;
			s[i] = 1 + s[i-1];
		}
		else
		{
			res--;
			s[i] = s[i-1] - 1;
		}
	}
	if(res!=0)
	{
		cout<<"-1";
		return 0;
	}
	res=0;
	n=0; pos=0;
	for(i=1;i<=len;i++)
	{
		if(s[i]<0 && n==0)
		{
			n=1;
			pos = i;
		}
		if(s[i]==0 && n==1)
		{
			n=0;
			res += (i-pos+1);
		}
	}
	cout<<res;
	return 0;
}
