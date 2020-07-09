#include<iostream>
#include<vector>

using namespace std;

int lower_search(vector<int>& arr, int data){
    int le=0;
    int ri=arr.size()-1;
    int mid=0;
    while(le<=ri){
        mid = (le + ri)/2;
        if(arr[mid]<data)
        le=mid+1;
        else if(arr[mid]>data)
        ri=mid-1;
        else if(arr[mid]==data)
        {
            if(mid-1>=0 && arr[mid-1]==data)ri=mid-1;
            else return mid;
        }
        else return -1;
    }

}

void inputArray(vector<int>& arr){
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
}

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n,0);
    inputArray(arr);
    cout<<"number to be searched"<<endl;
    int r;
    cin>>r;
    int m=lower_search(arr,r);
    if(m==-1)
    cout<<"not found!";
    else
    {
        cout<<"lower bound found at  "<<m;
    }
    
}
int main(int args, char**argv)
{
    solve();
    return 0;
}