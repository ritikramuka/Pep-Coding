import java.util.Scanner;
import java.util.*;
public class string_questions{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] args){
        solve();
    }

    public static void solve()
    {
        StringBuilder sb=new StringBuilder("aaabcdddefgh");
        removedublicate(sb);
    }

    public static void removedublicate(StringBuilder sb)
    {
        StringBuilder ans=new StringBuilder();
        
        for(int i=1;i<sb.length();i++)
        {
            char ch=sb.charAt(i);
            char pch=sb.charAt(i-1);
            if(ch!=pch)
            {
                ans.append(pch);
            }
        }
        int m=sb.length()-1;
        ans.append(sb.charAt(m));
        ans.toString();
        System.out.print(ans);
    }


}