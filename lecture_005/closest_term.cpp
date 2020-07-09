#include<iostream>
#include<vector>

using namespace std;

int closest_term(vector<int>& arr, int data){
    int le=0;
    int ri=arr.size()-1;
    int mid=0;
    int temp;
    while(le<=ri){
        mid = (le + ri)/2;
        if(arr[mid]<data)
        {  
             temp=(data-arr[mid])>(arr[mid+1]-data)?arr[mid+1]:arr[mid];
            le=mid+1;}

        else if(arr[mid]>data)
        {
            ri=mid-1;
            temp=(data-arr[mid-1])>(arr[mid]-data)?arr[mid]:arr[mid-1];
        }
        else if(arr[mid]==data)
        return mid;
        
        
    }
return temp;
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
    int m=closest_term(arr,r);
    if(m==r)
    cout<<"found at "<<m<<endl;
    else
    cout<<"closest term found is "<<m;
    
    
}
int main(int args, char**argv)
{
    solve();
    return 0;
}