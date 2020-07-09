#include<iostream>
#include<vector>
using namespace std;

int nqueens_Per1(vector<bool>& box,int qpsf,int tnq,string ans)
{
    if(qpsf==tnq)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<box.size();i++)
    {
        if(!box[i])
        {
            box[i]=true;
            count+=nqueens_Per1(box,qpsf+1,tnq,ans+"q"+to_string(qpsf+1)+"b"+to_string(i+1));
            box[i]=false;
        }
    }
    return count;
}

int nqueens_Comb1(vector<bool>& box,int idx,int qpsf,int tnq,string ans)
{
    if(qpsf==tnq)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<box.size();i++)
    {
        if(!box[i])
        {
            box[i]=true;
            count+=nqueens_Comb1(box,i+1,qpsf+1,tnq,ans+"q"+to_string(qpsf+1)+"b"+to_string(i+1));
            box[i]=false;
        }
    }
    return count;
}

int nqueens_Comb2(vector<bool>& box,int idx,int qpsf,int tnq,string ans)//subsequence method
{
    if(tnq==0 || idx==box.size())
    {
        if(tnq==0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    
    if(!box[idx])
        {
            box[idx]=true;
            count+=nqueens_Comb2(box,idx+1,qpsf+1,tnq-1,ans+"q"+to_string(qpsf+1)+"b"+to_string(idx+1));
            box[idx]=false;
        }
            count+=nqueens_Comb2(box,idx+1,qpsf,tnq,ans);//faith: agar queen bethi hui toh mai tujha nahi bethna dungi and agar queen nahi bethi hui tabh bhi main tujha nahi bethna dungi..
    
    return count;
}

int nqueens_Per2(vector<bool>& box,int idx,int qpsf,int tnq,string ans)//subsequence method
{
    if(tnq==0 || idx==box.size())
    {
        if(tnq==0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    
    if(!box[idx])
        {
            box[idx]=true;
            count+=nqueens_Per2(box,0,qpsf+1,tnq-1,ans+"q"+to_string(qpsf+1)+"b"+to_string(idx+1));
            box[idx]=false;
        }
            count+=nqueens_Per2(box,idx+1,qpsf,tnq,ans);
    
    return count;
}

int nqueens_CombNew(vector<bool>& box,int idx,int qpsf,int tnq,string ans)//subsequence method
{
    if(tnq==0 || idx==box.size())                                         //reverse!!! queen 1 will at max pos and queen 2 will be before 1 and so on...
    {
        if(tnq==0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    
    if(!box[idx])
        {
            box[idx]=true;
            count+=nqueens_CombNew(box,0,qpsf+1,tnq-1,ans+"q"+to_string(qpsf+1)+"b"+to_string(idx+1));
            box[idx]=false;
            count+=nqueens_CombNew(box,idx+1,qpsf,tnq,ans);
        }
    
    return count;
}

void solve()
{
    vector<bool>box(6,false);
    //cout<<nqueens_Per1(box,0,3,"");
    //cout<<nqueens_Comb1(box,0,0,3,"");
    //cout<<nqueens_Comb2(box,0,0,3,"");
    //cout<<nqueens_Per2(box,0,0,3,"");
    cout<<nqueens_CombNew(box,0,0,3,"");
}

int main(int args,char** argv)
{
    solve();
}