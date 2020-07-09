import java.util.Scanner;
import java.util.ArrayList;


public class numberOfPath{
    public static Scanner sc = new Scanner(System.in);

    public static  void main(String[] args){
          int n = sc.nextInt();
          int m = sc.nextInt();
          ArrayList<String> arr_simple = new ArrayList<>();
          ArrayList<String> arr_diagonal = new ArrayList<>();
          
          arr_simple = print_path_simple(0,0,n,m);
          arr_diagonal = print_path_diagonal(0,0,n,m);

          System.out.println(arr_simple);
          System.out.println(arr_diagonal);


    }

    public static ArrayList<String> print_path_simple(int sr,int sc,int er, int ec){

        if(er == sr && ec == sc){ 
            ArrayList<String> baseAns = new ArrayList<>();
            baseAns.add("");
            return baseAns;
        }

        ArrayList<String> myAns = new ArrayList<>();
        if(sc+1 <= ec){
        ArrayList<String> horizontalans = print_path_simple(sr,sc+1,er,ec);
        for(String smallans : horizontalans){
            String realans = "H" + smallans;
            myAns.add(realans); 
        }
        }
        
        if(sr+1 <= er){
        ArrayList<String> verticalans = print_path_simple(sr+1,sc,er,ec);
        for(String smallans : verticalans){
            String realans = "V" + smallans;
            myAns.add(realans); 
        }
        }

       return myAns;

  }

  public static ArrayList<String> print_path_diagonal(int sr,int sc,int er, int ec){

    if(er == sr && ec == sc){ 
        ArrayList<String> baseAns = new ArrayList<>();
        baseAns.add("");
        return baseAns;
    }

    ArrayList<String> myAns = new ArrayList<>();
    if(sc+1 <= ec){
    ArrayList<String> horizontalans = print_path_diagonal(sr,sc+1,er,ec);
    for(String smallans : horizontalans){
        String realans = "H" + smallans;
        myAns.add(realans); 
    }
    }

    if(sc+1 <= ec && sr+1 <= er){
        ArrayList<String> diagonalans = print_path_diagonal(sr+1,sc+1,er,ec);
        for(String smallans : diagonalans){
            String realans = "D" + smallans;
            myAns.add(realans); 
        }
        }
    
    if(sr+1 <= er){
    ArrayList<String> verticalans = print_path_diagonal(sr+1,sc,er,ec);
    for(String smallans : verticalans){
        String realans = "V" + smallans;
        myAns.add(realans); 
    }
    }

   return myAns;

}

}



