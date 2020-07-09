import java.util.ArrayList;
import java.util.LinkedList;

public class  genericTree{
    public static void main(String[] args) {
        solve();
    }
    public static void solve()
    {
       int arr[] = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100 ,-1,-1,-1};
            Node ans= constructor( arr); // constructor ne return kara and humne usse ans mei daal diya
        //display(ans);
        //int height= height(ans);
        //System.out.println(height);
        //find(100, ans);
        //levelorder3(ans);
        //levelorder2(ans);
        //levelorder1(ans);
        zigzag(ans);

    }
    public static class Node{
        int data =0 ;
          ArrayList<Node> children =new ArrayList<>(); // arraylist of node isliye banayi kyuki usme aur node ho sakte hai
           Node(int data)
           {
               this.data = data;
           }
    }
    public static Node constructor(int[] arr){    // constructor mei data daalna hoga hum array pass karenge and iterative karenge
        LinkedList<Node> st =new LinkedList<>();  // humne stack banaya 
        Node root =null;  // node banayi khali hai 
        // root new = Node(arr[0]);
        for(int i=0 ; i<arr.length; i++)
        {
            if(arr[i]==-1){   // agar uss parent ka koi child ni hai to usse remove kar do
                st.removeFirst();
            }
            else
            {
                Node node = new Node(arr[i]); //node type kas isliye banay kyuki root apna node type ka hai
                if(st.size()==0)   // ye if bas ek baar chalega kyuki stack ka size zero hoga starting mei and starting waala jo hoga element wo root mei daal denge           
                 {
                     root = node;  // pehle waale ko root assign kar diya 
                 }
                 else
                 {
                     st.getFirst().children.add(node);  // stack ke first pe jaake children ko add kar re hai Arraylist mei
                                                        // is waale ne getFirst waale element ke array List waale mei karega stack mei ni
                 }
                 st.addFirst(node); // ye jaake Stack pe add karega  
                }
            }
            return root;
            
        }
 public static void display(Node ans)
  {
      System.out.println(ans.data); // is waale ne root ko print kar diya 
                                           // ans ka data print ho gya ab Array List bacha hai jisme uske saare children pade hai
      for(Node e : ans.children)  //ab ye line uske arrayList ko access karene ke liye banaya 
      {
          display(e);  // ye arrayLIst ke elements ko access karega 
      }// for is ki jagah for(int i=0; i<ans.child.size();i++)
  }
 public static boolean find(int data ,Node ans)  // ntf =number to find 
   {  if(ans.data==data)  //base case ki zarurat ni hai coz for loop use kar re hai
        return true;   // agar node/root hi answer hai to aage check karne ki zarurat hi ni 
       
        for(Node child :ans.children)  // ab agar root answer ni hai to uske children ko check karega
      {  boolean res=find(data, child);  
        if(res) 
        return true;
      }
      return false;
   }
   public static int minelement(Node ans){
    int minoverall=ans.data;   // root ko humne max ele maan liya
    for(Node child:ans.children){  
        int recmin=minelement(child);        // ab root ko compare karenge children se 
        minoverall=Math.min(recmin,minoverall);
    }
    return minoverall;
}
    
   public static int height(Node ans)
   { int height = -1;  // -1 isliye liya kyuki height 0 se start karenge 
    for(Node child : ans.children)
    {
        int recAns=height(child);
        height=Math.max(height,recAns);

    }
   
    return height+1;

   }
    
   public static int size(Node ans)
   {
       int count = 0;  
       for(Node child : ans.children)
       {
           count+=size(child);  // kitne children hai unko add kar diya

       }

       return count+1;  // count hume saare children dega +1 se hume parent de dega i.e, root add karke
      
     } 
     public static int size2(Node ans){
        int count=1;
   
        for(Node child:ans.children){
            count+=size(child);
        }
        return count;


   }
    //lowest common ancestor
    public static ArrayList<Node> path(Node root,int data){
        if(root.data==data){
            ArrayList<Node>base=new ArrayList<>();
            base.add(root);
            return base;
        }
        
        for(Node child:root.children){
        ArrayList<Node> myans=path(child,data);
        if(myans.size()>0){   
            myans.add(root);
            return myans;
           }
        }
        return new ArrayList<>();

    }
