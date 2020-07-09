import java.util.*;
public class binarytree{
    public static class Node{
        int data=0;
        Node left=null;
        Node right=null;

        Node(){    
        }

        Node(int data,Node left,Node right)
        {
            this.data=data;
            this.left=left;
            this.right=right;
        }
    }
    static Node root=null;
    static int idx=0;

    public static  Node construct(int[] arr)
    {
        if(idx>=arr.length || arr[idx]== -1)
        {
            idx++;
            return null;
        }
        Node node=new Node(arr[idx],null,null);
        idx++;
        node.left=construct(arr);
        node.right=construct(arr);

        return node;
    }

    public static void display(Node node)
    {
        if(node==null)
        return;

        String str="";
        str+=node.left!=null?node.left.data+"-> " : ". ->";
        str+=node.data;
        str+=node.right!=null?"<- " +node.right.data : "<- .";
        System.out.println(str);

        display(node.left);
        display(node.right);
    }

    public static int maxval(Node node)
    {
        if(node==null)
        {
            return Integer.MIN_VALUE;
        }
        int ls=maxval(node.left);
        int rs=maxval(node.right);
        return Math.max(node.data,Math.max(ls,rs));
    }

    public static ArrayList<Node> rootToNodePath(Node root,int data)
    {
        if(root==null)
        {
            return new ArrayList<>();
        }

        if(data==root.data)
        {
            ArrayList<Node> list=new ArrayList<>();
            list.add(root);
            return list;
        }

        ArrayList<Node> rtnpfl=rootToNodePath(root.left,data);
        if(rtnpfl.size()>0)
        {
            rtnpfl.add(root);
            return rtnpfl;
        }

        ArrayList<Node> rtnpfr=rootToNodePath(root.right,data);
        if(rtnpfr.size()>0)
        {
            rtnpfr.add(root);
            return rtnpfr;
        }
        return new ArrayList<>();
    }

    public static boolean rootToNodePath(Node root,int data,ArrayList<Node> path)
    {
        if(root==null)
        return false;
        if(root.data==data)
        {
            path.add(root);
            return true;
        }

        if(rootToNodePath(root.left,data,path))
        {
            path.add(root);
            return true;
        }
        
        if(rootToNodePath(root.right,data,path))
        {
            path.add(root);
            return true;
        }
        return false;
    }

    public static void leafNode(Node root)
    {
        if(root==null)
            return;
        
        if(root.left==null && root.right==null)
        {
            System.out.print(root.data+" ");
            return;
        }

        leafNode(root.left);
        leafNode(root.right);
    }

    //simple
    public static void levelorder_01(Node root)
    {
        LinkedList<Node> que=new LinkedList<>();
        que.addLast(root);
        while(!que.isEmpty())
        {
            Node node=que.removeFirst();
            System.out.println(node.data);
            if(node.left!=null)
            {
                que.addLast(node.left);
            }
            if(node.right!=null)
            {
                que.addLast(node.right);
            }
        }
    }

    //line wise
    public static void levelorder_02(Node root)
    {
        LinkedList<Node> que=new LinkedList<>();
        que.addLast(root);
        while(!que.isEmpty())
        {
            int size=que.size();
            while(size --> 0)
            {
                Node node=que.removeFirst();
                System.out.print(node.data+" ");
                if(node.left!=null)
                {
                    que.addLast(node.left);
                }
                if(node.right!=null)
                {
                    que.addLast(node.right);
                }
            }
            System.out.println();
        }
    }

    static void levelorder_03(Node root)
    {
        LinkedList<Node> q1=new LinkedList<>();
        LinkedList<Node> q2=new LinkedList<>();
        q1.addLast(root);
        while(!q1.isEmpty())
        {
            Node node=q1.removeFirst();
            System.out.print(node.data+" ");
            if(node.left!=null)
            {
                q2.addLast(node.left);
            }
            if(node.right!=null)
            {
                q2.addLast(node.right);
            }
            if(q1.isEmpty())
            {
                System.out.println();
                while(!q2.isEmpty())
                {
                    Node swap=q2.removeFirst();
                    q1.addLast(swap);
                }
            }
        }
    }

    static void ZigZag_01(Node root)
    {
        LinkedList<Node> stack=new LinkedList<>();
        LinkedList<Node> q2=new LinkedList<>();
        stack.addFirst(root);
        boolean lefttoright=true;
        while(!stack.isEmpty())
        {
            Node node=stack.removeFirst();
            System.out.print(node.data+" ");
            if(lefttoright)
            {
                if(node.left!=null)
                {
                    q2.addLast(node.left);
                }
                if(node.right!=null)
                {
                    q2.addLast(node.right);
                }
            }
            if(!lefttoright)
            {
                if(node.right!=null)
                {
                    q2.addLast(node.right);
                }

                if(node.left!=null)
                {
                    q2.addLast(node.left);
                }
            }

            if(stack.isEmpty())
            {
                System.out.println();
                while(!q2.isEmpty())
                {
                    Node swap=q2.removeFirst();
                    stack.addFirst(swap);
                }
                lefttoright=!lefttoright;
            }
        }
    }

    public static void main(String[] args)
    {
        int arr[]={10,20,40,80,-1,-1,90,-1,-1,50,100,-1,-1,-1,30,60,-1,110,-1,-1,70,120,-1,-1,-1};
        root=construct(arr);
        // display(root);
        // System.out.println(maxval(root));
        // ArrayList<Node> ll=rootToNodePath(root,120);
        // for(int i=0;i<ll.size();i++)
        // System.out.println(ll.get(i).data);
        // ArrayList<Node> ans=new ArrayList<>();
        // rootToNodePath(root,120,ans);
        // for(int i=0;i<ans.size();i++)

        // System.out.println(ans.get(i).data);
        // leafNode(root);
        //levelorder_03(root);
        ZigZag_01(root);
    }
}