// Colin Smith
// CS 202
// Program 3
// May 15th, 2020
// Sources: https://www.youtube.com/watch?v=JwgeECkckRo
// Sources: https://www.coders-hub.com/2015/07/red-black-tree-rb-tree-using-c.html

#include "tree.h"

int main()
{
    // objects to be used for each class
    tree List;
    calender temp1;
    website temp2;
    zoom temp3;

    // variables that will be used in main
    int choice = -1;
    String name;
    int result = 0;

    cout << "Welcome to my rubbish program! \n";
    cout << "We will use it to schedule events. \n";

    // while loop to allow for a choice driven menu loop
    while(choice != 0)
    {
        result = 0;
        cout << "What would you like to do? \n";
        cout << "   Create Event           (1) \n";
        cout << "   Remove Event           (2) \n";
        cout << "   Display by Name        (3) \n";
        cout << "   Display All            (4) \n";
        cout << "   Remove All             (5) \n";
        cout << "   Operator Testing       (6) \n";
        cout << "   Retrieve               (7) \n";
        cout << "   Exit                   (0) \n";

        cin >> choice;
        cin.ignore();

        // creates a new event
        if(choice == 1)
        {
            cout << "What kind of event would you like to add? \n";
            cout << "   Calender (1) \n";
            cout << "   Website  (2) \n";
            cout << "   Zoom     (3) \n";
            cin >> choice;
            cin.ignore();
            if(choice == 1)
            {
                temp1.insert();
                result = List.insert(temp1);
            }
            else if(choice == 2)
            {
                temp2.insert();
                result = List.insert(temp2);

            }
            else if(choice == 3)
            {
                temp3.insert();
                result = List.insert(temp3);
            }
        }

        // removes an event by name
        else if(choice == 2)
        {
            cout << "What is the name of the event you would like to remove? ";
            cin >> name;
            result = List.remove(name);
            if(result == 0)
            {
                cout << "Unable to remove specified event. \n";
            }
            else
            {
                cout << "Event removed!\n";
            }
        }

        // displays event by name
        else if(choice == 3)
        {
            cout << "What is the name of the event you would like to display? ";
            cin >> name;
            result = List.display(name);
            if(result == 0)
            {
                cout << "Unable to find that event. \n";
            }
        }

        // displays all events
        else if(choice == 4)
        {
            result = List.displayAll();
            if(result == 0)
            {
                cout << "No events to display. \n";
            }
        }

        // deletes all data
        else if(choice == 5)
        {
            List.removeAll();
            cout << "All data removed!... \n";
        }

        // used to test operation overloading
        else if(choice == 6)
        {
            calender test;
            calender test2;
            cout << "Enter data into temp objects to run operators." << endl;
            test.insert();
            cout << "And the next one. " << endl;
            test2.insert();
            if(test == test2)
            {
                cout << "They are equal. " << endl;
            }
            
            if(test != test2)
            {
                cout << "They are not equal. " << endl;
            }
            
            if(test < test2)
            {
                cout << "Test is less than. " << endl;
            }
            
            if(test <= test2)
            {
                cout << "Test is less than or equal. " << endl;
            }
            
            if(test > test2)
            {
                cout << "Test is greater than. " << endl;
            }
            
            if(test >= test2)
            {
                cout << "Test is greater than or equal. " << endl;
            }
        }
        // option to retrieve then display event, saves to pointer of base class
        else if(choice == 7)
        {
            info * object;
            String temp;
            cout << "What is the name of the event you would like to retrieve? ";
            cin >> temp;
            result = List.retrieve(temp, object);
            if(result == 1)
            {
                cout << "Found!" << endl;
                object->display();
            }
            else
            {
                cout << "Unable to retrieve that event. " << endl;
            }
        }
    }
    // File writing occurs here
    List.fileWrite();

    return 0;
};