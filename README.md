# Competitive coding practice repo

## Tree:
### _Supplementary files:_
1. __gen_tree.cpp__
    
    __UDTs:__
    
    * Node

        Stores the integer value of node of the tree and the points to its left and right branches.

        ```
        struct Node {
            int data;
            Node *left, *right;
        };
        ```

    __Functions:__

    * `Node *BuildTree(string seq);`
    
        Generate a tree from a string with node values separatedby space and N as null node, the values are to be takenin level order.

        __example:__
        ```
        input tree:
                                      1
                                    /  \  
                                   2    3 
                                  / \    \
                                 4   6    7
                                    /    / \
                                   5    8   9

        input: 1 2 3 4 6 N 7 N N 5 N 8 9
        output: <pointer to the root node>
        ```
