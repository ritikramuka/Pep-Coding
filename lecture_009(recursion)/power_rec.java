public class power_rec{
    public static void main(String[] args){
        System.out.println(power_V1(2,10));
        System.out.println(steps);
        System.out.println(power_V2(2,10));
        System.out.println(steps2);
    }
    static int steps=0;
    public static int power_V1(int a,int b){
        if(b==0)
        return 1;
        steps++;
        int ans=a*power_V1(a,b-1);
        return ans;
    }static int steps2=0;
    public static int power_V2(int a,int b){
        if(b==0)
        return 1;
        steps2++;
        int ans2=power_V2(a,b/2);
        ans2*=ans2;
        if(b%2!=0)
        ans2*=a;
        return ans2;
    }
}