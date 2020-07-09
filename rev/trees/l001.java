import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Arrays;

public class l001 {

    public static void main(String[] args) {
        solve();
    }

    public static class Node {
        int data;
        Node left = null;
        Node right = null;

        Node(int data) {
            this.data = data;
        }

        Node() {
        }
    }

    static int idx = 0;

    public static Node constructTree(int[] arr) {
        if (idx >= arr.length || arr[idx] == -1) {
            idx++;
            return null;
        }

        Node node = new Node(arr[idx++]);
        node.left = constructTree(arr);
        node.right = constructTree(arr);

        return node;
    }

    public static void display(Node node) {
        if (node == null)
            return;

        String str = "";
        str += ((node.left != null) ? node.left.data : ".");
        str += " <- " + node.data + " -> ";
        str += ((node.right != null) ? node.right.data : ".");
        System.out.println(str);

        display(node.left);
        display(node.right);

    }

    // Basic.================================================================

    public static int size(Node node) {
        if (node == null)
            return 0;
        return (size(node.left) + size(node.right) + 1);
    }

    public static int height(Node node) {
        if (node == null)
            return -1; // return -1, height w.r.t edge, return 0, height w.r.t node.
        return Math.max(height(node.left), height(node.right)) + 1;
    }

    public static int Maximum(Node node) {
        if (node == null)
            return (int) -1e8; // java: Integer.MIN_VALUE, c++: INT_MIN;
        return Math.max(Math.max(Maximum(node.left), Maximum(node.right)), node.data); // max(leftSubtree,rightSubtree,myself);
    }

    public static int Minimum(Node node) {
        if (node == null)
            return (int) 1e8; // java: Integer.MAX_VALUE, c++: INT_MAX;
        return Math.min(Math.min(Minimum(node.left), Minimum(node.right)), node.data);
    }

    public static int Minimum_02(Node node) {
        int min_ = node.data;

        if (node.left != null)
            min_ = Math.min(min_, Minimum_02(node.left));
        if (node.right != null)
            min_ = Math.min(min_, Minimum_02(node.right));

        return min_;
    }

    public static boolean find(Node node, int data) {
        if (node == null)
            return false;

        if (node.data == data)
            return true;
        return find(node.left, data) || find(node.right, data);
    }

    // Traversal.============================================================

    public static void preOrder(Node node) {
        if (node == null)
            return;

        System.out.print(node.data + " ");
        preOrder(node.left);
        preOrder(node.right);
    }

    public static void inOrder(Node node) {
        if (node == null)
            return;

        inOrder(node.left);
        System.out.print(node.data + " ");
        inOrder(node.right);
    }

    public static void postOrder(Node node) {
        if (node == null)
            return;

        postOrder(node.left);
        postOrder(node.right);
        System.out.print(node.data + " ");
    }

    public static boolean nodeToRoot(int data, Node node, ArrayList<Node> ans) {
        if (node == null)
            return false;

        if (node.data == data) {
            ans.add(node);
            return true;
        }
        boolean res = false;

        res = res || nodeToRoot(data, node.left, ans);
        res = res || nodeToRoot(data, node.right, ans);

        if (res)
            ans.add(node);

        return res;
    }

    // levelOrdertraversal.==================================================

    public static void levelOreder_01(Node node) {
        LinkedList<Node> que = new LinkedList<>();
        que.addLast(node);
        int count = 0;
        while (que.size() != 0) {
            System.out.print("level: " + count + " ->");
            count++;
            int size = que.size();
            while (size-- > 0) {
                Node rvtx = que.removeFirst();
                if (rvtx.left != null)
                    que.addLast(rvtx.left);
                if (rvtx.right != null)
                    que.addLast(rvtx.right);

                System.out.print(rvtx.data + " ");
            }
            System.out.println();
        }
    }

    public static void levelOreder_02(Node node) {
        LinkedList<Node> que = new LinkedList<>();
        que.addFirst(node);
        que.addFirst(null);
        int count = 0;
        while (que.size() != 1) {
            int size = que.size();
            while (size-- > 0) {
                Node rvtx = que.removeFirst();
                if (rvtx.left != null)
                    que.addLast(rvtx.left);
                if (rvtx.right != null)
                    que.addLast(rvtx.right);

                System.out.print(rvtx.data + " ");
                if (que.getFirst() == null) {
                    que.removeFirst();
                    que.addLast(null);
                    System.out.print("Level: " + count + " ->");
                    count++;
                }
            }
        }
    }

