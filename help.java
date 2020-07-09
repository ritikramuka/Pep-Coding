import java.util.Scanner;
import java.util.ArrayList;

public class help {

    public static Scanner scn = new Scanner(System.in);

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

    public static Node constructBST(int[] arr, int si, int ei) {
        if (si > ei)
            return null;

        int mid = (si + ei) >> 1;

        Node node = new Node(arr[mid]);

        node.left = constructBST(arr, si, mid - 1);
        node.right = constructBST(arr, mid + 1, ei);

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

    public static int height(Node root) {
        if (root == null)
            return -1;

        int lh = 0;
        int rh = 0;
        lh = height(root.left);
        rh = height(root.right);

        return Math.max(lh, rh) + 1;

    }

    public static int size(Node root) {
        if (root == null)
            return 0;
        int count = 0;
        count += size(root.left);
        count += size(root.right);

        return count + 1;

    }

    public static boolean find(Node root, int data) {
        Node curr = root;

        while (curr != null) {
            if (curr.data == data)
                return true;

            else if (curr.data < data) {
                curr = curr.right;
            } else {
                curr = curr.left;
            }
        }
        return false;
    }

    public static Node lowestCommonAncestor(Node root, int p, int q) {

        Node curr = root;

        while (curr != null) {
            if (p > curr.data && q > curr.data)
                curr = curr.right;

            else if (p < curr.data && q < curr.data)
                curr = curr.left;
            else
                return curr;
        }
        return null;
    }

    static Node prevNode;

    public static boolean isBST(Node root) {
        if (root == null)
            return true;

        if (!isBST(root.left))
            return false;

        if (prevNode != null && prevNode.data > root.data)
            return false;
        prevNode = root;

        if (!isBST(root.right))
            return false;

        return true;

    }

    static Node a = null;
    static Node b = null;
    static Node prev1 = null;

    public static boolean recoverTree_(Node root) {
        if (root == null)
            return false;

        if (recoverTree_(root.left))
            return true;

        if (prev1 != null && prev1.data > root.data) {
            b = root;

            if (a == null) {
                a = prev1;
            } else
                return true;

        }
        prev1 = root;

        if (recoverTree_(root.right))
            return true;

        return false;

    }

    public static void recoverTree(Node root) {
        recoverTree_(root);

        if (a != null) {
            Node temp = a;
            a.data = b.data;
            b.data = temp.data;
        }
    }

    public static class pair{
        Node pred=null;
        Node succ=null;
        pair(){}
    }

    public static void allSol(Node root, int data, Node prev, pair p) {
        if (root == null)
            return;

        if (root.data == data && p.pred == null) {
            p.pred = prev;
            // System.out.println(prev.data);
        }
        if ((prev != null) && (prev.data == data) && (p.succ == null)) {
            p.succ = root;
            // System.out.println(succ.data);
        }
        prev = root;

        allSol(root.left, data, prev, p);
        allSol(root.right, data, prev, p);
    }

    public static void solve() {
        int[] arr = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130 };
        Node root = constructBST(arr, 0, arr.length - 1);
        display(root);
        // System.out.println(height(root));
        // System.out.println(size(root));
        // System.out.println(find(root, 130));
        pair p=new pair();
        allSol(root, 50, null,p);
        System.out.println(p.pred.data+" "+p.succ.data);

        // Node ans=lowestCommonAncestor(root, 30, 50);
        // System.out.println(ans.data);
    }

    public static void main(String[] args) {
        solve();
    }
}