import java.util.Scanner;
public class string_basics{
    public static void main(String[] args)
    {
        solve();
        return;
    }

    public static void solve()
    {
        experiment();
    }

    public static void experiment()
    {
        String str="";
        for(int i=0;i<100000;i++)
        {
            str+=i+" ";
        }
        System.out.print(str);
    }
}