### MULTISTAGE GRAPH

This program calculates the shortest path from a given source node to a target node in a directed graph using a dynamic programming approach. The graph is represented as an adjacency matrix, where the user provides input for the number of vertices and the adjacency matrix values.

---
### Working:
The program's core function, shortestDist, uses dynamic programming to compute the shortest path in a directed graph. Here's how it works:

1. **Initialization:**

The distance array dist[] is initialized with INF for all nodes except the target node, which has a distance of 0. This array will store the shortest known distances from each node to the target.
The path array path[] is initialized to store the next node on the shortest path for each node.

2. **Dynamic Programming Loop:**

The function iterates from the target node backward to the source, evaluating each node's potential distance to the target by checking its connection to subsequent nodes.
If the current distance from node i to the target is greater than the distance from node i to j plus dist[j] (where j is a neighboring node), it updates dist[i] and sets path[i] to j.

3. **Path Construction:**

If a valid path exists, the function prints the shortest distance from the source to the target.
It then traces the path from the source to the target using the path[] array and prints each node in the order they are visited.

---
### Example:
![Screenshot 2024-10-22 184618](https://github.com/user-attachments/assets/b4a70ddf-332e-4885-b367-38b20362d31f)

### Procedure
In the above graph, cost of an edge is represented as c(i, j). We need to find the minimum cost path from vertex 1 to vertex 12. Using the below formula we can find the shortest cost path from source to destination:

cost(i,j)=min{c(j,l)+cost(i+1,l)}

### Step 1:

Stage 5

cost(5,12)=c(12,12)=0

We use forward approach here therefore (cost(5,12) = 0 ). Here, 5 represents the stage number and 12 represents a node in that stage. Since there are no outgoing edges from vertex 12, the cost is 0 and D[12]=12

### Step 2:

Stage 4

cost(4,9)= c(9,12) = 4 D[9]=12

cost(4,10) = c(10,12) = 2 D[10]=12

cost(4,11) = c(11,12) = 5 D[11]=12

### Step 3:

Stage 3

cost(3,6)=min{c(6,9)+cost(4,9), c(6,10)+cost(4,10)} = min{6+4,5+2} =min{10,7}=7 D[6]=10

cost(3,7)=min{c(7,9)+cost(4,9), c(7,10)+cost(4,10)} = min{4+4,3+2} =min{8,5}=5 D[7]=10

cost(3,8)=min{c(8,10)+cost(4,10), c(8,11)+cost(4,10)} = min{5+2,6+5} =min{7,11}=7 D[7]=10

### Step 4:

Stage 2

cost(2,2) = min{c(2,6)+cost(3,6), c(2,7)+cost(3,7), c(2,8)+cost(3,8)} = min{4+7,2+5,1+7}=min{11,7,8}=7 D[2]=7

cost(2,3) = min{c(3,6)+cost(3,6), c(3,7)+cost(3,7)} = min{2+7,7+5}=min{9,12}=9 D[3]=6

cost(2,4) = min{c(4,8)+cost(3,8)} = min{11+7}=min{18}=18 D[4]=8

cost(2,5) = min{c(5,7)+cost(3,7), c(5,8)+cost(3,8)} = min{11+5,8+7}=min{16,15}=15 D[3]=8

### Step 5:

Stage 1

cost(1,1) = min(c(1,2)+cost(2,2), c(1,3)+cost(2,3), c(1,4)+cost(2,4), c(1,5)+cost(2,5)} = min{9+7, 7+9, 3+18, 2+15}=min{16,16,21,17}=16

D[1] = 2 (we can take 3 also )

The path through which we have to find the shortest distance

D ( 1) = 2

D ( 2) = 7

D ( 7) = 10

D (10) = 12

So, the minimum –cost path is,  ```1 -> 2 -> 7 -> 10 -> 12```

The cost is ```9+2+3+2=16```

---

### Sample Input and Output:

Enter the number of vertices in the graph: 12                           
Enter the adjacency matrix (use 99 for INF):                    
99 9 7 3 2 99 99 99 99 99 99 99                           
99 99 99 99 99 4 2 1 99 99 99 99                       
99 99 99 99 99 2 7 99 99 99 99 99                          
99 99 99 99 99 99 99 11 99 99 99 99                              
99 99 99 99 99 99 11 8 99 99 99 99                             
99 99 99 99 99 99 99 99 6 5 99 99                                  
99 99 99 99 99 99 99 99 4 3 99 99                           
99 99 99 99 99 99 99 99 99 5 6 99                                
99 99 99 99 99 99 99 99 99 99 99 4                              
99 99 99 99 99 99 99 99 99 99 99 2                                  
99 99 99 99 99 99 99 99 99 99 99 5                          
99 99 99 99 99 99 99 99 99 99 99 0                          

Enter the source node: 1                       
Enter the target node: 12                    
The shortest path distance from node 1 to node 12 is: 16                      
Path: 1 -> 2 -> 7 -> 10 -> 12