    // view.=============================================================

    public static void leftView(Node node) {
        LinkedList<Node> que = new LinkedList<>(); // addLast and removeFirst.
        que.addLast(node);
        while (que.size() != 0) {
            int size = que.size();
            System.out.print(que.getFirst().data + " ");
            while (size-- > 0) {
                Node rnode = que.removeFirst();
                if (rnode.left != null)
                    que.addLast(rnode.left);
                if (rnode.right != null)
                    que.addLast(rnode.right);
            }
        }
        System.out.println();
    }

    public static void rightView(Node node) {
        LinkedList<Node> que = new LinkedList<>(); // addLast and removeFirst.
        que.addLast(node);
        while (que.size() != 0) {
            int size = que.size();
            Node prev = null;
            while (size-- > 0) {
                Node rnode = que.removeFirst();
                if (rnode.left != null)
                    que.addLast(rnode.left);
                if (rnode.right != null)
                    que.addLast(rnode.right);
                prev = rnode;
            }
            System.out.print(prev.data + " ");
        }
        System.out.println();
    }

    static int leftMinValue = 0;
    static int rightMaxValue = 0;

    public static void width(Node node, int lev) {
        if (node == null)
            return;

        leftMinValue = Math.min(leftMinValue, lev);
        rightMaxValue = Math.max(rightMaxValue, lev);

        width(node.left, lev - 1);
        width(node.right, lev + 1);
    }

    public static class pairVO {
        Node node; // actual Node
        int vl = 0; // vertical Level

        public pairVO(Node node, int vl) {
            this.node = node;
            this.vl = vl;
        }
    }

    public static void verticalOrder(Node node) {
        width(node, 0);
        int n = rightMaxValue - leftMinValue + 1;
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>(); // vector<vector<int>> (n,vector<int>());
        for (int i = 0; i < n; i++)
            ans.add(new ArrayList<>());

        LinkedList<pairVO> que = new LinkedList<>();
        que.addLast(new pairVO(node, -leftMinValue));

        while (que.size() != 0) {
            int size = que.size();
            while (size-- > 0) {
                pairVO rpair = que.removeFirst();
                ans.get(rpair.vl).add(rpair.node.data);
                if (rpair.node.left != null)
                    que.addLast(new pairVO(rpair.node.left, rpair.vl - 1));
                if (rpair.node.right != null)
                    que.addLast(new pairVO(rpair.node.right, rpair.vl + 1));
            }
        }

        for (ArrayList<Integer> ar : ans)
            System.out.println(ar);
        System.out.println();
    }

    public static void verticalOrderSum(Node node) {
        width(node, 0);
        int[] ans = new int[rightMaxValue - leftMinValue + 1];

        LinkedList<pairVO> que = new LinkedList<>();
        que.addLast(new pairVO(node, -leftMinValue));

        while (que.size() != 0) {
            int size = que.size();
            while (size-- > 0) {
                pairVO rpair = que.removeFirst();
                ans[rpair.vl] += rpair.node.data;
                if (rpair.node.left != null)
                    que.addLast(new pairVO(rpair.node.left, rpair.vl - 1));
                if (rpair.node.right != null)
                    que.addLast(new pairVO(rpair.node.right, rpair.vl + 1));
            }
        }

        for (int ar : ans)
            System.out.println(ar);
        System.out.println();
    }

    public static void bottomView(Node node){
        width(node,0);
        int[] arr=new int[rightMaxValue-leftMinValue+1];

        LinkedList<pairVO> que=new LinkedList<>();
        que.addFirst(new pairVO(node,-leftMinValue));

        while(que.size()!=0){
            int size=que.size();
            while(size-->0){
                pairVO rpair=que.removeFirst();
                arr[rpair.vl]=rpair.node.data;
                if (rpair.node.left != null)
                    que.addLast(new pairVO(rpair.node.left, rpair.vl - 1));
                if (rpair.node.right != null)
                    que.addLast(new pairVO(rpair.node.right, rpair.vl + 1));
            }
        }

        for(int e: arr)
            System.out.println(e);
        System.out.println();
    }

