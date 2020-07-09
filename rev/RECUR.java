import java.util.ArrayList;
import java.util.HashSet;

public class RECUR {
    public static void main(String[] args) {
        solve();
    }

    public static void solve() {

        // floodFillCate();
        // coinChange();
        // sudoku();
        // WordBreak();
    }

    // =================================================================

    public static void floodFillCate() {
        int[][] board = new int[4][4];
        int ans = floodfill_Height(0, 0, 3, 3, board);
        // pair ansP=floodfill_LongestPath(0,0,3,3,board);
        pair ansP = floodfill_ShortestPath(0, 0, 3, 3, board);

        System.out.println(ansP.str + " -> " + ansP.len);

    }

    static int[][] dir = { { 0, 1 }, { -1, 1 }, { -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
    static String[] dirN = { "R", "E", "U", "N", "L", "W", "D", "S" };

    public static int floodfill_Height(int sr, int sc, int er, int ec, int[][] board) {
        if (sr == er && sc == ec) {
            return 0;
        }

        board[sr][sc] = 2;
        int maxH = 0;
        for (int d = 0; d < dir.length; d++) {
            int r = sr + dir[d][0];
            int c = sc + dir[d][1];
            if (r >= 0 && c >= 0 && r < board.length && c < board[0].length && board[r][c] == 0) {
                int recH = floodfill_Height(r, c, er, ec, board);
                maxH = Math.max(recH, maxH);
            }
        }

        board[sr][sc] = 0;
        return maxH + 1;
    }

    static class pair {
        int len = 0;
        String str = "";

        pair(int len, String str) {
            this.len = len;
            this.str = str;
        }
    }

    public static pair floodfill_LongestPath(int sr, int sc, int er, int ec, int[][] board) {
        if (sr == er && sc == ec) {
            return new pair(0, "");
        }

        board[sr][sc] = 2;

        pair mypair = new pair(0, "");

        for (int d = 0; d < dir.length; d++) {
            int r = sr + dir[d][0];
            int c = sc + dir[d][1];
            if (r >= 0 && c >= 0 && r < board.length && c < board[0].length && board[r][c] == 0) {
                pair recP = floodfill_LongestPath(r, c, er, ec, board);

                if (recP.len + 1 > mypair.len) {
                    mypair.len = recP.len + 1;
                    mypair.str = recP.str + dirN[d];
                }
            }
        }

        board[sr][sc] = 0;
        return mypair;
    }

    public static pair floodfill_ShortestPath(int sr, int sc, int er, int ec, int[][] board) {
        if (sr == er && sc == ec) {
            return new pair(0, ""); // c++ -> INT_MAX;
        }

        board[sr][sc] = 2;

        pair mypair = new pair((int) 1e7, "");

        for (int d = 0; d < dir.length; d++) {
            int r = sr + dir[d][0];
            int c = sc + dir[d][1];
            if (r >= 0 && c >= 0 && r < board.length && c < board[0].length && board[r][c] == 0) {
                pair recP = floodfill_ShortestPath(r, c, er, ec, board);

                if (recP.len + 1 < mypair.len) {
                    mypair.len = recP.len + 1;
                    mypair.str = dirN[d] + recP.str;
                }
            }
        }

        board[sr][sc] = 0;
        return mypair;
    }

    // CoinTrees.====================================================

    public static int coinChangePermuINFI_01(int[] arr, int tar, String ans) {
        if (tar == 0) {
            System.out.println(ans);
            return 1;
        }

        int count = 0;
        for (int i = 0; i < arr.length; i++) {
            if (tar - arr[i] >= 0)
                count += coinChangePermuINFI_01(arr, tar - arr[i], ans + arr[i] + " ");
        }

        return count;
    }

    public static int coinChangePermu_01(int[] arr, int tar, boolean[] vis, String ans) {
        if (tar == 0) {
            System.out.println(ans);
            return 1;
        }

        int count = 0;
        for (int i = 0; i < arr.length; i++) {
            if (!vis[i] && tar - arr[i] >= 0) {
                vis[i] = true;
                count += coinChangePermu_01(arr, tar - arr[i], vis, ans + arr[i] + " ");
                vis[i] = false;
            }
        }
        return count;
    }

    public static int coinChangeCombinationINFI_01(int[] arr, int idx, int tar, String ans) {
        if (tar == 0) {
            System.out.println(ans);
            return 1;
        }

        int count = 0;
        for (int i = idx; i < arr.length; i++) {
            if (tar - arr[i] >= 0)
                count += coinChangeCombinationINFI_01(arr, i, tar - arr[i], ans + arr[i] + " ");
        }

        return count;
    }

    // public static int coinChangeCombination_01(int[] arr,int idx,int tar,String
    // ans){
    // if(tar==0){
    // System.out.println(ans);
    // return 1;
    // }

    // int count=0;
    // for(int i=idx;i<arr.length;i++){
    // if(tar-arr[i]>=0)
    // count+=coinChangeCombination_01(arr,i+1,tar-arr[i],ans + arr[i]+ " ");
    // }

    // return count;
    // }

    // public static int coinChangeCombination_01(int[] arr,int idx,int tar,String
    // ans)
    // {
    // if(tar==0 || idx>=arr.length)
    // {
    // if(tar==0)
    // {
    // System.out.println(ans);
    // return 1;
    // }
    // return 0;
    // }

    // int count=0;
    // if(tar-arr[idx]>=0)
    // count+=coinChangeCombination_01(arr,idx+1,tar-arr[idx],ans+arr[idx]+" ");
    // count+=coinChangeCombination_01(arr,idx+1,tar,ans);

    // return count;
    // }

    public static int coinChangeCombination_02(int[] arr, int idx, int tar, String ans) {
        if (tar == 0 || idx >= arr.length) {
            if (tar == 0) {
                System.out.println(ans);
                return 1;
            }
            return 0;
        }

        int count = 0;
        if (tar - arr[idx] >= 0)
            count += coinChangeCombination_02(arr, idx, tar - arr[idx], ans + arr[idx] + " ");
        count += coinChangeCombination_02(arr, idx + 1, tar, ans);

        return count;
    }

    // n-queens********************************************************

    public static int queenscomb(int[] arr, int idx, int n, String ans) {
        if (n == 0 || idx > arr.length - n) {
            if (n == 0) {
                System.out.println(ans);
                return 1;
            }
            return 0;
        }

        int count = 0;
        if (arr.length - idx >= 0)
            count += queenscomb(arr, idx + 1, n - 1, ans + arr[idx] + (3 - n + 1) + " ");
        count += queenscomb(arr, idx + 1, n, ans);

        return count;
    }

    public static int queensper(int[] arr, int idx, int n, boolean[] vis, String ans) {
        if (n == 0 || idx > arr.length - 1) {
            if (n == 0) {
                System.out.println(ans);
                return 1;
            }
            return 0;
        }

        int count = 0;
        if (arr.length - idx >= 0 && vis[idx] == false) {
            vis[idx] = true;
            count += queensper(arr, 0, n - 1, vis, ans + arr[idx] + (4 - n) + " ");
            vis[idx] = false;
        }
        count += queensper(arr, idx + 1, n, vis, ans);

        return count;
    }

    public static int nqueens2D(boolean[][] boxes, int qpsf, int idx, int tnq, String ans) {
        if (qpsf == tnq) {
            System.out.println(ans);
            return 1;
        }

        int count = 0;
        for (int i = idx; i < boxes.length * boxes[0].length; i++) {
            int x = i / boxes[0].length;
            int y = i % boxes[0].length;
            count += nqueens2D(boxes, qpsf + 1, i + 1, tnq, ans + "(" + x + ", " + y + ") ");
        }
        return count;
    }

    public static int nqueensPer2D(boolean[][] boxes, int qpsf, int tnq, String ans) {
        if (qpsf == tnq) {
            System.out.println(ans);
            return 1;
        }

        int count = 0;
        for (int i = 0; i < boxes.length * boxes[0].length; i++) {
            int x = i / boxes[0].length;
            int y = i % boxes[0].length;
            if (boxes[x][y] == false) {
                boxes[x][y] = true;
                count += nqueensPer2D(boxes, qpsf + 1, tnq, ans + "(" + x + ", " + y + ") ");
                boxes[x][y] = false;
            }
        }
        return count;
    }

    // nqueens====================================================================

    public static boolean isSafeToPlaceQueen(boolean[][] boxes, int row, int col) {
        int[][] Qdir = { { 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 } };

        for (int d = 0; d < Qdir.length; d++) {
            for (int rad = 1; rad <= boxes.length; rad++) {
                int r = row + rad * Qdir[d][0];
                int c = col + rad * Qdir[d][1];

                if (r >= 0 && c >= 0 && r < boxes.length && c < boxes[0].length) {
                    if (boxes[r][c])
                        return false;
                } else
                    break;
            }
        }
        return true;
    }

    public static int nqueens(boolean[][] boxes, int qpsf, int tnq, int idx, String ans) {
        if (qpsf == tnq) {
            System.out.println(ans);
            return 1;
        }

        int count = 0;
        for (int i = idx; i < boxes.length * boxes[0].length; i++) {
            int x = i / boxes[0].length;
            int y = i % boxes[0].length;
            if (isSafeToPlaceQueen(boxes, x, y)) {
                boxes[x][y] = true;
                count += nqueens(boxes, qpsf + 1, tnq, i + 1, ans + "(" + x + ", " + y + ") ");
                boxes[x][y] = false;
            }
        }
        return count;
    }

    // static boolean[] row;
    // static boolean[] col;
    // static boolean[] diag;
    // static boolean[] adiag;

    // public static int nqueens02(int n, int m, int qpsf, int tnq, int idx, String
    // ans) {
    // if (qpsf == tnq) {
    // System.out.println(ans);
    // return 1;
    // }

    // int count = 0;
    // for (int i = idx; i < m * n; i++) {
    // int x = i / m;
    // int y = i % n;
    // if (!row[m] && !col[n] && diag[x - y + m - 1] && adiag[x + y]) {

    // row[x]=true;
    // col[y]=true;
    // diag[x - y + m - 1]=true;
    // adiag[x + y]=true;

    // count += nqueens02(n, m, qpsf + 1, tnq, i + 1, ans + "(" + x + ", " + y + ")
    // ");

    // row[x]=false;
    // col[y]=false;
    // diag[x - y + m - 1]=false;
    // adiag[x + y]=false; }
    // }
    // return count;
    // }

    static int row_ = 0;
    static int col_ = 0;
    static int diag_ = 0;
    static int adiag_ = 0;

    public static int nqueens03(int n, int m, int qpsf, int tnq, int idx, String ans) {
        if (qpsf == tnq) {
            System.out.println(ans);
            return 1;
        }

        int count = 0;
        for (int i = idx; i < m * n; i++) {
            int x = i / m;
            int y = i % n;
            if ((row_ & (1 << x)) == 0 && (col_ & (1 << y)) == 0 && (diag_ & (1 << (x - y + m - 1))) == 0
                    && (adiag_ & (1 << (x + y))) == 0) {

                row_ ^= (1 << x);
                col_ ^= (1 << y);
                diag_ ^= (1 << (x - y + m - 1));
                adiag_ ^= (1 << (x + y));

                count += nqueens03(n, m, qpsf + 1, tnq, i + 1, ans + "(" + x + ", " + y + ") ");

                row_ ^= (1 << x);
                col_ ^= (1 << y);
                diag_ ^= (1 << (x - y + m - 1));
                adiag_ ^= (1 << (x + y));
            }
        }
        return count;
    }

    public static void coinChange() {
        int[] arr = { 0, 1, 2, 3, 4 };
        int tar = 10;
        int ans = 0;
        boolean[][] boxes = new boolean[4][4];

        // boolean[] vis = new boolean[arr.length];
        // ans=coinChangePermuINFI_01(arr,tar,"");
        // ans=coinChangePermu_01(arr,tar,vis,"");

        // ans=coinChangeCombinationINFI_01(arr,0,tar,"");
        ans=coinChangeCombination_02(arr,0,tar,"");

        // ans=queenscomb(arr,0,3,"");
        // ans = queensper(arr, 0, 3, vis, "");
        // ans = nqueens2D(boxes, 0, 0, 3, "");
        // ans = nqueensPer2D(boxes, 0, 3, "");
        // ans = nqueens(boxes, 0, 4, 0, "");
        // ans=nqueens03(4, 4, 0, 4, 0, "");

        // row=new boolean[n]

        // ans = nqueens03(4, 4, 0, 4, 0, "");

        System.out.println(ans);

    }
    // sudoku================================================================

    public static void sudoku() {
        int[][] board = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, { 5, 2, 0, 0, 0, 0, 0, 0, 0 }, { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                { 0, 0, 3, 0, 1, 0, 0, 8, 0 }, { 9, 0, 0, 8, 6, 3, 0, 0, 5 }, { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                { 1, 3, 0, 0, 0, 0, 2, 5, 0 }, { 0, 0, 0, 0, 0, 0, 0, 7, 4 }, { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

        ArrayList<Integer> calls=new ArrayList<>();

        row=new int[9];
        col=new int[9];
        mat=new int[3][3];

        for(int i=0;i<board.length;i++)
        {
            for(int j=0;j<board.length;j++)
            {
                if(board[i][j]==0)
                {
                    calls.add((i*9)+j);
                }
                else
                {
                    row[i]^=1;
                    col[j]^=1;
                    mat[i/3][j/3]^=1;
                }
            }
        }
        // System.out.println(sudoku_01(board,0));
        // System.out.println(sudoku_02(board,0,calls));
        System.out.println(sudoku_03(board, 0, calls));
    }

    public static boolean isSafeToPlaceNumber(int[][] board, int r, int c, int num) {
        for (int i = 0; i < board.length; i++) {
            if (board[r][i] == num)
                return false;
        }

        for (int j = 0; j < board[0].length; j++) {
            if (board[j][c] == num)
                return false;
        }

        int x = (r / 3) * 3;
        int y = (c / 3) * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[x + i][y + j] == num)
                    return false;
            }
        }

        return true;
    }

    public static boolean sudoku_01(int[][] board, int idx) {
        if (idx == 81) {
            display(board);
            return true;
        }

        boolean res = false;

        int r = idx / 9;
        int c = idx % 9;

        if (board[r][c] == 0) {
            for (int num = 1; num <= 9; num++) {
                if (isSafeToPlaceNumber(board, r, c, num)) {
                    board[r][c] = num;
                    res = res || sudoku_01(board, idx + 1);
                    board[r][c] = 0;
                }
            }
        } else
            res=res||sudoku_01(board, idx + 1);

        return res;
    }

    public static boolean sudoku_03(int[][] board, int idx, ArrayList<Integer> calls) {
        if (idx == calls.size()) {
            display(board);
            return true;
        }

        boolean res = false;

        int r = calls.get(idx) / 9;
        int c = calls.get(idx) % 9;

        if (board[r][c] == 0) {
            for (int num = 1; num <= 9; num++) {

                int mask=(1<<num);

                if ((row[r] & mask)==0 && (col[c] & mask)==0 && (mat[r/3][c/3] & mask)==0) {
                    board[r][c] = num;
                    row[r]^=mask;
                    col[c]^=mask;
                    mat[r/3][c/3]^=mask;

                    res = res || sudoku_03(board, idx + 1,calls);

                    board[r][c] = 0;
                    row[r]^=mask;
                    col[c]^=mask;
                    mat[r/3][c/3]^=mask;
                }
            }
        } else
            res=res||sudoku_03(board, idx + 1,calls);

        return res;
    }

    static int[] row;
    static int[] col;
    static int[][] mat;

    public static boolean sudoku_02(int[][] board, int idx, ArrayList<Integer> calls) {
        if (idx == calls.size()) {
            display(board);
            return true;
        }

        boolean res = false;

        int r = calls.get(idx) / 9;
        int c = calls.get(idx) % 9;

        if (board[r][c] == 0) {
            for (int num = 1; num <= 9; num++) {
                if (isSafeToPlaceNumber(board, r, c, num)) {
                    board[r][c] = num;
                    res = res || sudoku_02(board, idx + 1,calls);
                    board[r][c] = 0;
                }
            }
        } else
            res=res||sudoku_02(board, idx + 1,calls);

        return res;
    }

    public static void display(int[][] arr) {
        for (int[] a : arr) {
            for (int ele : a)
            {    
                System.out.print(ele + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static HashSet<String> map=new HashSet<>();
    public static int WordBreak_(String str,String ans)
    {
        if(str.length()==0)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;
        for(int i=1;i<=str.length();i++)
        {
            String smallstr=str.substring(0,i);
            if(map.contains(smallstr))
            {
                count+=WordBreak_(str.substring(i), ans+smallstr+" ");
            }
        }
        return count;
    }
    public static void WordBreak()
    {
        String[] words={"i","like","ilike","sam","sung","samsung"};
        for(String word : words)
        {
            map.add(word);
        }
        String str="ilikesamsung";
        System.out.println(WordBreak_(str, "")); 
    }

}