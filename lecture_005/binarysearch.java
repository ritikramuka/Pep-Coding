import java.util.Scanner;
public class binarysearch{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] args){
        solve();
    }

    public static void solve()
    {
        int n=scn.nextInt();
        int[] arr=new int[n];
        input(arr);
        System.out.println("enter number to find");
        int m=scn.nextInt();
        int f=binary(arr,m);
        if(f==-1)
        System.out.println("not found");
        else
        System.out.println("found at  "+f);
        int k=lower(arr,m);
        if(k==-1)
        System.out.println("not found");
        else
        System.out.println("found at  "+k);
        int e=upper(arr,m);
        if(e==-1)
        System.out.println("not found");
        else
        System.out.println("found at  "+e);
    }

     public static void input(int[] arr)
    {
        for(int i=0;i<arr.length;i++)
        arr[i]=scn.nextInt();
        System.out.println();
    }


    public static int binary(int[] arr,int data)
    {
        int ri=arr.length-1,le=0;
        while(le<=ri)
        {
            int mid=(le+ri)/2;
            if(arr[mid]<data)
            le=mid+1;
            else if(arr[mid]>data)
            ri=mid-1;
            else
            return mid;
        }
        return -1;
    
    }

    public static int lower(int[] arr,int data)
    {
        int ri=arr.length-1,le=0;
        while(le<=ri)
        {
            int mid=(le+ri)/2;
            if(arr[mid]<data)
            le=mid+1;
            else if(arr[mid]>data)
            ri=mid-1;
            else if(arr[mid]==data)
            {
                if(arr[mid-1]==data && (mid-1)>=0)
                ri=mid-1;
                else return mid;
                
            }
            else return-1;
            
        }
    
    }
    
    
    public static int upper(int[] arr,int data)
    {
        int ri=arr.length-1,le=0;
        while(le<=ri)
        {
            int mid=(le+ri)/2;
            if(arr[mid]<data)
            le=mid+1;
            else if(arr[mid]>data)
            ri=mid-1;
            else if(arr[mid]==data)
            {
                if(arr[mid+1]==data && (mid+1)!=0)
                le=mid+1;
                else return mid;
            }
            else return -1;
        }
        
    }
    
}
