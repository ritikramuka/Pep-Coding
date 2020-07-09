import java.util.Scanner;
public class fibonacci_pattern{
    public static Scanner Scn=new Scanner (System.in);
    public static void main(String[] args){
        System.out.println("enter the number of rows..");
        int n=Scn.nextInt();
        int a=0,b=1,sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                System.out.print(sum+" ");
                a=b;
                b=sum;
                sum=a+b;
            }
            System.out.println();
        }
        return;
    }
}