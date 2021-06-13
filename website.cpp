// Colin Smith
// CS 202
// Program 3
// May 15th, 2020
// Sources: https://www.youtube.com/watch?v=JwgeECkckRo
// Sources: https://www.coders-hub.com/2015/07/red-black-tree-rb-tree-using-c.html

#include "tree.h"

website::website(): info()
{
    url = NULL;
}

website::website(website & toCopy): info(toCopy)  // copy constructor
{
    url = toCopy.url;
}

website::~website()
{
    url = NULL;
}

int website::insert()
{
    cout << "What is the name of this event? \n";
    cin >> name;
    cout << "What is the subject of this event? \n";
    cout << "(Home, School, or Work?) \n";
    cin >> subject;
    cout << "What is the priority of this event? \n";
    cout << "(1, 2, ... , n?) \n";
    cin >> priority;
    Url();
    return 1;
}

int website::display() const
{
    cout << "Website:" << endl;
    cout << "   Name:      " << name << endl;
    cout << "   Subject:   " << subject << endl;
    cout << "   Priority:  " << priority << endl;
    cout << "   URL:       " << url << endl;
    return 1;
}

int website::compare(const String & toFind) const
{
    if(name == toFind)
    {
        return 0;
    }
    else if(toFind < name)
    {
        return -1;
    }
    else if(toFind > name)
    {
        return 1;
    }
    return 0;
}

int website::remove()
{
    url = NULL;
    return 1;
}

int website::Url()
{
    cout << "What is the URL of this event? \n";
    cin >> url;
    return 1;
}

// Operator Overloading Functions **********************************

ostream & operator << (ostream & out, const website & toOut)
{
    out << "Website:" << endl;
    out << "    Name:     " << toOut.name << endl;
    out << "    Subject:  " << toOut.subject << endl;
    out << "    Priority: " << toOut.priority << endl;
    out << "    URL:      " << toOut.url << endl;
    return out;
}

istream & operator >> (istream & in, website & toIn)
{
    return in;
}
