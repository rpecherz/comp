#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second

const int N=5e5+1;
const int m=(1<<19);
int tree[m*2];
pair<char,int> question[N];
vector<int> wartosci;
map<int,int> chcesz;
map<int,int> odw;
 
int quest(int l, int node)
{
    if(tree[node]<l) 
        return -1;
    if(node>=m) 
        return odw[node-m];
    if(tree[node*2]>=l) 
        return quest(l,node*2);
    else 
        return quest(l-tree[node*2],node*2+1);
}
void add(int l,int w)
{
    l+=m;
    while(l>0)
    {
        tree[l]+=w;
        l/=2;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    int t;
    cin >> t;
    for(int i=0;i<t;++i)
    {
        string a;
        int x;
        cin >> a >> x;
        if(a=="add")
        {
            wartosci.push_back(x);
            question[i]={'a',x};
        }
        if(a=="remove")
            question[i]={'r',x};
        if(a=="query")
            question[i]={'q',x+1};
    }
    sort(wartosci.begin(),wartosci.end());

    for(int i=0;i<wartosci.size();++i)
    {
        chcesz[wartosci[i]]=i+1;
        odw[i+1]=wartosci[i];
    }
        
    
    for(int i=0;i<t;++i)
    {
        if(question[i].st=='a')
            add(chcesz[question[i].nd],1);
        if(question[i].st=='q') 
            cout << quest(question[i].nd,1) << "\n";
        if(question[i].st=='r')
            add(chcesz[question[i].nd],-1);
    }
        
    return 0;
}