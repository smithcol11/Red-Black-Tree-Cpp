// Colin Smith
// CS 202
// Program 3
// May 15th, 2020
// Sources: https://www.youtube.com/watch?v=JwgeECkckRo
// Sources: https://www.coders-hub.com/2015/07/red-black-tree-rb-tree-using-c.html

#include "String.h"

// base class
class info
{
    public:
        // constructor and destructor
        info();
        info(info & toCopy);
        virtual ~info(); // virtual destructor
        virtual int insert() = 0;
        virtual int display() const = 0;
        virtual int compare(const String & toFind) const = 0;
        virtual int remove() = 0;
        String name; // testing

    protected:
        
        String subject; // home, school, or work
        int priority; // ex: 1, 2, ... , n

};

class calender: public info
{
    public:
        // constructors and destructor
        calender();
        calender(calender & toCopy);
        ~calender();
        int insert();
        int display() const;
        int compare(const String & toFind) const;
        int remove();
        int Date(); // unique function to calender

        // Operator Overloading
        // calender & operator = (calender & toCopy);
        friend ostream & operator << (ostream & out, const calender & toOut);
        friend istream & operator >> (istream & in, calender & toIn);
        calender & operator += (const calender & toAdd);
        calender & operator + (const calender & toAdd);
        bool operator == (const calender & toTest);
        bool operator != (const calender & toTest);
        bool operator < (const calender & toTest);
        bool operator <= (const calender & toTest);
        bool operator > (const calender & toTest);
        bool operator >= (const calender & toTest);

    protected:
        String date;
    
};

class website: public info
{
    public:
        // constructors and destructor
        website();
        website(website & toCopy);
        ~website();
        int insert();
        int display() const;
        int compare(const String & toFind) const;
        int remove();
        int Url(); // unique function to website

        // Operator Overloading
        friend ostream & operator << (ostream & out, const website & toOut);
        friend istream & operator >> (istream & in, website & toIn);

    protected:
        String url;
};

class zoom: public info
{
    public:
        // constructors and destructor
        zoom();
        zoom(zoom & toCopy);
        ~zoom();
        int insert();
        int display() const;
        int compare(const String & toFind) const;
        int remove();
        int Id(); // unique function to zom

        // Operator Overloading
        friend ostream & operator << (ostream & out, const zoom & toOut);
        friend istream & operator >> (istream & in, zoom & toIn);

    protected:
        int id;
    
};
