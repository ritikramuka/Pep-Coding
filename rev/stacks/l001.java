public class l001 {
    public static class MyStack {
        private int N = 10000;
        private int[] arr;
        private int sz = 0;
        private int tos = -1;

        public MyStack() {
            this.arr = new int[this.N];
        }

        public MyStack(int size) {
            this.arr = new int[size];
            this.N = size;
        }

        public int size() {
            return this.sz;
        }

        public int top() {
            int rv = arr[tos];
            return rv;
        }

        public void pop() {
            if (this.tos == -1)
                return;
            arr[this.tos] = -1;
            this.sz--;
            this.tos--;
        }

        public void push(int val) {
            this.sz++;
            this.tos++;
            this.arr[this.tos] = val;
        }
    };

    public static void solve() {
        MyStack st = new MyStack();
        for (int i = 1; i <= 10; i++) {
            st.push(i + 10);
        }
        for (int i = 0; i < 10; i++) {
            System.out.println(st.top());
            st.pop();
        }
    }

    public static void main(String args[]) {
        solve();
        return;
    }
}