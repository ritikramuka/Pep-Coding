import java.util.*;
public class BST{
    static class Node{
        int data=0;
        Node left;
        Node right;

        Node(){
        }

        Node(int data,Node left,Node right)
        {
            this.data=data;
            this.left=left;
            this.right=right;
        }
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

    public static construct(int[] sa,int lo,int hi)
    {
        if(lo>hi)
        {
            return null;
        }

        Node node=new Node;
        int mid=(lo+hi)/2;
        node.data=sa[mid];
        node.left=construct(sa,lo,mid-1);
        node.right=construct(sa,mid+1,hi);

        return node;
        
    }

    static int max(Node node)
    {
        if(node==null)
        {
            return node.data;
        }
        else
            return max(node.right);
    }

    static int min(Node node)
    {
        if(node==null)
        {
            return node.data;
        }
        else
            return min(node.left);
    }

    public static Boolean find(Node node)
    {

    }

    public static void main(String[] args)
    {
        int[] sa={12,25,37,50,62,75,87};
        Node root=construct(sa,0,sa.length-1);
        display(root);
    }
}