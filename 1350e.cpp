#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 1002

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll n,m,t,i,j,a[MAX][MAX],x,y,p,rem,dist[MAX][MAX],visited[MAX][MAX];
string s;
queue<pairs>q;

int movex[] = {0,0,1,-1};
int movey[] = {1,-1,0,0};

bool good(ll c, ll d)
{
	ll nx,ny;
	for(int k=0;k<4;k++)
	{
		nx = c+movex[k];
		ny = d+movey[k];
		if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
		if(a[nx][ny] == a[c][d])
		{
			return true;
		}
	}
	return false;
}

void bfs()
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(good(i,j))
			{
				q.push({i,j});
				dist[i][j]=0;
				visited[i][j]=1;
			}
		}
	}

	pairs cell;
	ll nx,ny;
	while(!q.empty())
	{
		cell = q.front();
		q.pop();
		x = cell.first; y = cell.second;
		for(i=0;i<4;i++)
		{
			nx = x+movex[i]; ny = y+movey[i];
			
			if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
			if(visited[nx][ny]) continue;
			
			dist[nx][ny] = dist[x][y]+1;
			visited[nx][ny]=1;
			q.push({nx,ny}); 
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m>>t;
	for(i=0;i<n;i++)
	{
		cin>>s;
		for(j=0;j<m;j++) a[i][j] = s[j]-'0';
	}
	
	for(i=0;i<n;i++) for(j=0;j<m;j++) dist[i][j] = INF;
	bfs();
	while(t--)
	{
		cin>>x>>y>>p;
		x--; y--;
		if(p<=dist[x][y])
		{
			cout<<a[x][y]<<"\n";
			continue;
		}
		rem = p - dist[x][y];
		if(rem%2==0) cout<<a[x][y]<<"\n";
		else cout<<1-a[x][y]<<"\n";
	}
	return 0;
}