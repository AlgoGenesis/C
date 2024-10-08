import java.util.*;
public class QueueLinkedListImplementation {
    public static class Node {
        int data;
        Node next;
        Node (int data) {
            this.data = data;
            this.next = null;
        }
    }
    public static class LinkedListQueue {
        Node head = null;
        int size = 0;
        void push (int data) {
            Node newNode = new Node(data);
            if (head == null) {
                head = newNode;
            } else {
                Node current = head;
                while (current.next != null) {
                    current = current.next;
                }
                current.next = newNode;
            }
            size++;
        }
        void pop() {
            head = head.next;
            size--;
        }
        void erase() {
            head = null;
        }
        int peek() {
            if (head == null) {
                System.out.println("Stack is Empty");
                return -1;
            }
            return head.data;
        }
        int size() {
            return size;
        }
        boolean isEmpty() {
            if (size() == 0) {
                return true;
            } else {
                return false;
            }
        }
        void display() {
            Node current = head;
            while (current != null) {
                System.out.print(current.data + " ");
                current = current.next;
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        LinkedListQueue st = new LinkedListQueue();
        st.push(4);
        st.display();
        st.push(8);
        st.display();
        int a  = st.peek();
        System.out.println(a);
        st.push(20);
        st.display();
        System.out.println(st.size());
        st.pop();
        st.display();
        System.out.println(st.size());
        st.erase();
        st.push(5);
        st.display();
    }
}
