// Colin Smith
// CS 202
// Program 3
// May 15th, 2020
// Sources: https://www.youtube.com/watch?v=JwgeECkckRo
// Sources: https://www.coders-hub.com/2015/07/red-black-tree-rb-tree-using-c.html

#include "tree.h"

// Info functions **************************************************
info::info()
{
    subject = NULL;
    name = NULL;
    priority = 0;
}

info::info(info & toCopy) // copy constructor
{
    subject = toCopy.subject;
    name = toCopy.name;
    priority = toCopy.priority;
}

info::~info()
{
    subject = NULL;
    name = NULL;
    priority = 0;
}

// Node functions **************************************************
node::node()
{
    data = NULL;
    parent = NULL;
    left = NULL;
    right = NULL;
    color = 'r';
}

node::~node()
{
    data = NULL;
    parent = NULL;
    left = NULL;
    right = NULL;
    color = 'r';
}

// Tree functions **************************************************
tree::tree()
{
    root = NULL;
}

tree::~tree()
{
    if(root)
    {
        delete root->data;
        delete root;
    }
    root = NULL;
}

// Wrapper functions ***********************************************
int tree::insert(info & toAdd) // insert into tree
{
    node * prev = NULL;
    return insert(root, prev, toAdd);
}

int tree::retrieve(const String & toFind, info * & object) const // retrieve from tree
{
    return retrieve(root, toFind, object);
}   

int tree::display(const String & toShow) const // display single item by name, 1st iteration
{
    return display(root, toShow);
}

int tree::displayAll() const // displays all
{
    return displayAll(root);
}

int tree::remove(const String & toDel) // removes a single item by name, 1st iteration
{
    return remove(root, toDel);
}

int tree::removeAll() // removes all nodes from tree
{
    return removeAll(root);
}

int tree::fileWrite() // writes to file at end of program
{
    return fileWrite(root);
}

// Recursive functions *********************************************
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

int tree::balance(node * leaf) // balances RB tree in case of rules broken or recoloring needed
{
    if(!leaf)
    {
        return 1;
    }
    node * s; 
    node * g;
    // int direction;
    while(leaf->parent != NULL && leaf->parent->color == 'r')
    {
        g = leaf->parent->parent;
        if(g->right == leaf->parent)
        {
            if(g->left)
            {
                s = g->left;
                if(s->color == 'r')
                {
                    s->color = 'b';
                    g->color = 'r';
                    leaf->parent->color = 'b';
                    leaf = g;
                }
            }
            else
            {
                if(leaf->parent->right == leaf)
                {
                    leaf = leaf->parent;
                    rotateLeft(leaf);
                }
                leaf->parent->color = 'b';
                g->color = 'r';
                rotateRight(g);
            }

        }
        else
        {
            if(g->left)
            {
                s = g->left;
                if(s->color == 'r')
                {
                    s->color = 'b';
                    g->color = 'r';
                    leaf->parent->color = 'b';
                    leaf = g;
                }
            }
            else
            {
                if(leaf->parent->left == leaf)
                {
                    leaf = leaf->parent;
                    rotateRight(leaf);
                }
                leaf->parent->color = 'b';
                g->color = 'r';
                rotateLeft(g);
            }
        }
        root->color = 'b';
    }
    return 1;
}

int tree::rotateLeft(node * leaf) // rotates the tree counter clockwise
{
    if(!leaf->right)
    {
        return 0;
    }
    else
    {
        node * temp = leaf->right;
        if(temp->left)
        {
            leaf->right = temp->left;
            temp->left->parent = leaf;
        }
        else
        {
            leaf->right = NULL;
        }
        if(leaf->parent)
        {
            temp->parent = leaf->parent;
        }
        if(!leaf->parent)
        {
            root = temp;
        }
        else
        {
            if(leaf == leaf->parent->left)
            {
                leaf->parent->left = temp;
            }
            else
            {
                leaf->parent->right = temp;
            }
        }
        temp->left = leaf;
        leaf->parent = temp;
    }
    return 1;
}

