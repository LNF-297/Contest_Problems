//reference:luoguP3366
//Username:LNF_297
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>
#include<cstring>
#include<vector>

#define pii std::pair < int , int > 

const int MAX_N=5001,MAX_M=2e5+1;

int n,m,ans,cnt;
int dis[MAX_N];
bool vis[MAX_N];

std::vector < pii > edge[MAX_N];
std::priority_queue < pii , std:: vector < pii > , std::greater < pii > > heap;

inline void init();
inline void prime();

int main()
{
	init();
	prime();
	if(cnt==n) std::cout<<ans<<std::endl;
	else std::cout<<"orz"<<std::endl;
	return 0;
}


inline void prime()
{
	dis[1]=0;
	heap.push(std::make_pair(0,1));
	while(!heap.empty())
	{
		int u=heap.top().second;
		heap.pop();
		if(vis[u]) continue;
		vis[u]=true;
		cnt++;
		ans+=dis[u];
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i].first,w=edge[u][i].second;
			if(!vis[v]&&w<dis[v])
			{
				dis[v]=w;
				heap.push(std::make_pair(dis[v],v));
			}
		}
	}
}

inline void init()
{
	std::cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edge[u].push_back(std::make_pair(v,w));
		edge[v].push_back(std::make_pair(u,w));
	}
	memset(dis,0x7f,sizeof(dis));
}
