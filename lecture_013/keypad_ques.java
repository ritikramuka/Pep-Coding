import java.util.Scanner;
import java.util.ArrayList;
public class keypad_ques{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] args)
    {
        int num=scn.nextInt();
        System.out.print(keypad(num));
    }
    public static String getcode(int digit)
    {
         String[] arr={"abc","def","ghi","jkl","mno","pqr","stu","vwx","yz","*+#"};
         return arr[digit];
    }
    public static ArrayList<String> keypad(int num)
    {
        if(num==0){
            ArrayList<String>base =new ArrayList<>();
            base.add("");
            return base;
        }
        int digit=num%10;
        num=num/10;

        ArrayList<String> myAns=new ArrayList<>();
        String str=getcode(digit);
        ArrayList<String> recans=keypad(num);
        for(int i=0;i<str.length();i++)
        {
            for(String s:recans)
            {
                myAns.add(s+str.charAt(i));
            }
        }
        return myAns;
    }
}