import java.util.*;
import java.util.ArrayList;

public class bidirectionalGraph {
    private static class Edges {
        int V1;
        int V2;
        int weight;

        private Edges(int V1, int V2, int weight) {
            this.V1 = V1;
            this.V2 = V2;
            this.weight = weight;
        }
    }

    private static ArrayList<ArrayList<Edges>> graph = new ArrayList<>();
    private static int noOfEdges = 0;

    // vertices.=========================================================================

    public static void addvertix(int V1) {
        if (graph.size() == V1) {
            graph.add(new ArrayList<>());
        }
    }

    // Edge.==============================================================================

    public static void addEdge(int V1, int V2, int weight) {
        if (graph.size() > V1 && graph.size() > V2) {
            graph.get(V1).add(new Edges(V1, V2, weight));
            graph.get(V2).add(new Edges(V2, V1, weight));
            noOfEdges++;
        }
    }

    // totalEdges without using global
    // noOfEdges.========================================

    public static int totalEdges() {
        int count = 0;
        for (int i = 0; i < graph.size(); i++) {
            count += graph.get(i).size();
        }
        return count / 2;
    }

    // Display.===========================================================================

    public static void Display() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < graph.size(); i++) {
            for (Edges e : graph.get(i)) {
                sb.append("(" + e.V1 + "," + e.V2 + ")" + "@" + e.weight + " ");
            }
            sb.append("\n");
        }
        System.out.print(sb.toString());
    }

    // remove
    // edge.=======================================================================

    public static void removeEdge(int V1, int V2) {
        int idx1 = GetIdx(V1, V2);
        if (idx1 != -1)
            graph.get(V1).remove(idx1);

        int idx2 = GetIdx(V2, V1);
        if (idx2 != -1)
            graph.get(V2).remove(idx2);
    }

    // remove
    // Vertex.======================================================================

    public static void removeVertex(int V1) {
        for (int i = 0; i < graph.get(V1).size(); i++) {
            Edges e = graph.get(V1).get(i);
            int idx = GetIdx(e.V2, e.V1);
            graph.get(e.V2).remove(idx);
        }
        graph.remove(V1);
    }

    // contain
    // edge.=======================================================================

    public static boolean containEdge(int V1, int V2) {
        if (V1 < graph.size() && V2 < graph.size() && GetIdx(V1, V2) != -1) {
            return true;
        }
        return false;
    }

    // has
    // path.==========================================================================

    public static void hasPath() {
        boolean[] isVisited = new boolean[graph.size()];
        hasPath(0, 6, isVisited, "");
    }

    public static boolean hasPath(int src, int desti, boolean[] isVisited, String ans) {
        if (src == desti) {
            System.out.print(ans + " -> " + "true");
            return true;
        }

        isVisited[src] = true;
        for (Edges e : graph.get(src)) {
            if (isVisited[e.V2])
                continue;

            boolean res = hasPath(e.V2, desti, isVisited, ans + src + " ");
            if (res)
                return true;
        }
        return false;
    }

    // all
    // path.===========================================================================

    public static void AllPath() {
        boolean[] isVisited = new boolean[graph.size()];
        AllPath(0, 6, isVisited, "");
    }

    public static void AllPath(int src, int desti, boolean[] isVisited, String ans) {
        if (src == desti) {
            System.out.println(ans);
            return;
        }

        isVisited[src] = true;
        for (Edges e : graph.get(src)) {
            if (isVisited[e.V2])
                continue;

            AllPath(e.V2, desti, isVisited, ans + src + " ");
        }
        isVisited[src] = false;
        return;
    }

    // ==================================linkedlist.=======================================//

    // BFS.And.DFS================================================================================

    public static void BFSandDFS() {
        boolean[] isVisited = new boolean[graph.size()];
        // BFS(0, 6,isVisited);
        // BFTComponents();
        DFTComponent();
    }

    public static class BFSpair {
        int vtx = 0;
        int wsf = 0;
        String psf = "";
        int noOfEdges = 0;

        BFSpair(int vtx, int wsf, String psf, int noOfEdges) {
            this.vtx = vtx;
            this.wsf = wsf;
            this.psf = psf;
            this.noOfEdges = noOfEdges;
        }
    }

    public static void BFS(int src, int desti, boolean[] isVisited) {

        LinkedList<BFSpair> que = new LinkedList<>();

        que.addLast(new BFSpair(src, 0, src + "", 0));

        while (!que.isEmpty()) {
            BFSpair rpair = que.removeFirst();
            if (isVisited[rpair.vtx]) { // spotted cycle.
                System.out.println("Cycle : " + rpair.vtx + " via " + rpair.psf);
                continue;
            }
            isVisited[rpair.vtx] = true;

            if (rpair.vtx == desti) { // sppoted destination.
                System.out.println("Desti : " + rpair.vtx + " via " + rpair.psf);
                // return;
            }
            System.out.println(rpair.vtx + " via " + rpair.psf);

            for (Edges e : graph.get(rpair.vtx)) {
                if (!isVisited[e.V2]) { // if it is marked then leave this children.
                    que.addLast(new BFSpair(e.V2, rpair.wsf + e.weight, rpair.psf + e.V2, rpair.noOfEdges + 1));
                }
            }
        }
    }

    public static void BFTComponents() {
        boolean[] isVisited = new boolean[graph.size()];
        int components = 0;
        removeEdge(3, 4);
        for (int i = 0; i < graph.size(); i++) {
            if (!isVisited[i]) {
                BFS(i, 6, isVisited);
                System.out.println();
                components++;
            }
        }

        System.out.println(components);
    }

    public static void DFSRec(int src, boolean[] isVisited, String psf) {
        isVisited[src] = true;
        System.out.println(src + " via " + psf);

        for (Edges e : graph.get(src)) {
            if (!isVisited[e.V2])
                DFSRec(e.V2, isVisited, psf + e.V2);
        }

        isVisited[src] = false;
    }

    public static void DFTComponent() {
        boolean[] isVisited = new boolean[graph.size()];
        int components = 0;
        removeEdge(3, 4);
        for (int i = 0; i < graph.size(); i++) {
            if (!isVisited[i]) {
                DFSRec(i, isVisited, i + "");
                System.out.println();
                components++;
            }
        }

        System.out.println(components);
    }

    // some Ques using BFS and
    // DFS.========================================================

    private static int noOfCycles(int src, boolean[] isVisited) {

        LinkedList<BFSpair> que = new LinkedList<>();

        que.addLast(new BFSpair(src, 0, src + "", 0));
        int count = 0;

        while (!que.isEmpty()) {
            BFSpair rpair = que.removeFirst();
            if (isVisited[rpair.vtx]) { // spotted cycle.
                count++;
                continue;
            }
            isVisited[rpair.vtx] = true;

            for (Edges e : graph.get(rpair.vtx)) {
                if (!isVisited[e.V2]) {
                    que.addLast(new BFSpair(e.V2, rpair.wsf + e.weight, rpair.psf + e.V2, rpair.noOfEdges + 1));
                }
            }
        }
        return count;
    }

    public static boolean isCyclic() {
        boolean[] isVisited = new boolean[graph.size()];
        int Cycles = 0;
        for (int i = 0; i < graph.size(); i++) {
            if (!isVisited[i]) {
                Cycles += noOfCycles(0, isVisited);
            }
        }
        return Cycles > 0 ? true : false;
    }

    public static boolean ComponentCycles() {
        boolean[] isVisited = new boolean[graph.size()];
        int Cycles = 0;
        int component = 0;
        for (int i = 0; i < graph.size(); i++) {
            if (!isVisited[i]) {
                component++;
                Cycles = noOfCycles(0, isVisited);
                System.out.println("component no. " + component + " : cycles " + Cycles);
            }
        }
        return component > 0 ? true : false;
    }

    public static boolean isConnected() {
        boolean[] isVisited = new boolean[graph.size()];
        int component = 0;
        for (int i = 0; i < graph.size(); i++) {
            if (!isVisited[i]) {
                component++;
                noOfCycles(0, isVisited);
            }
        }
        return component == 0 ? true : false;
    }

    // BiPitrated.========================================================================

    public static class BiPitratedPair {
        int vtx = 0;
        String color = "R";

        BiPitratedPair(int vtx, String color) {
            this.vtx = vtx;
            this.color = color;
        }
    }

    public static boolean isBipitrated(int src) {
        LinkedList<BiPitratedPair> que = new LinkedList<>();

        que.addLast(new BiPitratedPair(src, "R"));
        while (!que.isEmpty()) {
            BiPitratedPair[] isVisited = new BiPitratedPair[graph.size()];
            BiPitratedPair rpair = que.removeFirst();

            if (isVisited[rpair.vtx] != null) {
                String oldcolor = isVisited[rpair.vtx].color;
                String newcolor = rpair.color;
                if (!oldcolor.equals(newcolor))
                    return false;
                continue;
            }

            isVisited[rpair.vtx] = rpair;
            for (Edges e : graph.get(rpair.vtx)) {
                if (isVisited[e.V2] == null) {
                    String color;
                    color = rpair.color.equals("R") ? "G" : "R";
                    que.addLast(new BiPitratedPair(e.V2, color));
                }
            }
        }
        return true;
    }

    public static boolean totalBipitrated(int src) {
        LinkedList<BiPitratedPair> que = new LinkedList<>();

        que.addLast(new BiPitratedPair(src, "R"));
        while (!que.isEmpty()) {
            BiPitratedPair[] isVisited = new BiPitratedPair[graph.size()];
            BiPitratedPair rpair = que.removeFirst();

            if (isVisited[rpair.vtx] != null) {
                String oldcolor = isVisited[rpair.vtx].color;
                String newcolor = rpair.color;
                if (!oldcolor.equals(newcolor))
                    return false;
                continue;
            }

            isVisited[rpair.vtx] = rpair;
            for (Edges e : graph.get(rpair.vtx)) {
                if (isVisited[e.V2] == null) {
                    String color;
                    color = rpair.color.equals("R") ? "G" : "R";
                    que.addLast(new BiPitratedPair(e.V2, color));
                }
            }
        }
        return true;
    }

    // BombWater.=========================================================================

    public static int BombAndWater(int[][] mat, boolean[][] isvisited, int bno) {
        if (bno == mat.length * mat[0].length) {
            return 0;
        }

        int[][] dir = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        int maxTime = 0;
        for (int d = 0; d < dir.length; d++) {
            int r = dir[d][0] + bno / mat[0].length;
            int c = dir[d][1] + bno % mat[0].length;

            if (r < mat.length && c < mat[0].length && r >= 0 && c >= 0 && mat[r][c] == 1 && !isvisited[r][c]) {
                isvisited[r][c] = true;
                int recAns = BombAndWater(mat, isVisited, bno + 1);
                maxTime = Math.max(maxTime, recAns) + 1;
                isvisited[r][c] = false;
            }
        }
        return maxTime;
    }

    private static class BAWPair {
        int r;
        int c;
        int time;

        public BAWPair(int r, int c, int time) {
            this.r = r;
            this.c = c;
            this.time = time;
        }
    }

    public static int BombAndWaterBFS(int[][] mat) {

        boolean[][] isVisited = new boolean[mat.length][mat[0].length];
        int[][] dir = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        int minTime = 0;

        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                if (isVisited[i][j] == false && mat[i][j] == 1) {
                    LinkedList<BAWPair> que = new LinkedList<>();
                    que.addLast(new BAWPair(i, j, 0));

                    while (!que.isEmpty()) {

                        BAWPair rpair = que.removeFirst();

                        minTime = Math.max(minTime, rpair.time);

                        for (int d = 0; d < dir.length; d++) {
                            int r = dir[d][0] + rpair.r;
                            int c = dir[d][1] + rpair.c;

                            if (r < mat.length && c < mat[0].length && r >= 0 && c >= 0 && mat[r][c] == 1
                                    && !isvisited[r][c]) {
                                isVisited[r][c] = true;
                                que.addLast(new BAWPair(r, c, rpair.time + 1));
                                // isVisited[r][c]=false;
                            }

                        }
                    }
                }
            }
        }
    }

    // Dijeckstra.=========================================================================

    private static class DijikstrPair implements Comparable<DijikstrPair> {
        int vtx = 0;
        int csf = Integer.MAX_VALUE;
        String psf = "";
        int noe = 0;
        int avtx = 0;

        public DijikstrPair(int vtx, int avtx, int csf, String psf, int noe) {
            this.vtx = vtx;
            this.avtx = avtx;
            this.csf = csf;
            this.psf = psf;
            this.noe = noe;

        }

        @Override
        public int compareTo(DijikstrPair o) {
            return this.csf - o.csf;
        }
    }

    public static void DijikstrAlgo(int src) {

        // ArrayList<ArrayList<Edge>> dgraph=new ArrayList<>();

        PriorityQueue<DijikstrPair> pq = new PriorityQueue<>();
        DijikstrPair[] maping = new DijikstrPair[graph.size()];
        boolean[] isVisited = new boolean[graph.size()];

        for (int i = 0; i < graph.size(); i++) {
            DijikstrPair p = new DijikstrPair(i, Integer.MAX_VALUE, "", 0);
            if (i == src) {
                p.csf = 0;
                p.psf = i + "";
                p.avtx = -1;
            }

            maping[i] = p;
            pq.add(p);
        }

        while (!pq.isEmpty()) {
            DijikstrPair rpair = pq.remove();
            isVisited[rpair.vtx] = true;

            // dgraph.addVertex(rpair.vtx);
            // if(rpair.avtx!=-1){
            // addEdge(dgraph,rpair.vtx,rpair.avtx,rpair.weight);
            // }

            if (rpair.vtx == 6) {
                System.out.println(rpair.csf + " " + rpair.psf + " " + rpair.noe);
            }

            for (Edge e : graph.get(rpair.vtx)) {
                if (isVisited[e.v2])
                    continue;

                DijikstrPair oldPair = maping[e.v2];
                int oldcsf = oldPair.csf;
                int newcsf = rpair.csf + e.weight;
                if (newcsf < oldcsf) {
                    DijikstrPair p = new DijikstrPair(e.v2, rpair.vtx, newcsf, rpair.psf + e.v2, rpair.noe + 1);

                    maping[e.v2] = p;
                    pq.remove(oldPair);
                    pq.add(p);
                }
            }
        }
    }

    // main.===============================================================================

    private static int GetIdx(int V1, int V2) {
        for (int i = 0; i < graph.get(V1).size(); i++) {
            Edges e = graph.get(V1).get(i);
            if (e.V2 == V2)
                return i;
        }
        return -1;
    }

    public static void solve() {
        for (int i = 0; i < 7; i++) {
            addvertix(i);
        }

        addEdge(0, 1, 10);
        addEdge(0, 3, 40);
        addEdge(1, 2, 10);
        addEdge(2, 3, 10);
        addEdge(3, 4, 2);
        addEdge(4, 5, 2);
        addEdge(4, 6, 8);
        addEdge(5, 6, 3);

        // Display();

        // System.out.println(totalEdges());

        // removeEdge(2,3);

        // Display();

        // removeVertex(3);

        // Display();

        // System.out.println(containEdge(2,3));

        // hasPath();

        // AllPath();

        // isCyclic();

        // ComponentCycles();

        // isConnected();

        System.out.print(isBipitrated(0));

    }

    public static void main(String[] args) {
        solve();
    }
}