import java.util.ArrayList;
import java.util.Collections;

public class PriorityQueueByArrayList {

    private ArrayList<Integer> queue;

    public PriorityQueueByArrayList() {
        queue = new ArrayList<>();
    }


    // Enqueue operation
    public void enqueue(int value) {
        queue.add(value);
        heapifyUp(queue.size() - 1);
    }

    // Dequeue operation
    public int dequeue() {
        if (queue.isEmpty()) {
            System.out.println("Priority queue is empty");
            return -1;
        }
        int maxPriorityIndex = findMaxPriorityIndex();
        int maxPriority = queue.get(maxPriorityIndex);
        queue.set(maxPriorityIndex, queue.get(queue.size() - 1));
        queue.remove(queue.size() - 1);
        heapifyDown(maxPriorityIndex);
        return maxPriority;
    }

    // Heapify operation (bottom-up)
    private void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && queue.get(parent) < queue.get(index)) {
            Collections.swap(queue, parent, index);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    // Heapify operation (top-down)
    private void heapifyDown(int index) {
        int leftChild, rightChild, maxPriorityChild;
        while (true) {
            leftChild = 2 * index + 1;
            rightChild = 2 * index + 2;
            maxPriorityChild = index;
            if (leftChild < queue.size() && queue.get(leftChild) > queue.get(maxPriorityChild))
                maxPriorityChild = leftChild;
            if (rightChild < queue.size() && queue.get(rightChild) > queue.get(maxPriorityChild))
                maxPriorityChild = rightChild;
            if (maxPriorityChild == index)
                break;
            Collections.swap(queue, index, maxPriorityChild);
            index = maxPriorityChild;
        }
    }

    // Find index of the element with maximum priority
    private int findMaxPriorityIndex() {
        if (queue.isEmpty()) {
            return -1;
        }
        int maxPriorityIndex = 0;
        for (int i = 1; i < queue.size(); i++) {
            if (queue.get(i) > queue.get(maxPriorityIndex)) {
                maxPriorityIndex = i;
            }
        }
        return maxPriorityIndex;
    }

    // Display the priority queue
    public void display() {
        for (int i = 0; i < queue.size(); i++) {
            System.out.print(queue.get(i) + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        PriorityQueueByArrayList priorityQueue = new PriorityQueueByArrayList();
        priorityQueue.enqueue(10);
        priorityQueue.enqueue(20);
        priorityQueue.enqueue(15);
        priorityQueue.enqueue(40);
        priorityQueue.enqueue(50);

        System.out.println("Priority Queue:");
        priorityQueue.display();

        System.out.println("Dequeued element: " + priorityQueue.dequeue());
        System.out.println("Priority Queue after dequeue:");
        priorityQueue.display();
    }
}