public static int ancestor(Node root,int a,int b){
         if( find(a,root) && find(b,root)){  // idhar hum ye check kar re hai ki element present hai ya ni
            ArrayList<Node>path1=path(root,a);
            ArrayList<Node>path2=path(root,b);
            for(int i=path1.size()-1,j=path2.size()-1;i>=0&& j>=0;i--,j--){
                if(path1.get(i).data!=path2.get(j).data){
                    return path1.get(i+1).data;
                }
                if(i==0)//these checks are for such cases path1=10(0)   path2=10(0),30(1)   so i==0,j==1 these are not equal if we decrease i and j then i==-1 (not possible)
                return path1.get(i).data;//and it will give error similarly for j so if in both of i and j (if data exist in arraylist)one bcm at zeroth index then that indx data was the answer 
                if(j==0)
                return path2.get(j).data;
            }


        }
       // else
        return -1;
    }
        //level order
    
        public static void levelorder1(Node a){
            LinkedList<Node>que=new LinkedList<>();
            que.addLast(a);
            while(!que.isEmpty()){
                Node rnode=que.removeFirst();
                System.out.print(rnode.data+" ");
                for(Node child:rnode.children){
                    que.addLast(child);
                }
            }
        }  
        public static void levelorder2(Node a){
            LinkedList<Node>que1=new LinkedList<>();
            LinkedList<Node>que2=new LinkedList<>();
            que1.addLast(a);
            while(!que1.isEmpty()){
                Node rnode=que1.removeFirst();
                System.out.print(rnode.data+" ");
                for(Node child:rnode.children){
                    que2.addLast(child);
                }
                if(que1.size()==0){
                    System.out.println();
                    LinkedList<Node>temp=new LinkedList<>();
                    temp=que1;
                    que1=que2;
                    que2=temp;
                }
            }
        }  
    
    public static void levelorder3(Node a)
    {
        LinkedList<Node> que=new LinkedList<>();
        que.addLast(a);
        while(que.size()>0)
        {
            int size=que.size();

            while(size-->0)
            {
                Node rnode=que.removeFirst();
                System.out.print(rnode.data+" ");

                for(Node child : rnode.children)
                {
                    que.addLast(child);
                }
            }
            System.out.println();
        }
    }

    public static void zigzag(Node a)
    {
        LinkedList<Node> st1=new LinkedList<>();
        LinkedList<Node> st2=new LinkedList<>();
        boolean flag=false;

        st1.addFirst(a);

        while(!st1.isEmpty()){
            Node rnode=st1.removeFirst();
            System.out.print(rnode.data+" ");

            if(flag)
            {
                for(Node ans : rnode.children)
                {
                    st2.addFirst(ans);
                }
            }else
            {
                for(int i=rnode.children.size()-1;i>=0;i--)
                {
                    st2.addFirst(rnode.children.get(i));
                }
               
            }
             if(st1.size()==0)
                {
                    flag=flag?false:true;
                    System.out.println();
                    LinkedList<Node>temp=new LinkedList<>();
                    temp=st1;
                    st1=st2;
                    st2=temp;
                }
        }
    }

    public static class HMpair{
        int max=Integer.MIN_VALUE;
        int min=Integer.MAX_VALUE;
        boolean find=false;

    }

    public static void multisolver(Node root,int data,HMpair pair)
    {
        if(pair.find==false && root.data=data)
        pair.find=true;

        pair.max=Math.max(pair.max,root.data);
        pair.min=Math.min(pair.min,root.data);

        for(Node child : root.children){
            multisolver(child,data,HMpair);
        }
    }

    
}