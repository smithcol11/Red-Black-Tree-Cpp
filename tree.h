// Colin Smith
// CS 202
// Program 3
// May 15th, 2020
// Sources: https://www.youtube.com/watch?v=JwgeECkckRo
// Sources: https://www.coders-hub.com/2015/07/red-black-tree-rb-tree-using-c.html

#include "info.h"

class node
{
    public:
        // constructor and destructor
        node();
        ~node();
        info * data;
        node * parent; // pointer to parent to determine color
        node * left;
        node * right;
        char color; // Red or Black, r or b

    private:

};

// Red Black tree
class tree
{
    public:
        // constructor and destructor
        tree();
        ~tree();
        // Wrapper functions ***************************************
        int insert(info & toAdd); // insert into tree
        int retrieve(const String & toFind, info * & object) const; // retrieve from tree
        int display(const String & toShow) const; // display single item by name, 1st iteration
        int displayAll() const; // displays all
        int remove(const String & toDel); // removes a single item by name, 1st iteration
        int removeAll(); // removes all nodes from tree
        int fileWrite(); // writes to file at end of program

    private:
        // Data
        node * root;

        // Recursive functions *************************************
        int insert(node * & root, node * & prev, info & toAdd); // insert into tree
        int balance(node * leaf); // balances RB tree in case of rules broken or recoloring needed
        int rotateLeft(node * leaf); // rotates the tree counter clockwise
        int rotateRight(node * leaf); // rotates the tree clockwise
        int retrieve(node * root, const String & toFind, info * & object) const;  // retrieve from tree
        int display(node * root, const String & toShow) const;  // display single item by name, 1st iteration
        int displayAll(node * root) const; // displays all
        int remove(node * & root, const String & toDel); // removes a single item by name, 1st iteration
        int removeAll(node * & root); // removes all nodes from tree
        int fileWrite(node * root); // writes to file at end of program
};
