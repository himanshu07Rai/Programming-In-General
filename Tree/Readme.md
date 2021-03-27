# Binary Search Tree

Binary Search Tree is a node-based binary tree data structure which has the following properties:

1. The left subtree of a node contains only nodes with keys lesser than the node’s key.

2. The right subtree of a node contains only nodes with keys greater than the node’s key.

3. The left and right subtree each must also be a binary search tree.

      ![image](https://user-images.githubusercontent.com/64080063/112709717-496a5c80-8eee-11eb-88ff-3ae04fce4328.png)
      
## Why do we need a Binary Search Tree?
The two major factors that make binary search tree an optimum solution to any real-world problems are Speed and Accuracy.

Due to the fact that the binary search is in a branch-like format with parent-child relations, the algorithm knows in which location of the tree the elements need to be searched.

This decreases the number of key-value comparisons the program has to make to locate the desired element.

Additionally, in case the element to be searched greater or less than the parent node, the node knows which tree side to search for.

The reason is, the left sub-tree is always lesser than the parent node, and the right sub-tree has values always equal to or greater than the parent node.

BST is commonly utilized to implement complex searches, robust game logics, auto-complete activities, and graphics.

The algorithm efficiently supports operations like search, insert, and delete.

### Types of Binary Trees

Three kinds of binary trees are:

Complete binary tree: All the levels in the trees are full of last level's possible exceptions. Similarly, all the nodes are full, directing the far left.

Full binary tree: All the nodes have 2 child nodes except the leaf.

Balanced or Perfect binary tree: In the tree, all the nodes have two children. Besides, there is the same level of each subnode.

### Representation

We have two representations : 

1. Sequential Representation
2. Linked Representation 


## How are binary search trees stored in computer memory?
