import java.util.ArrayList;
import java.util.LinkedList;
public class bidirectionalGraph{
    public static void main(String[] args)
    {
        solve();
    }

    public static ArrayList<Integer>[] graph;
    public static int N=8;

    public static void display()
    {
        for(int i=0;i<graph.length;i++){
            for(Integer e : graph[i])
                System.out.print(e+" ");
            System.out.println();
        }
    }

    //topological sort=================================================

    // public static void topologicalSort_(Integer src,boolean[] vis,ArrayList<Integer> ans)
    // {
    //     vis[src]=true;
    // }

    // public static void topologicalSort()
    // {
    //     boolean[] vis=new boolean[N];
    //     ArrayList<Integer> ans=new ArrayList<>();
    //     for(int i=0;i<N;i++)
    //         if(!vis[graph[i]])
    //             topologicalSort_(graph[i],vis,ans);
    // }

    public static void constructGraph()
    {
        graph=new ArrayList[N];
        for(int i=0;i<N;i++)
        {
            graph[i]=new ArrayList<Integer>();
        }

        display();
    }

    public static void solve(){
        constructGraph();
    }
}