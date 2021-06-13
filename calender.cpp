// Colin Smith
// CS 202
// Program 3
// May 15th, 2020
// Sources: https://www.youtube.com/watch?v=JwgeECkckRo
// Sources: https://www.coders-hub.com/2015/07/red-black-tree-rb-tree-using-c.html

#include "tree.h"

calender::calender(): info()
{
    date = NULL;
}

calender::calender(calender & toCopy): info(toCopy)  // copy constructor
{
    date = toCopy.date;
}

calender::~calender()
{
    date = NULL;
}

int calender::insert()
{
    cout << "What is the name of this event? \n";
    cin >> name;
    cout << "What is the subject of this event? \n";
    cout << "(Home, School, or Work?) \n";
    cin >> subject;
    cout << "What is the priority of this event? \n";
    cout << "(1, 2, ... , n?) \n";
    cin >> priority;
    Date();
    return 1;
}

int calender::display() const
{
    cout << "Calender:" << endl;
    cout << "   Name:      " << name << endl;
    cout << "   Subject:   " << subject << endl;
    cout << "   Priority:  " << priority << endl;
    cout << "   Date:      " << date << endl;
    return 1;
}

int calender::compare(const String & toFind) const
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

int calender::remove()
{
    date = NULL;
    return 1;
}

int calender::Date()
{
    cout << "What is the date of this event? \n";
    cin >> date;
    return 1;
}

// Operator Overloading Functions **********************************

/* calender & calender::operator = (calender & toCopy)
{
    if(this)
    {
        delete this;
    }
    this = new calender(toCopy);
    return *this;
} */

ostream & operator << (ostream & out, const calender & toOut)
{
    out << "Calender:" << endl;
    out << "    Name:     " << toOut.name << endl;
    out << "    Subject:  " << toOut.subject << endl;
    out << "    Priority: " << toOut.priority << endl;
    out << "    Date:     " << toOut.date << endl;
    return out;
}

istream & operator >> (istream & in, calender & toIn)
{
    return in;
}

calender & calender::operator += (const calender & toAdd)
{
    name += toAdd.name;
    subject += toAdd.subject;
    priority = toAdd.priority;
    date = toAdd.date;
    return *this;
}

calender & calender::operator + (const calender & toAdd)
{
    name += toAdd.name;
    subject += toAdd.subject;
    priority = toAdd.priority;
    date = toAdd.date;
    return *this; 
}

bool calender::operator == (const calender & toTest)
{
    if(name == toTest.name)
    {
        return true;
    }
    return false;
}

bool calender::operator != (const calender & toTest)
{
    if(name != toTest.name)
    {
        return true;
    }
    return false;
}

bool calender::operator < (const calender & toTest)
{
    if(toTest.name < name)
    {
        return true;
    }
    return false;
}

bool calender::operator <= (const calender & toTest)
{
    if(toTest.name <= name)
    {
        return true;
    }
    return false;
}

bool calender::operator > (const calender & toTest)
{
    if(toTest.name > name)
    {
        return true;
    }
    return false;
}

bool calender::operator >= (const calender & toTest)
{
    if(toTest.name >= name)
    {
        return true;
    }
    return false;
}
