import java.util.Scanner;
public class pattern_2{
    public static Scanner Scn=new Scanner(System.in);
    public static void main(String[] args){
        System.out.println("enter the number of rows..");
        int n=Scn.nextInt();
        int nst=1,nsp;
        nsp=n;
        for(int i=1;i<=n;i++){
            for(int csp=1;csp<nsp;csp++)
            System.out.print("  ");
            for(int cst=1;cst<=nst;cst++ )
            System.out.print("* ");
            nsp--;
            nst++;
            System.out.print("\n");
        }
        return;
    }
}