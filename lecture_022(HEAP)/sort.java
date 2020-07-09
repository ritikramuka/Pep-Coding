import java.util.*;
class sort{
    static void swap(int[] arr,int a,int b)
    {
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }

    static int[] sortZeroOne(int[] arr)
    {
        for(int i=0,j=0;i<arr.length;)
        {
            if(arr[i]==1)
            {
                i++;
            }
            else if(arr[i]==0) 
            {
                swap(arr,i,j);
                i++;
                j++;
            }
        }
    return arr;
    } 

    static void Sort012(int[] arr)
    {
        int itr=0,ptr1=0,ptr2=arr.length-1;
        while(itr<=ptr2)
        {
            if(arr[itr]==0)
            {
                swap(arr,itr,ptr1);
                ptr1++;
                itr++;
            }
            else if(arr[itr]==1)
            {
                itr++;
            }
            else
            {
                swap(arr,ptr2,itr);
                ptr2--;
            }
        }
        System.out.print(Arrays.toString(arr));
    }

    //number of inversions in nLog(n).... using Merge Sort

    static int intvercounter=0;

    static int[] merge2sortedarray(int[] one,int[] two)
    {
        int[] ans=new int[one.length+two.length];
        int i=0,j=0,k=0;
        while(i<one.length && j<two.length)
        {
            if(one[i]<two[j])
            {
                ans[k++]=one[i++];
            }
            else
            {
                ans[k++]=two[j++];
                intvercounter+=one.length-i;
            }
        }
        while(i<one.length)
        {
            ans[k++]=one[i++];
        }
        while(j<two.length)
        {
            ans[k++]=two[j++];
        }
        return ans;
    }

    static int[] mergesort(int[] arr,int lo,int hi)
    {
        if(lo==hi)
        {
            int[] ba=new int[1];
            ba[0]=arr[lo];
            return ba;
        }

        int mid=(hi+lo)/2;
        int[] fh=mergesort(arr,lo,mid);
        int[] sh=mergesort(arr,mid+1,hi);
        int[] fsa=merge2sortedarray(fh,sh);
        return fsa;
    }

    public static int partitioning(int[] arr,int lo,int hi)
    {
        int pvt=arr[hi];
        int j=lo;
        for(int i=lo;i<=hi;)
        {
            if(arr[i]<=pvt)
            {
                swap(arr,i,j);
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        return j-1;
    }

    public static int quickSelect(int[] arr,int lo,int hi,int idx)
    {
        if(lo>hi)
        {    
            return -1;
        }

        int ptr=partitioning(arr,lo,hi);
        System.out.println(arr[ptr]);
        if(ptr>idx)
            return quickSelect(arr,lo,ptr-1,idx);
        else if(ptr<idx)
            return quickSelect(arr,ptr+1,hi,idx);
        else
            return arr[ptr];
    }


    public static void main(String[] args)
    {
        // int[] arr={1,1,0,0,0,1,0,1};
        // int[] ans =sortZeroOne(arr);
        // System.out.println(Arrays.toString(ans));
        // int[] arr2={1,1,2,2,0,2,1,0,2,0,2,1};
        // Sort012(arr2);
        int [] arr={2,5,1,8,6,3,7,4};
        // int [] sarr=mergesort(arr,0,arr.length-1);
        // System.out.println(Arrays.toString(sarr));
        // System.out.println(intvercounter);
        System.out.println(quickSelect(arr,0,arr.length-1,6));
    } 
}