### Problem Statement:
You need to find the **longest common prefix** among an array of strings. A **prefix** is a substring that appears at the beginning of the string, and the task is to find the longest such prefix common to all the strings in the input array.

### Approach Overview:
This solution uses a **Trie (Prefix Tree)** data structure to help find the common prefix. Here's a breakdown of how the Trie works in this context:

- **TrieNode**: Represents each character in the trie. Each node contains:
  - `ch`: The character it represents.
  - `children[26]`: An array to hold pointers to the child nodes for each letter of the alphabet ('a' to 'z').
  - `isTerminal`: A boolean indicating whether this node marks the end of a word.
  - `childCount`: Tracks how many children nodes a node has (this helps in finding the common prefix).

- **Insert function**: Inserts words into the Trie, creating child nodes if necessary.

- **Longest Common Prefix function**: Traverses the Trie from the root node, following the path of the common prefix until it reaches a point where the commonality breaks (i.e., multiple branches or a terminal node).

---

### Dry Run of the Code:
Let’s go through an example step by step with the input:

```c
char *strs[] = {"flower", "flow", "flight"};
```

#### Step 1: **Insert the words into the Trie**

1. **Insert "flower"**:
    - Start at the root node (TrieNode with `ch='\0'`).
    - Insert each character of "flower":
      - `f`: No child exists at index `'f' - 'a'`, so create a new node and add it as a child of the root.
      - `l`: No child exists at index `'l' - 'a'`, so create a new node and add it under the `f` node.
      - `o`: Similarly, create a node for `o` under `l`.
      - `w`, `e`, `r`: Continue creating nodes for each character.
    - Mark the final node (for `r`) as terminal (`isTerminal = true`).

2. **Insert "flow"**:
    - Start at the root again.
    - Traverse through existing nodes (`f`, `l`, `o`, `w`) since they already exist in the Trie.
    - Mark the final node (for `w`) as terminal (`isTerminal = true`).

3. **Insert "flight"**:
    - Start at the root.
    - Traverse through existing nodes for `f` and `l` because they already exist.
    - At character `i`, no child exists, so create a new node and add it.
    - Create nodes for the remaining characters (`g`, `h`, `t`).
    - Mark the final node (for `t`) as terminal.

#### Step 2: **Find the Longest Common Prefix**

Now that the words are inserted into the Trie, we will traverse the Trie to find the longest common prefix:

- Start from the root node.
- The first word is `"flower"`, so we'll check each character of `"flower"` while traversing the Trie.

1. **First character `'f'`**:
   - The root has exactly one child, and it’s `f`. Continue traversing the Trie and add `f` to the prefix (`result = "f"`).

2. **Second character `'l'`**:
   - The `f` node also has exactly one child, which is `l`. Continue and add `l` to the prefix (`result = "fl"`).

3. **Third character `'o'`**:
   - The `l` node has two children: one for `o` (from "flower" and "flow") and one for `i` (from "flight"). Since the node has multiple children (`childCount > 1`), stop the traversal.

The longest common prefix we found is `"fl"`.

#### Output:
```
Longest Common Prefix: fl
```

### Key Points:

- The Trie helps build a common prefix by inserting each word one character at a time and following the path that is shared by all words.
- The traversal stops when the commonality breaks (either multiple children or reaching the terminal node of a word).
- In this case, the longest common prefix is `"fl"`, because "flower", "flow", and "flight" all share the first two characters, but differ after that.