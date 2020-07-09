import java.util.*;
public class binaryTree{
    static class Node{
        int data;
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
    {
        Node root=null;
        Stack<Node> stack=new Stack<>();
        for(int val : arr)
        {
            if(val==-1)
                stack.pop();
            else{
                Node node=new Node();
                if(stack.isEmpty()){ 
                    node.data = val;
                    root=node;
                }
                else{
                    
                    node.data = val;

                    if(stack.peek().left == null)
                        stack.peek().left=node;
                    else
                        stack.peek().right=node;
                }
                stack.push(node);
            }
        }
        return root;
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

    public static int size(Node node)
    {
        if(node==null)
        return 0;

        int ls =size(node.left);
        int rs =size(node.right);
        return ls+rs+1;
    }

    public static int max_ (Node node)
    {
        if(node==null)
            return Integer.MIN_VALUE;
        
        int lm=max_(node.left);
        int rm=max_(node.right);
        int m=Math.max(node.data,Math.max(lm,rm));
        return m;
    }

    public static int heigth(Node node)
    {
        if(node==null)
            return 0;
        int lh=heigth(node.left);
        int rh=heigth(node.right);
        int h=Math.max(lh,rh)+1;
        return h;
    }

    public static boolean find(int data,Node node)
    {
        if(node==null)
            return false;

        if(node.data==data)
        {
            return true;
        }

        boolean fl=find(data,node.left);
        if(fl)
        {
            return true;
        }

        boolean fr=find(data,node.right);
        if(fr)
        {
            return true;
        }

        return false;
    }

    public static ArrayList rootToPath(int data,Node node)
    {
        if(node==null)
            return new ArrayList<>();

        if(node.data==data)
        {
            ArrayList<Integer> list=new ArrayList<>();
            list.add(data);
            return list;
        }

        ArrayList<Integer> rtpfl=rootToPath(data,node.left);
        if(rtpfl.size()>0)
        {
            rtpfl.add(node.data);
            return rtpfl;
        }

        ArrayList<Integer> rtpfr=rootToPath(data,node.right);
        if(rtpfr.size()>0)
        {
            rtpfr.add(node.data);
            return rtpfr;
        }

        return new ArrayList<>();
    }

    public static void removeleaves(Node node)
    {
        if(node.left.left==null && node.left.right==null)
            node.left=null;
        else
            removeleaves(node.left);

        if(node.right.left==null && node.right.right==null)
            node.right=null;
        else 
            removeleaves(node.right);
    }


    public static Node removeleaves2(Node node)
    {
        if(node==null){
            return null;
        }
        else if(node.left==null && node.right==null){
            return null;
        }
        else{
            node.left=removeleaves2(node.left);
            node.right=removeleaves2(node.right);
            return node;
        }
    }

    // static void printSingleChild(Node node)

    static void pir(Node node,int lo,int hi,int ssf,String psf)
    {
        if(node==null)
        {
            return;
        }

        if(node.left==null && node.right==null)
        {
            ssf+=node.data;
            psf+=node.data;
            if(ssf>=lo && ssf<=hi)
            {
                System.out.println(psf);
            }
        }

        pir(node.left,lo,hi,ssf+node.data,psf+node.data+" ");
        pir(node.right,lo,hi,ssf+node.data,psf+node.data+" ");
    }

    static Node transformLD(Node node)
    {
        if(node==null)
            return null;

        node.left=transformLD(node.left);
        node.right=transformLD(node.right);

        node.left=new Node(node.data,node.left,null);

        return node;
    }

    static Node transformFromLD(Node node)
    {
        if(node==null)
        {
            return null;
        }

        node.left=transformFromLD(node.left.left);
        node.right=transformFromLD(node.right);
        return node;
    }

    static Node construct2(int[] pre,int psi,int pei,int[] in,int isi,int iei)
    {
        if(pei<psi || iei<isi)
        {
            return null;
        }

        Node node=new Node();
        node.data=pre[psi];

        int x=0;
        for(int i=isi;i<=iei;i++)
        {
            if(in[i]==pre[psi]){
                x=i;
                break;
            }
        }

        int lhs=x-isi;
        node.left=construct2(pre,psi+1,psi+lhs,in,isi,x-1);
        node.right=construct2(pre,psi+lhs+1,pei,in,x+1,iei);

        return node;
    }

    static Node construct3(int[] post,int psi,int pei,int[] in,int isi,int iei)
    {
        if(pei<psi || iei<isi)
        {
            return null;
        }

        Node node=new Node();
        node.data=post[pei];

        int x=0;
        for(int i=isi;i<=iei;i++)
        {
            if(in[i]==post[pei]){
                x=i;
                break;
            }
        }

        int lhs=x-isi;
        node.left=construct3(post,psi,psi+lhs-1,in,isi,x-1);
        node.right=construct3(post,psi+lhs,pei-1,in,x+1,iei);

        return node;
    }

    
    // static Node construct4(int[] post2,int posi,int poei,int[] pre2,int prsi,int prei)
    // {
    //     if(?)
    //     {
    //         return null;
    //     }

    //     Node node=new Node();
    //     node.data=pre[prsi];

    //     int x=0;
    //     for(int i=prsi+1;i<=prei;i++)
    //     {
    //         if(in[i]==pre[prsi+1]){
    //             x=i;
    //             break;
    //         }
    //     }

    //     int lhs=x-isi;
    //     node.left=construct4(post2,posi,psi+lhs,pre2,isi,x-1);
    //     node.right=construct4(post2,psi+lhs,pei-1,pre2,x+1,iei);

    //     return node;
    // }

    static class Pair{
        Node node;
        int state=0;
        Pair(){

        }
        Pair(Node node,int state)
        {
            this.node=node;
            this.state=state;
        }
    }
    static void iterativeDFTraversals(Node root)
    {
        ArrayList<Integer> pre=new ArrayList<>();
        ArrayList<Integer> in=new ArrayList<>();
        ArrayList<Integer> post=new ArrayList<>();

        Stack<Pair> st=new Stack<>();
        st.push(new Pair(root,0));
        while(st.size()>0)
        {
            Pair top=new Pair();
            top=st.peek();
            if(top.state==0)
            {
                pre.add(top.node.data);
                top.state++;
                if(top.node.left != null)
                    st.push(new Pair(top.node.left,0));
            }
            else if(top.state==1)
            {
                in.add(top.node.data);
                top.state++;
                if(top.node.right != null)
                    st.push(new Pair(top.node.right,0));
            }
            else if (top.state==2)
            {
                post.add(top.node.data);
                st.pop();
            }
        } 

        System.out.println("Pre -> "+pre);
        System.out.println("In -> "+in);
        System.out.println("Post -> "+post);
    }

    static int diameter(Node node)
    {
        if(node==null)
        {
            return 0;
        }
        
        //one of the farthest nodes lives in either side of st
        int lh=heigth(node.left);
        int rh=heigth(node.right);
        int factor=lh+rh+1;//for edges lh+rh+2

        //if both the farthest nodes lives in left st
        int ld=diameter(node.left);//maximum distace between any two nodes in either side of a root
        //if both the farthest nodes lives in left st
        int rd=diameter(node.right);

        return Math.max(factor,Math.max(ld,rd));
    }

    static class BalPair{
        boolean isBal;
        int ht;
    }

    static BalPair IsBalanced(Node node){
        if(node==null)
        {
            BalPair bp=new BalPair();
            bp.ht=0;
            bp.isBal=true;
            return bp;
        }

        BalPair lt=IsBalanced(node.left);
        BalPair rt=IsBalanced(node.right);
        BalPair mp=new BalPair();
        mp.ht=Math.max(lt.ht,rt.ht)+1;
        mp.isBal=lt.isBal && rt.isBal && Math.abs(lt.ht-rt.ht)<=1;

        return mp;
    }

    static boolean isBal=true;
    static int heigthofIsBal(Node node)
    {
        if(node==null)
            return 0;

        int lh=heigthofIsBal(node.left);
        int rh=heigthofIsBal(node.right);

        if(Math.abs(lh-rh)>1)
            isBal=false;

        return Math.max(lh,rh)+1;
    }


    static class BSTPair{
        int min;
        int max;
        boolean isBST;
        int lBSTSize;
        Node lBSTroot;
    }

    static BSTPair isBST(Node node)
    {
        if(node==null)
        {
            BSTPair bp = new BSTPair();
            bp.min=Integer.MAX_VALUE;
            bp.max=Integer.MIN_VALUE;
            bp.isBST=true;
            return bp;
        }

        BSTPair lp=isBST(node.left);
        BSTPair rp=isBST(node.right);
        BSTPair mp=new BSTPair();

        mp.max=Math.max(node.data,Math.max(lp.max,rp.max));
        mp.min=Math.min(node.data,Math.min(lp.min,rp.min));
        mp.isBST=lp.isBST && rp.isBST && node.data>lp.max && node.data<rp.min;

        return mp;
    }

    //BST adv**=====================================================================
     static BSTPair isBST2(Node node)
    {
        if(node==null)
        {
            BSTPair bp = new BSTPair();
            bp.min=Integer.MAX_VALUE;
            bp.max=Integer.MIN_VALUE;
            bp.isBST=true;
            bp.lBSTSize = 0;
            bp.lBSTroot = null;
            return bp;
        }

        BSTPair lp=isBST2(node.left);
        BSTPair rp=isBST2(node.right);
        BSTPair mp=new BSTPair();

        mp.max=Math.max(node.data,Math.max(lp.max,rp.max));
        mp.min=Math.min(node.data,Math.min(lp.min,rp.min));
        mp.isBST=lp.isBST && rp.isBST && node.data>lp.max && node.data<rp.min;

        if(mp.isBST){
            mp.lBSTroot=node;
            mp.lBSTSize=lp.lBSTSize+rp.lBSTSize+1;
        }else{
            if(lp.lBSTSize>=rp.lBSTSize)
            {
                mp.lBSTroot=lp.lBSTroot;
                mp.lBSTSize=lp.lBSTSize;
            }else{
                mp.lBSTroot=rp.lBSTroot;
                mp.lBSTSize=rp.lBSTSize;
            }
        }

        return mp;
    }
    // K far**===================================================
    
    public static ArrayList<Node> rootToPath2(int data,Node node)
    {
        if(node==null)
            return new ArrayList<>();

        if(node.data==data)
        {
            ArrayList<Node> list=new ArrayList<>();
            list.add(node);
            return list;
        }

        ArrayList<Node> rtpfl=rootToPath2(data,node.left);
        if(rtpfl.size()>0)
        {
            rtpfl.add(node);
            return rtpfl;
        }

        ArrayList<Node> rtpfr=rootToPath2(data,node.right);
        if(rtpfr.size()>0)
        {
            rtpfr.add(node);
            return rtpfr;
        }

        return new ArrayList<>();
    }

    static void printkfar(Node node,int data,int k){
        ArrayList<Node> path=rootToPath2(data,node);
        printkdown(path.get(0),null,k);
        for(int i=1;i<path.size();i++)
        {
            printkdown(path.get(i),path.get(i-1),k-1);
        }
    }

    static void printkdown(Node node,Node Blocker, int k){
        if(node==null || node==Blocker || k<0)
        {
            return;
        }
     
        if(k==0)
        {
            System.out.println(node.data);
        }

        printkdown(node.left,Blocker,k-1);
        printkdown(node.right,Blocker,k-1);

        return;
    }

    static int maximumSumfromanyleafToanylaef

    public static void main (String[] args)
    {
         int arr[]={ 50,25,12,-1,37,30,-1,40,-1,-1,-1,75,62,60,-1,70,-1,-1,87,-1,-1,-1};
        // int pre[]={50,25,12,37,30,75,62,70,87};
        // int post[]={12,30,37,25,70,62,87,75,50};
        // int in[]={12,25,30,37,50,62,70,75,87};
        // Node root=construct2(pre,0,pre.length-1,in,0,in.length-1);
        // Node root=construct3(post,0,post.length-1,in,0,in.length-1);
        // display(root);
        Node root=construct(arr);
        // iterativeDFTraversals(root);
        // System.out.println(diameter(root));
        // display(root);
        // System.out.println(size(root));
        // System.out.println(heigth(root));
        // System.out.println(find(37,root));
        // // System.out.println(rootToPath(37,root));
        // removeleaves(root);
        // display(root);
        // root=removeleaves2(root);
        // display(root);
        // System.out.println(max_(root));
        // pir(root,150,250,0,"");
        // transformLD(root);
        // display(root);
        // transformFromLD(root);
        // display(root);
        // BalPair m=IsBalanced(root);
        // if(!m.isBal)
        // {
        //     System.out.println("not balanced");
        // }
        // else{
        //     System.out.println("balanced");
        // }
        // display(root);
        // System.out.println("~~~~~~~~~~~~~~~~~");
        // // int m=heigthofIsBal(root);
        // if(isBal)
        // {
        //     System.out.println("balanced");
        // }
        // else{
        //     System.out.println("not balanced");
        // // }
        // BSTPair m=isBST2(root);
        // System.out.println(m.lBSTSize);
        // System.out.println(m.lBSTroot.data);
        // display(m.lBSTroot);
        printkfar(root,25,2);
    }
}