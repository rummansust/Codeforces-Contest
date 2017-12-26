#include <bits/stdc++.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<29)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("outE.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

const int MAX = 1000000;


struct data
{
    int tree[26];
    int complete;
}trie[MAX];

char text[100005];

int tot_node;

void trie_tree(int node,int ind)
{
    if(text[ind]=='\0')
    {
        return ;
    }
    int id=(int) (text[ind]-'a');
    if(trie[node].tree[id]==-1) trie[node].tree[id]=++tot_node;
    int nnode=trie[node].tree[id];
    trie_tree(nnode,ind+1);
    return ;
}

int dp[MAX][3];

int check(int pos)
{
    for(int i=0;i<26;i++)
    {
        if(trie[pos].tree[i]!=-1)
        {
            return false;
        }
    }
    return true;
}

int rec(int pos,int rem,int player)
{
    if(rem==0 || check(pos))
    {
        return !player;
    }
    int &ret = dp[pos][player];
    if(ret!=-1) return ret;
    ret=player;
    int npos;
    for(int i=0;i<26;i++)
    {
        if(trie[pos].tree[i]!=-1)
        {
            npos=trie[pos].tree[i];
            if(!player) ret|=rec(npos,rem-1,!player);
            else ret&=rec(npos,rem-1,!player);
        }
    }
    return ret;
}

int main()
{
    int n,k;
    clrall(trie,-1);
    SF("%d %d ",&n,&k);
    tot_node=0;
    while(n--)
    {
        SF("%s",&text);
        trie_tree(0,0);
    }
    clrall(dp,-1);
    int ret=rec(0,k,0);
    if(ret) cout<<"Second\n";
    else cout<<"First\n";
    return 0;
}



















