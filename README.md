# Red-Black-Tree-Cpp
This is an advanced tree that I coded in C++ for my Data Structures class. It is a more advanced and balanced Binary Search Tree called a Red Black Tree. It uses color coded nodes to maintain its balance. This particular program utilizes dynamic binding and stores information about calender, website, and zoom events.
This program uses my personally created string class which can be found in my repositories. These can be replaced by the '#include<string>' or by cstrings. 

## Code Snippets
> tree.h
```c++
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
```
> tree.cpp, insert function
```c++
  int tree::insert(node * & root, node * & prev, info & toAdd) // insert into tree at leaf
{
    if(!root)
    {
        root = new node;
        root->parent = prev;
        calender * cal = dynamic_cast<calender*>(&toAdd);
        if(cal)
        {
            root->data = new calender(*cal);
        }
        website * web = dynamic_cast<website*>(&toAdd);
        if(web)
        {
            root->data = new website(*web);
        }
        zoom * zoo = dynamic_cast<zoom*>(&toAdd);
        if(zoo)
        {
            root->data = new zoom(*zoo);
        }
        if(this->root == root)
        {
            root->color = 'b';
            return 1;
        }
        return balance(root);
    }
    int result;
    result = root->data->compare(toAdd.name);
    prev = root;
    if(result >= 0)
    {
        insert(root->right, prev, toAdd);
    }
    else
    {
        insert(root->left, prev, toAdd);
    }
    return result;
}
```