int tree::rotateRight(node * leaf) // rotates the tree clockwise
{
    if(!leaf->left)
    {
        return 0;
    }
    else
    {
        node * temp = leaf->left;
        if(temp->right)
        {
            leaf->left = temp->right;
            temp->right->parent = leaf;
        }
        else
        {
            leaf->left = NULL;
        }
        if(leaf->parent)
        {
            temp->parent = leaf->parent;
        }
        if(!leaf->parent)
        {
            root = temp;
        }
        else
        {
            if(leaf == leaf->parent->left)
            {
                leaf->parent->left = temp;
            }
            else
            {
                leaf->parent->right = temp;
            }
        }
        temp->right = leaf;
        leaf->parent = temp;
    }
    return 1;
}

int tree::retrieve(node * root, const String & toFind, info * & object) const  // retrieve from tree
{
    if(!root)
    {
        return 0;
    }
    int result;
    result = root->data->compare(toFind);
    if(result == 0)
    {
        object = root->data;
        return 1;
    }
    else if(result == -1)
    {
        return retrieve(root->left, toFind, object);
    }
    else if(result == 1)
    {
        return retrieve(root->right, toFind, object);
    }
    return 1;
}

int tree::display(node * root, const String & toShow) const  // display single item by name, 1st iteration
{
    if(!root)
    {
        return 0;
    }
    int result;
    result = root->data->compare(toShow);
    if(result == 0)
    {
        return root->data->display();
    }
    else if(result == -1)
    {
        return display(root->left, toShow);
    }
    else if(result == 1)
    {
        return display(root->right, toShow);
    }
    return 1;
}

int tree::displayAll(node * root) const // displays all
{
    if(!root)
    {
        return 0;
    }
    displayAll(root->left);
    // cout << root->color << endl; // testing
    root->data->display();
    displayAll(root->right);
    return 1;
}

// remove used BST algorithm from 163 to delete a node, then balances with balance function
int tree::remove(node * & root, const String & toDel) // removes a single item by name, 1st iteration
{
    if(!root)
    {
        return 0;
    }
    int result = root->data->compare(toDel);
    if(result == 0)
    {
        if(!root->left && !root->right)
        {
            delete root->data;
            delete root;
            root = NULL;
        }
        else if(root->left && !root->right)
        {
            node * temp = root;
            root = root->left;
            delete temp->data;
            delete temp;
            temp = NULL;
        }
        else if(!root->left && root->right)
        {
            node * temp = root;
            root = root->right;
            delete temp->data;
            delete temp;
            temp = NULL;
        }
        else if(root->left && !root->right->left)
        {
            node * temp = root;
            root = root->right;
            root->left = temp->left;
            delete temp->data;
            delete temp;
            temp = NULL;
        }
        else if (root->left && root->right->left)
        {
            node * temp = root;
            node * current = root->right;
            node * prev = current;
            while (current->left)
            {
                prev = current;
                current = current->left;
            }
            root = current;
            root->left = temp->left;
            root->right = temp->right;
            prev->left = current->right;
            delete temp->data;
            delete temp;
            temp = NULL;
        }
        return balance(root);
    }
    remove(root->left, toDel);
    remove(root->right, toDel);
    return 1;
}

int tree::removeAll(node * & root) // removes all nodes from tree
{
    if(!root)
    {
        return 0;
    }
    removeAll(root->left);
    removeAll(root->right);
    delete root->data;
    delete root;
    root = NULL;
    return 1;
}

int tree::fileWrite(node * root) // writes to file at end of program
{
    if(!root)
    {
        return 0;
    }

    fileWrite(root->left);

    ofstream file;
    file.open("test.txt", ios::app);
    if(!file)
    {
        return 0;
    }
    // dynamic cast to determine which object to write into file at current node
    calender * cal = dynamic_cast<calender*>(root->data);
    if(cal)
    {
        file << *cal << endl;
    }
    website * web = dynamic_cast<website*>(root->data);
    if(web)
    {
        file << *web << endl;
    }
    zoom * zoo = dynamic_cast<zoom*>(root->data);
    if(zoo)
    {
        file << *zoo << endl;
    }
    file.close();
    file.clear();

    fileWrite(root->right);
    return 1;
}