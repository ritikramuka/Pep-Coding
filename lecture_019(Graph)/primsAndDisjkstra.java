import java.util.*;
public class primsAndDisjkstra{
    public static void main(String[] args)
    {
        ArrayList<ArrayList<Edge>> graph = new ArrayList<>();

        for(int i=0;i<7;i++)
        {
            graph.add(new ArrayList<>());
        }

        addEdge(graph,0,1,10);
        addEdge(graph,0,3,40);
        addEdge(graph,1,2,10);
        addEdge(graph,2,3,10);
        addEdge(graph,3,4,2);
        addEdge(graph,4,5,2);
        addEdge(graph,4,6,8);
        addEdge(graph,5,6,3);

        display(graph);
        primAlgo(graph);
    }

    public class bidirectionalGraph{
    private static class Edges
    {
        int V1;
        int V2;
        int weight;

        private Edges(int V1, int V2, int weight)
        {
            this.V1=V1;
            this.V2=V2;
            this.weight=weight;
        }
    }

    public static void primAlgo(ArrayList<ArrayList<Edge>> graph)
    {
        class primsPair implements comparable<primsPair>
        {
            int vtx;
            int csf=Integer.MAX_VALUE;
            int avtx=0;

            public primsPair(int vtx,int csf,int avtx)
            {
                this.vtx=vtx;
                this.csf=csf;
                this.avtx=avtx;
            } 

            @override
            public int compareTo(primsPair o)
            {
                return this.cst-o.cst;
            }
        }

        ArrayList<ArrayList<Edges>> primGraph = new ArrayList<>();
        for(int i=0;i<graph.size();i++)
        {
            primsGraph.add(new ArrayList<>());
        }

        PriorityQueue<primsPair> pq=new PriorityQueue<>();

        pq.add(new primsPair(0,0,-1));

        boolean[] isVisited=new boolean[graph.size()];

        while(!)
    }


}