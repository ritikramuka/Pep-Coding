import java.util.*;
public class graphBasics{
    private static class Edges{
       public:

        int v1;
        int v2;
        int weight;

    private Edges(int v1,int v2,int weight)
    {
        this.v1=v1;
        this.v2=v2;
        this.weight=weight;
    }
}

private static ArrayList<ArrayList<Edges>> graph=new ArrayList<>();
private static int noOfEdges=0;

public static void AddVertices(int v1)
{
    if(v1==graph.size())
    {
        graph.add(new ArrayList<>());
    }
}

public static void AddEdge(int v1,int v2,int weight)
{
    if(v1<graph.size() && v2<graph.size())
    {
        graph.get(v1).add(new Edges(v1,v2,weight));
        graph.get(v2).add(new Edges(v1,v2,weight));
        noOfEdges++;
    }
}

public static void display()
{
    StringBuilder sb=new StringBuilder();
    for(int i=0;i<graph.size();i++)
    {
        for(Edges e : graph.get(i))
        {
            sb.append("("+e.v1+","+e.v2+")"+"@"+e.weight);
        }
        sb.append("\n");
    }
    System.out.print(sb.toString());
}

public static void removeEdges(int v1 ,int v2)
{
    int idx1=GetIdx(v1,v2);
    graph.get(v1).remove(idx1);
    
    int idx2=GetIdx(v2,v1);
    graph.get(v2).remove(idx2);
}

public static void removeVertices(int v1)
{
    for(int i=0;i<graph.size();i++)
    {
        Edges e=graph.get(v1).get(i);
        int indx2=GetIdx(e.v2,e.v1);
        graph.get(e.v2).remove(indx2);
    }
    graph.remove(v1);
}

public static boolean containEdge(int v1,int v2)
{
    if(v1<graph.size() && v2<graph.size() && GetIdx(v1,v2)!=-1)
    return true;

    return false;
}

public static void Allpath()
{
    boolean[] isvisited=new boolean[graph.size()];
    allPath(0,6,isvisited,"");
}

public static void allPath(int src,int desti,boolean[] isvisited,String ans)
{
    if(src == desti)
    {
        System.out.print(ans);
        return;
    }

    isvisited[src]=true;
    for(Edges e : graph.get(src))
    {
        if(isvisited[e.v2])
        continue;

        allPath(e.v2,desti,isvisited,ans+src+" ");
    }
    isvisited[src]=false;

    return;
}

public static int GetIdx(int v1,int v2)
{
    for(int i=0;i<graph.get(v1).size();i++)
    {
        Edges e=graph.get(v1).get(i);
        if(e.v2==v2)
        return i;
    }
    return -1;
}

public static void solve()
    {
        for(int i=0;i<7;i++)
        {
            AddVertices(i);
        }

        AddEdge(0,1,10);
        AddEdge(0,3,40);
        AddEdge(1,2,10);
        AddEdge(2,3,10);
        AddEdge(3,4,2);
        AddEdge(4,5,2);
        AddEdge(4,6,8);
        AddEdge(5,6,3);

        display();

        // System.out.println(totalEdges());

        removeEdges(2,3);

        display();
        
        removeVertices(3);

        display();

        System.out.println(containEdge(2,3));

        Allpath();

    }

    public static void main(String[] args)
    {
        solve();
    }
}
