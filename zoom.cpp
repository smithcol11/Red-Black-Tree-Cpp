// Colin Smith
// CS 202
// Program 3
// May 15th, 2020
// Sources: https://www.youtube.com/watch?v=JwgeECkckRo
// Sources: https://www.coders-hub.com/2015/07/red-black-tree-rb-tree-using-c.html

#include "tree.h"

zoom::zoom(): info()
{
    id = 0;
}

zoom::zoom(zoom & toCopy): info(toCopy)  // copy constructor
{
    id = toCopy.id;
}

zoom::~zoom()
{
    id = 0;
}

int zoom::insert()
{
    cout << "What is the name of this event? \n";
    cin >> name;
    cout << "What is the subject of this event? \n";
    cout << "(Home, School, or Work?) \n";
    cin >> subject;
    cout << "What is the priority of this event? \n";
    cout << "(1, 2, ... , n?) \n";
    cin >> priority;
    Id();
    return 1;
}

int zoom::display() const
{
    cout << "ZOOM:" << endl;
    cout << "   Name:      " << name << endl;
    cout << "   Subject:   " << subject << endl;
    cout << "   Priority:  " << priority << endl;
    cout << "   ID:        " << id << endl;
    return 1;
}

int zoom::compare(const String & toFind) const
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

int zoom::remove()
{
    id = 0;
    return 1;
}

int zoom::Id()
{
    cout << "What is the ID of this event? \n";
    cin >> id;
    return 1;
}

// Operator Overloading Functions **********************************

ostream & operator << (ostream & out, const zoom & toOut)
{
    out << "Zoom:" << endl;
    out << "    Name:     " << toOut.name << endl;
    out << "    Subject:  " << toOut.subject << endl;
    out << "    Priority: " << toOut.priority << endl;
    out << "    ID:       " << toOut.id << endl;
    return out;
}

istream & operator >> (istream & in, zoom & toIn)
{
    return in;
}
