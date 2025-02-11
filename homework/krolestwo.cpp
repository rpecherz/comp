#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define ll long long
typedef pair<int,int> pii;


int koszta[7001];
vector<pii> r[7001];
priority_queue<pii,vector<pii>,greater<pii>> q;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        r[a].push_back({c,b});
        r[b].push_back({c,a});
    }
    
    q.push({0,1});
    for(int i=2;i<=n;++i)
        koszta[i]=1e9+1;
    koszta[1]=0;
    while(!q.empty())
    {
        pii logo=q.top();
        q.pop();
        for(int i=0;i<r[logo.nd].size();++i)
        {
            int a=r[logo.nd][i].st,b=r[logo.nd][i].nd;
            if(koszta[b]>koszta[logo.nd]+a)
            {
                koszta[b]=koszta[logo.nd]+a;
                q.push({koszta[b],b});
            }
        }
    }
    
    for(int i=2;i<=n;++i)
        cout << koszta[i] << " ";
    
    return 0;
}