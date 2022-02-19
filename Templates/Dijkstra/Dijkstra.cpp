//Reference: luoguP4779
//Username:LNF_297
#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cstring>

#define pii std::pair < int , int >

const int MAX_N=1e5+1,MAX_M=2e5+1;

int n,m,s;
int dis[MAX_N];
bool vis[MAX_N];
std::vector <pii> edge[MAX_M];
std::priority_queue < pii , std::vector < pii > , std::greater < pii > > heap;

inline void init();
inline void dijkstra();

int main()
{
	init();
	dijkstra();
	for(int i=1;i<=n;i++)
	{
		printf("%d ",dis[i]);
	}
	return 0;
}

inline void dijkstra()
{
	dis[s]=0;
	heap.push(std::make_pair(0,s));
	while(!heap.empty())
	{
		int u;
		u=heap.top().second;
		heap.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i].first,w=edge[u][i].second;
			if(!vis[v]&&dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				heap.push(std::make_pair(dis[v],v));
			}
		}
	}
}

inline void init()
{
	memset(dis,0x7f,sizeof(dis));
	std::cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edge[u].push_back(std::make_pair(v,w));
	}
}
