import java.util.Scanner;
public class greatest{
    public static Scanner scn=new Scanner(System.in);
    public static void main (String[] args){
        System.out.println("enter three numbers to be varifyed");
        int a=scn.nextInt();
        int b=scn.nextInt();
        int c=scn.nextInt();
        System.out.println("the largest number is");
        if (a>b && a>c)
        System.out.println(a);
        else if (b>c && b>a)
        System.out.println(b);
        else
        System.out.println(c);
    }
}