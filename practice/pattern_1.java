import java.util.Scanner;
public class pattern_1{
    public static Scanner Scn= new Scanner(System.in);
    public static void main(String[] args){
        System.out.println("enter number of rows..");
        int n=Scn.nextInt();
        int cst=1;
        for(int i=1;i<=n;i++){
            for(int nst=1;nst<=cst;nst++){
                System.out.print("*");
            }
            cst++;
            System.out.print("\n");
        }
    }
}