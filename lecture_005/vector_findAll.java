import java.util.Scanner;
import java.util.ArrayList;
public class vector_findAll{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] args)
    {
        solve();
        return;
    }
    public static void solve()
    {
        System.out.println("enter n");
        int n=scn.nextInt();
        int[]arr=new int[n];
        inputArray(arr);
        System.out.println("enter data");
        int data=scn.nextInt();
        ArrayList<Integer> ans=allIndex(arr,data);
        System.out.println(ans);
    }
    public static void inputArray(int[]arr)
    {
        for(int i=0;i<arr.length;i++)
            arr[i]=scn.nextInt();
        System.out.println();
    }
    public static ArrayList<Integer> allIndex(int[] arr,int b)
    {
        ArrayList<Integer>ans=new ArrayList<>();
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]==b)
            ans.add(i);
        }
        return ans;
    }
    
}