    public static void topView(Node node){
        width(node,0);
        int[] arr=new int[rightMaxValue-leftMinValue+1];
        Arrays.fill(arr,(int)-1e8);

        LinkedList<pairVO> que=new LinkedList<>();
        que.addFirst(new pairVO(node,-leftMinValue));

        while(que.size()!=0){
            int size=que.size();
            while(size-->0){
                pairVO rpair=que.removeFirst();
                if(arr[rpair.vl]==(int)-1e8)
                    arr[rpair.vl]=rpair.node.data;
                if (rpair.node.left != null)
                    que.addLast(new pairVO(rpair.node.left, rpair.vl - 1));
                if (rpair.node.right != null)
                    que.addLast(new pairVO(rpair.node.right, rpair.vl + 1));
            }
        }

        for(int e: arr)
            System.out.println(e);
        System.out.println();
    }

    static int leftMinDValue = 0;

    public static void Dwidth(Node node, int lev) {
        if (node == null)
            return;

        leftMinDValue = Math.min(leftMinDValue, lev);

        Dwidth(node.left, lev - 1);
        Dwidth(node.right, lev);
    }

    public static void DiagonalView(Node node){
        Dwidth(node,0);
        int n=-leftMinDValue+1;
        ArrayList<ArrayList<Integer>> ans=new ArrayList<>(); 
        for(int i=0;i<n;i++)
            ans.add(new ArrayList<>());

        LinkedList<pairVO> que=new LinkedList<>();
        que.addLast(new pairVO(node,-leftMinDValue));

        while(que.size()!=0)
        {
            int size=que.size();
            while(size-->0)
            {
                pairVO rpair=que.removeFirst();
                ans.get(rpair.vl).add(rpair.node.data);
                if (rpair.node.left != null)
                    que.addLast(new pairVO(rpair.node.left, rpair.vl - 1));
                if (rpair.node.right != null)
                    que.addLast(new pairVO(rpair.node.right, rpair.vl + 0));
            }
        }
        for (ArrayList<Integer> ar : ans)
            System.out.println(ar);
        System.out.println();
    }

    //pred and succ.====================================================

    public static class allSolution{
        int height = 0;
        int size=0;
        boolean find=false;
 
        Node pred=null;
        Node succ=null;
        Node prev=null;
    }
 
    public static void allSol(Node node,int data,int level,allSolution pair){
     if(node==null) return;
     pair.size++;
     pair.height=Math.max(pair.height,level);
     pair.find= pair.find || node.data==data;
     
     if(node.data==data && pair.pred==null) pair.pred=prev;
     if(pair.prev!=null && pair.prev.data == data && pair.succ==null) pair.succ=node;
     pair.prev=node;
     
      allSol(node.left,data,level+1,pair);
      allSol(node.right,data,level+1,pair);
    }

    //morris traversal.=================================================

    public static Node AllRight_of_LeftNode(Node lnode,Node curr)
    {
        while(lnode.right!=null && lnode.right!=curr)
        {
            lnode=lnode.right;
        }
        return lnode;
    }

    // public static void morrisInOrder(Node root)
    // {
    //     while(root.left!=null)
    //     {
    //         root=root.left;
    //         if(root.left==null)
    //     }
    // }

    public static void view(Node node) {
        // leftView(node);
        // rightView(node);
        // verticalOrder(node);
        // bottomView(node);
        // topView(node);
        DiagonalView(node);
    }

    public static void levelOreder(Node root) {
        // levelOreder_01(root);
        levelOreder_02(root);
    }

    public static void solve() {
        // int[] arr = { 10, 20, 40, -1, -1, 50, 80, -1, -1, 90, -1, -1, 30, 60, 100, -1, -1, -1, 70, 110, -1, -1, 120, -1,-1 };
        int[] arr=   {11,6,4 ,-1, 5 ,-1, -1, 8, -1, 10, -1, -1, 19, 17, -1, -1, 43, 31, -1, -1, 49, -1, -1};
        Node root = constructTree(arr);
        display(root);
        ArrayList<Node> ans = new ArrayList<>();
        nodeToRoot(60, root, ans);
        for (Node e : ans)
            System.out.print(e.data + "->");

        System.out.println();
        // levelOreder(root);

        view(root);
    }

}