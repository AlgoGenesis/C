import java.util.Arrays;
public class QueueArrayListImplementation {
    static int[] arr = {};
    static int num = 4;
    static void increaseArraySize() {
        int n = arr.length * 2;
        int[] b = new int[n];
        for (int i = 0; i < arr.length; i++) {
            b[i] = arr[i];
        }
        arr = b;
        num++;
    }
    static void decreaseArraySize() {
        int n = arr.length - 1;
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = arr[i];
        }
        arr = b;
        num--;
    }
    static void push(int x) {
        int[] c = new int[arr.length + 1]; // Change to char[] instead of Object[]
        for (int i = 0; i < arr.length; i++) {
            c[i] = arr[i];
        }
        c[arr.length] = x;
        increaseArraySize();
        arr = c;
    }
    static void pop() {
        int[] c = new int[arr.length - 1];
        for (int i = 0; i < c.length; i++) {
            c[i] = arr[i+1];
        }
        decreaseArraySize();
        arr = c;
    }
    static void display() {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

    }
    public static void main(String[] args) {
        push(4);
        display();
        push(8);
        display();
        push(20);
        display();
        pop();
        display();
        push(5);
        display();
    }
}