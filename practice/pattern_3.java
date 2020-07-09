import java.util.Scanner;
public class pattern_3{
    public static Scanner Scn=new Scanner(System.in);
    public static void main(String[] args){
        System.out.println("enter number of rows");
        int n=Scn.nextInt();
        int count=1,cst=1;
        for(int i=1;i<=n;i++){
            for(int nst=1;nst<=cst;nst++)
            {
                System.out.print(count+" ");
                count++;
            }
        cst++;
        System.out.println();
        }return;
    }
}