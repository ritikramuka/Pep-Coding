import java.util.Scanner;
public class si{
    public static Scanner scn=new Scanner(System.in);//create object
    public static void main(String[] args){
       System.out.println("please input value of p,t and r ");
        int p=scn.nextInt();
        int r=scn.nextInt();
        int t=scn.nextInt();
        int si=(p*r*t)/100;
        
        System.out.print("your simple intrest is" + si);

    }

}