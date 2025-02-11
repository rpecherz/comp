#include <bits/stdc++.h>
using namespace std;
#define pb push_back


const int inf=1e9,M=8197;
int kowale[202],dist[202][M];
bool vis[202][M];

struct input
{
    int st,nd,rd;
    input(int a=0,int b = 0, int c =0)
    {
        st = a;
        nd = b; 
        rd = c;
    }
    bool operator< (const input lol)
    {
        return (nd < lol.nd);
    }
};

struct s{
    int st,nd,rd;
    bool operator> (const s xd) const
    {   
        return(st>xd.st);
    }
};
vector<input> road[202];

void dijkstra() 
{
    priority_queue<s,vector<s>,greater<s>> q;
    q.push({0,1,kowale[1]});
    dist[1][kowale[1]]=0;
    while(!q.empty()) 
    {
        int sandaly=q.top().nd,miecze=q.top().rd;
        int nast=miecze|kowale[sandaly];
        vis[sandaly][miecze]=true;
        q.pop();
        for(int i=0;i<road[sandaly].size();++i) 
        {
            int koszt=road[sandaly][i].nd,miejsce=road[sandaly][i].st,udko=road[sandaly][i].rd;
                if(((nast & udko) == udko) && !vis[miejsce][nast] && dist[miejsce][nast]>dist[sandaly][miecze]+koszt)
                {
                    dist[miejsce][nast]=koszt+dist[sandaly][miecze];
                    q.push({dist[miejsce][nast],miejsce,nast});
                }
        }
    }
}
int main()  
{
    int n,m,p,k;
    scanf("%d%d%d%d",&n,&m,&p,&k);
    for(int i=1;i<=k;++i)
    {
        int vil,monsters;
        scanf("%d%d",&vil,&monsters);
        int op=kowale[vil];
        for(int j=1;j<=monsters;++j)
        {
            int mon;
            scanf("%d",&mon);
            op|=(1<<(mon-1));
        }   
        kowale[vil]=op;
    }
    for(int i=1;i<=m;++i)
    {
        int vA,vB,cost,mon,op=0;
        scanf("%d%d%d%d",&vA,&vB,&cost,&mon);
        for(int j=0;j<mon;++j)
        {
            int a;
            scanf("%d",&a);
            op|=(1<<(a-1));
        }
        road[vA].pb({vB,cost,op});
        road[vB].pb({vA,cost,op});
    }
    for(int i=1;i<=n;++i)
        for(int j=0;j<=(1<<p);++j)
            dist[i][j]=inf;
    
    dijkstra();
    int ans=inf;
    for(int i=0;i<(1<<p);i++)
        ans = min(ans,dist[n][i]);
        
    if(ans==inf) 
        printf("-1\n");
    else
        printf("%d\n",ans);
    return 0;
}