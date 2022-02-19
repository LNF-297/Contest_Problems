#include<iostream>
#include<cstdio>
#include<new>
#include<algorithm>

typedef long long ll;
const int MAX_N=1e5+1;

struct node
{
	ll val;
	ll tag=0;
	node *ls=NULL,*rs=NULL;
};

node *root;

int n,m,x,y,k;
int a[MAX_N];

inline void init();
void build(int l,int r,node *now);
void modify(int l,int r,node *now);
ll query(int l,int r,node *now);

int main()
{
//	freopen("8.in","r",stdin);
//	freopen("8.out","w",stdout);
	init();
	build(1,n,root);
	while(m--)
	{
		int type;
		scanf("%d",&type);
		if(type==1)
		{
//			int x,y;
			scanf("%d%d%d",&x,&y,&k);
			modify(1,n,root);
		}
		else
		{
//			int x,y;
			scanf("%d%d",&x,&y);
			ll ans;
			ans=query(1,n,root);
			printf("%lld\n",ans);
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

ll query(int l,int r,node *now)
{
	ll sum=0;
	if(x<=l && r<=y)
	{
		sum=now->val+now->tag*(r-l+1);
//		printf("l=%d r=%d sum=%lld\n",l,r,sum);
		return sum;
	}
	now->val+=now->tag*(r-l+1);
	now->ls->tag+=now->tag;
	now->rs->tag+=now->tag;
	now->tag=0;
	int mid=(l+r)>>1;
	if(x<=mid) sum+=query(l,mid,now->ls);
	if(y>mid) sum+=query(mid+1,r,now->rs);
//	printf("l=%d r=%d sum=%lld\n",l,r,sum);
	return sum;
}

void modify(int l,int r,node *now)
{
	if(x<=l&&r<=y)
	{
		now->tag+=k;
		return;
	}
	now->val+=(std::min(y,r)-std::max(x,l)+1)*k;
	int mid=(l+r)>>1;
	if(x<=mid) modify(l,mid,now->ls);
	if(y>mid) modify(mid+1,r,now->rs);
}

void build(int l,int r,node *now)
{
	if(l==r)
	{
		now->val=a[l];
//		printf("l=%d r=%d sum=%lld\n",l,r,now->val);
		return;
	}
	int mid=(l+r)>>1;
	now->ls = new node;
	now->rs = new node;
	build(l,mid,now->ls);
	build(mid+1,r,now->rs);
	now->val = now->ls->val + now->rs->val;
//	printf("l=%d r=%d sum=%lld\n",l,r,now->val);
}

inline void init()
{
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	root = new node;
}
