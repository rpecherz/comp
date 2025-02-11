#include <bits/stdc++.h>
using namespace std;

const int f=7001;

int rep[f];
int ranga[f];
vector<int> wyniki;

struct s
{
    int st,nd,rd,cz;
};
vector<s> ona;

bool comp(s a,s b)
{
    return(a.rd<b.rd || (a.rd==b.rd && a.cz<b.cz));
}

int Find(int a)
{
    if(a==rep[a])
        return a;
    return rep[a]=Find(rep[a]);
}

void Union(int u,int v)
{
    u=Find(u);
    v=Find(v);
    if(ranga[u] < ranga[v])
        rep[u]=v;
    else if(ranga[u] > ranga[v])
            rep[v] = u;
        else
        {
            rep[u] = v;
            ranga[v]++;
        }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    int n,m;
    cin >> n >> m;
    
    for(int i=1;i<=n;++i)
    {
        rep[i]=i;
        ranga[i]=1;
    }
    for(int i=1;i<=m;++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        s zgred={a,b,c,i};
        ona.push_back(zgred);
    }

    sort(ona.begin(),ona.end(),comp);
    
    for(int i=0;i<m;++i)
    {
        int a=ona[i].st,b=ona[i].nd;
        if(Find(a)!=Find(b))
        {
            wyniki.push_back(ona[i].cz);
            Union(a,b);
        }
    }
    for(int i=0;i<wyniki.size();++i)
        cout << wyniki[i] << "\n";
    return 0;
}