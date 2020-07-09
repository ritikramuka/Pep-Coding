import java.util.Scanner;
public class pattern_4{
    public static Scanner Scn=new Scanner(System.in);
    public static void main (String[] args){
        System.out.println("enter number of rows..");
        int n=Scn.nextInt();
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j||(i+j)==(n+1))
                System.out.print("* ");
                else
                System.out.print("  ");
            }
            System.out.println();
        }
        return;
    }
}