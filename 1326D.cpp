#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 100003

ll MOD=1e9+7;


string s,ans,fans,res,temp;
ll n,i,j,ix1,ix2,t;

ll lps(string str)
{
	string t; 
	ll len,y,x;
	t = str;
	reverse(str.begin(),str.end());
	t = t + '#' + str;
	len = t.length();
	vector<ll>lpp(len+4);
	lpp[0]=0; y=0;
	for(x=1;x<len;x++)
	{
		while(y>0 && t[x]!=t[y])
			y = lpp[y-1];
		if(t[x]==t[y])
			y++;
		lpp[x]=y;
	}
	return y; 
}

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
		ll n = s.length(); ans="";
		for(i=0,j=n-1;i<j;i++,j--)
		{
			if(s[i]!=s[j]) break;
			ans += s[i];
		}
		if(i==j) res = s[i];
		else if(i>j) res = "";
		else
		{
			temp = s.substr(i,j-i+1);
			ix1 = lps(temp);
			reverse(temp.begin(),temp.end());
			ix2 = lps(temp);
			if(ix1 >= ix2)
			{
				reverse(temp.begin(),temp.end());
				res = temp.substr(0,ix1);
			}
			else res = temp.substr(0,ix2);
		}
		fans = ans;
		fans += res;
		reverse(ans.begin(),ans.end());
		fans += ans;
		cout<<fans<<"\n";
	}
	return 0;
}