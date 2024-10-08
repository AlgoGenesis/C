import java.util.ArrayList;
public class StackDSByArrayList{
    static int[] arr={1,2,3};
    static int size=3;
    static void increaseArraySize(){
        int n = arr.length+1;
        int[] b = new int[n];
        arr = b;
        size++;
    }
    static void decreaseArraySize(){
        int n = arr.length-1;
        int[] b = new int[n];
        arr = b;
        size--;
    }
    static void push(int x){
        int []c=new int[arr.length+1];
        for(int i=0;i<=arr.length-1;i++){
            c[i]=arr[i];
        }
        c[arr.length]=x;
        increaseArraySize();
        arr=c;
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();

    }
    static void pop(){
        int []c=new int [arr.length-1];
        for(int i=0;i<arr.length-1;i++){
            c[i]=arr[i];
        }
        decreaseArraySize();
        arr=c;
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }

    public static void main(String[] args){
        push(25);
        push(12);
        System.out.println("size:"+size);
        push(8);
        System.out.println("size:"+size);
        pop();
    }
}