import java.util.*;
public class alpha_num{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] args)
    {
        String str="";
        int m=scn.nextInt();
        for(int i=0;i<m;i++)
        {
            int g=scn.nextInt();
            str+=g;
        }
        int e= numToAlpha(str,"");
        System.out.println(e);
    }

    public static int numToAlpha(String str,String ans)
    {
        if(str.length()==0)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;

        char ch=str.charAt(0);
        String onelength=str.substring(1);

        if(ch=='0')
        {
            count+=numToAlpha(onelength,ans);
        }
        else
        {
            char c=(char)(ch-'1'+'A');
            count+=numToAlpha(onelength,ans+c);
            if(str.length()>1)
            {
                char ch2=str.charAt(1);
                String twolength=str.substring(2);
                int num=(ch-'0')*10+(ch2-'0');
                if(num<=26)
                count+=numToAlpha(twolength,ans+(char)(num+'A'));
            }
        }
        return count;
    }
}