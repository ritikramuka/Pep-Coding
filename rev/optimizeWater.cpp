//leetcode ques 1168 optimize water distribution in a village
vector<int> par;
int findPar(int vtx)
{
    if(vtx==par[vtx])
        return vtx;
    else
        return par[vtx]=findPar(par[vtx]);
}

int minCostToSupplyWater(int n,vector<int> &wells,vector<vector<int>> &pipes)
{
    for(int i=0;i<wells.size();i++)
    {
        pipes.push_back({0,i+1,wells[i]});
        par.push_back(i);
    }
    par.push_back(wells.size());

    sort(pipes.begin(),pipes.end(),[](vector<int> &a,vector<int> &b){
        return a[2]<b[2];
    });

    int cost=0;
    for(vector<int> &p : pipes)
    {
        int p1=findPar(p[0]);
        int p2=findPar(p[1]);
        if(p1!=p2)
        {
            cost+=p[2];
            par[p1]=p2;
        }
    }
    
    return cost;
}
