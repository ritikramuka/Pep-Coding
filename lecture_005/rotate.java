import java.util.Scanner;
public class rotate{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] args)
    {
        solve();
    }

    public static void solve()
    {
        int n=scn.nextInt();
        int [] arr=new int[n];
        input_arr(arr);
        System.out.println("inpute rotate number");
        int r=scn.nextInt();
        r=(r%arr.length);
        r=r>=0?r:r+arr.length;
        rotate(arr,0,r-1);
        rotate(arr,r,arr.length-1);
        rotate(arr,0,arr.length-1);
        display(arr);
    }

    public static void input_arr(int[] arr)
    {
        for(int i=0;i<arr.length;i++)
        arr[i]=scn.nextInt();
        System.out.println();
    }

    public static void rotate(int[] arr,int i,int j)
    {
        while(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            j--;
            i++;
        }
    }
    public static void display(int[] arr)
    {
        for(int k:arr)
        System.out.print(k+" ");
    }
    
}
