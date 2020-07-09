import java.util.Scanner;
import java.util.ArrayList;
public class jumpInArray{
    public static void main(String[] args)
    {

       // System.out.print(AllJumps(0,10));
       System.out.print(AllJumps2(0,10));
    }

    public static ArrayList<String> AllJumps(int si, int ei)
    {
        if(si==ei)
        {
           ArrayList<String> base=new ArrayList<>();
           base.add(" ");
           return base; 
        }

        ArrayList<String> myans=new ArrayList<>();
        if(si+1<=ei)
        {
            ArrayList<String> arr=AllJumps(si+1,ei);
            for( String s : arr )
            {
                String realAns=(1+s);
                myans.add(realAns);
            }
        } 
         if(si+2<=ei)
        {
            ArrayList<String> arr=AllJumps(si+2,ei);
            for( String s : arr )
            {
                String realAns=(2+s);
                myans.add(realAns);
            }
        } 
         if(si+3<=ei)
        {
            ArrayList<String> arr=AllJumps(si+3,ei);
            for( String s : arr )
            {
                String realAns=(3+s);
                myans.add(realAns);
            }
        } 
         if(si+4<=ei)
        {
            ArrayList<String> arr=AllJumps(si+4,ei);
            for( String s : arr )
            {
                String realAns=(4+s);
                myans.add(realAns);
            }
        } 
         if(si+5<=ei)
        {
            ArrayList<String> arr=AllJumps(si+5,ei);
            for( String s : arr )
            {
                String realAns=(5+s);
                myans.add(realAns);
            }
        } 
         if(si+6<=ei)
        {
            ArrayList<String> arr=AllJumps(si+6,ei);
            for( String s : arr )
            {
                String realAns=(6+s);
                myans.add(realAns);
            }
        } 
        return myans;
    }
    public static ArrayList<String> AllJumps2(int si, int ei)
    {
           if(si==ei)
        {
           ArrayList<String> base=new ArrayList<>();
           base.add(" ");
           return base; 
        }
        ArrayList<String> myans=new ArrayList<>();
        for(int steps=1;steps<=6 && si+steps<=ei;steps++)
        {
            ArrayList<String>recans=AllJumps2(si+steps,ei);
            for(String s:recans)
            {
                String realans=(steps+s);
                myans.add(realans);
            }
        }
        return myans;
    }
}