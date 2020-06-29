#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 200003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

struct comp
{	
	bool operator()(const pairs& a, const pairs& b){
		ll dista = a.second-a.first+1;
		ll distb = b.second-b.first+1;
		if(dista>distb) return false;
		if(dista == distb && a.first<b.first) return false;
		return true;
	}
};

ll t,n,i,len,pos,a[MAX],l,r;
pairs cur;

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
		
		priority_queue<pairs,vector<pairs>,comp>pq;
		pq.push({1,n});
		i=1;
		
		while(!pq.empty() && i<=n)
		{
			cur = pq.top();
			pq.pop();
			len = cur.second - cur.first + 1;
			if(len%2==1) pos = (cur.first+cur.second)/2;
			else pos = (cur.first+cur.second-1)/2;
			a[pos] = i;
			i++;
			l = cur.first; r = pos-1;
			if(1<=l && l<=n && 1<=r && r<=n && l<=r)
			{
				pq.push({l,r});
			} 
			l = pos+1; r = cur.second;
			if(1<=l && l<=n && 1<=r && r<=n && l<=r)
			{ 
				pq.push({l,r});
			}	
		}

		for(i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<"\n";
	}
	return 0;
}