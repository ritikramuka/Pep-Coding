import java.util.*;
class time{

//Bit Masking.==============================================================================
    static void setABit(int x,int k)
    {
        System.out.println(x+"="+Integer.toBinaryString(x));
        int mask=1<<k;
        System.out.println(mask+"="+Integer.toBinaryString(mask));
        x=x|mask;
        System.out.println(x+"="+Integer.toBinaryString(x));
    }
    
    static void unsetABit(int x,int k)
    {
        System.out.println(x+"="+Integer.toBinaryString(x));
        int mask=~(1<<k);
        System.out.println(mask+"="+Integer.toBinaryString(mask));
        x=x&mask;
        System.out.println(x+"="+Integer.toBinaryString(x));
    }

    static void toggleABit(int x,int k)
    {
        System.out.println(x+"="+Integer.toBinaryString(x));
        int mask=1<<k;
        System.out.println(mask+"="+Integer.toBinaryString(mask));
        x=x^mask;
        System.out.println(x+"="+Integer.toBinaryString(x));
    }
//============================================================================================

    public static void main(String[] args)
    {
        // setABit(57,2);
        // System.out.println();
        // unsetABit(45,4);
        // System.out.println();
        // toggleABit(45,3);
    }
}