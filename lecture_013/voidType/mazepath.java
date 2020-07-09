import java.util.Scanner;
public class mazepath{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] args){
        
        int n=scn.nextInt();
        int m=scn.nextInt();

        int f=puzzletypeOne(0,0,n,m,"");
        System.out.println(f);

        int p=puzzletypeTwo(0,0,n,m,"");
        System.out.println(p);

        int d=puzzletypeThree(0,0,n,m,"");
        System.out.println(d);

    }
    public static int puzzletypeOne(int sr,int sc,int er,int ec,String ans)
    {
        int count=0;
        if(sr==er && sc==ec)
        {
            System.out.println(ans);
            return 1;
        }
        if(sc+1<=ec){
            count+=puzzletypeOne(sr,sc+1,er,ec,ans+"H");
        }

        if(sr+1<=er){
            count+=puzzletypeOne(sr+1,sc,er,ec,ans+"V");
        }
        return count;
    }
    public static int puzzletypeTwo(int sr,int sc,int er,int ec,String ans)
    {
        int count=0;
        if(sr==er && sc==ec)
        {
            System.out.println(ans);
            return 1;
        }

        if(sc+1<=ec && sr+1<=er){
            count+=puzzletypeTwo(sr+1,sc+1,er,ec,ans+"D");
        }

        if(sc+1<=ec){
            count+=puzzletypeTwo(sr,sc+1,er,ec,ans+"H");
        }


        if(sr+1<=er){
            count+=puzzletypeTwo(sr+1,sc,er,ec,ans+"V");
        }
        return count;
    }

    public static int puzzletypeThree(int sr,int sc,int er,int ec,String ans)
    {
        int count=0;
        if(sr==er && sc==ec)
        {
            System.out.println(ans);
            return 1;
        }

        for(int i=1;sc+i<=ec && sr+i<=er;i++){
            count+=puzzletypeThree(sr+1,sc+1,er,ec,ans+"D"+i);
        }

        for(int i=1;sc+i<=ec;i++){
            count+=puzzletypeThree(sr,sc+1,er,ec,ans+"H"+i);
        }

        for(int i=1;sr+i<=er;i++){
            count+=puzzletypeThree(sr+1,sc,er,ec,ans+"V"+i);
        }
        return count;
    }
}