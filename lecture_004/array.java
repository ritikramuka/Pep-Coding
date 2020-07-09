import java.util.Scanner;
public class array{
    public static Scanner Scn=new Scanner (System.in);
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        int n=Scn.nextInt();
        int[] arr=new int[n];
        inputArray(arr);
        display(arr);
    }
    public static void inputArray(int[] arr){
        for(int i=0;i<arr.length;i++){
            arr[i]=Scn.nextInt();
        }
    }

    public static void display(int[] arr){
        for(int i: arr)
        System.out.print(i+" ");
        System.out.println();
    }
}