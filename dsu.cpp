#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int parent[N];
int group_size[N];
int level[N];
void dsu_initialization(int n){
    for(int i=0;i<n;i++){
        parent[i] = -1;
        group_size[i] = 1;
        level[i] = 0;
    }
}
int dsu_find(int node){
    if(parent[node] == -1)
        return node;
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}
void dsu_union(int node1, int node2){
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    parent[leaderA] = leaderB;
}
void dsu_union_by_size(int node1, int node2){
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if(group_size[leaderA] > group_size[leaderB]){
        parent[leaderB] = leaderA;
        group_size[leaderA]+=group_size[leaderB];
    }
    else{
        parent[leaderA] = leaderB;
        group_size[leaderB]+=group_size[leaderA];
    }
}
void dsu_union(int node1, int node2){
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if(level[leaderA] > level[leaderB]){
        parent[leaderB] = leaderA;
    }
    else if(level[leaderA] < level[leaderB]){
        parent[leaderA] = leaderB;
    }else{
        parent[leaderA] = leaderB;
        level[leaderB]++;
    }
}
int main()
{
    dsu_initialization(7);
    dsu_union_by_size(1,2);
    dsu_union_by_size(2,3);
    dsu_union_by_size(4,5);
    dsu_union_by_size(5,6);
    cout<<dsu_find(1)<<endl;
    cout<<dsu_find(4)<<endl;

    return 0;
}