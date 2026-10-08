#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node* next;
};

// INSERTION AT START :

void insertAtStart (Node*& list, int x)
{
    Node* p = new Node;

    p->info = x;
    p->next = list;

    list = p;
}

// INSERTION AT END :

void insertAtEnd(Node*& list, int x)
{
    Node* p = new Node;

    p->info = x;
    p->next = NULL;

    if(list == NULL)
    {
        list = p;
    }
    else
    {
        Node* q = list;

        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
}

// DELETION AT START :

void DeletionAtStart(Node*& list)
{
    if (list == NULL)
    {
        cout << "No need to Delete" << endl;
    }
    else
    {
        Node* p = list;

        list = p->next;
        delete p;
    }
}

// DELETION AT END :

void DeletionAtEnd(Node*& list)
{
    if(list == NULL)
    {
        cout << "NO Thing To Delete Here." << endl;
    }
    else if (list->next == NULL)
    {
        delete list;
        list = NULL;
    }
    else
    {
        Node* p = list;
        Node* q = list->next;

        while(q->next != NULL)
        {
            p = q;
            q = q->next;
        }
        p->next = NULL;

        delete q;
    }
}

// REVERSE USING LOOP :

void reverseUsingLoop(Node*& list)
{
    Node* previous = NULL;
    Node* current = list;
    Node* nextnode;

    while(current != NULL)
    {
        nextnode = current->next; // save data
        current->next = previous; // reverse list

        previous = current; // move prev forward
        current = nextnode; // move curr forward
    }

    list = previous;
    cout << "List Reversed Using LOOP" << endl;
}

// REVERSE USING RECURSION :
void reverseUsingRecursion(Node*& list)
{
    if(list == NULL || list->next == NULL)
    {
        return;
    }

    Node* rest = list->next;

    reverseUsingRecursion(rest);

    list->next->next = list;
    list->next = NULL;
    list = rest;
}

// MERGE 2 LINKED LISTS AND GENERATE A THIRD ONE :
Node* mergeLists(Node* list1, Node* list2)
{
    Node* mergedList = NULL;

    // Copy elements of list1 into mergedList
    Node* p = list1;
    while (p != NULL)
    {
        insertAtEnd(mergedList, p->info);
        p = p->next;
    }

    // Copy elements of list2 into mergedList
    Node* q = list2;
    while (q != NULL)
    {
        insertAtEnd(mergedList, q->info);
        q = q->next;
    }

    return mergedList;
}

// REMOVE MULTIPLE (CONSECUTIVE) OCCURRENCES OF A NUMBER :
void removeDuplicates(Node*& list)
{
    if (list == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* current = list;

    while (current != NULL && current->next != NULL)
    {
        if (current->info == current->next->info)
        {
            Node* duplicate = current->next;
            current->next = current->next->next; // Bypass the duplicate node
            delete duplicate; // Free memory
        }
        else
        {
            current = current->next; // Move forward only if values differ
        }
    }
    cout << "Consecutive duplicate occurrences removed successfully!" << endl;
}

// DISPLAY :

void Display(Node* list)
{
    Node* p = list;
    while(p != NULL)
    {
        cout << p->info << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}


int main()
{
    Node* list = NULL;

    int choice;
    int value;

    do
    {
        cout << " ===== LINKED LIST ==========" << endl;

        cout << " =============================" << endl;
        cout << " 1 . Insert at Start" << endl;
        cout << " 2 . Insert At End" << endl;

        cout << "========================" << endl;
        cout << " 3 . Delete At Start" << endl;
        cout << " 4 . Delete At End" << endl;

        cout << "========================" << endl;
        cout << " 5 . Display LIST" << endl;

        cout << "========================" << endl;
        cout << " 6 . Reverse Using LOOP" << endl;
        cout << " 7 . Reverse Using Recursion" << endl;

        cout << " HERE WE ADD THE ADDITIONAL FUNCTIONS AS WE GUIDED : "<< endl;

             cout << "========================" << endl;

        cout << " 8 . Merge Two Lists into a Third One" << endl;
        cout << " 9 . Remove Multiple Occurrences (Duplicates)" << endl;
        cout << " 0 . Exit" << endl;
        cout << "========================" << endl;
        cout << endl;

        cout << "Enter Your choice To run the TASK: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "Enter value TO Add it in Start: " << endl;
            cin >> value;
            insertAtStart(list, value);
            break;

        case 2:
            cout << "Enter Value to ADD it in the END: " << endl;
            cin >> value;
            insertAtEnd(list, value);
            break;

        case 3:
            DeletionAtStart(list);
            break;

        case 4:
            DeletionAtEnd(list);
            break;

        case 5:
            cout << "Here we'll Display the List: " << endl;
            Display(list);
            cout << endl << endl << endl;
            break;

        case 6:
            cout << "The Output is Reversed using Loop. PRESS 5 to Check" << endl;
            reverseUsingLoop(list);
            break;

        case 7:
            cout << "The Output is Reversed using Recursion. PRESS 5 to Check" << endl;
            reverseUsingRecursion(list);
            break;

        case 8:
        {
            // Checks if your main list is empty first
            if (list == NULL) {
                cout << "\n[Warning] Your main list is empty! Please insert some elements into it first (using Options 1 or 2).\n" << endl;
                break;
            }

            Node* list2 = NULL;
            int n2, val;

            cout << "\n--- Creating Second List ---" << endl;
            cout << "Enter number of elements for List 2: ";
            cin >> n2;
            for (int i = 0; i < n2; i++) {
                cout << "Enter value " << i + 1 << ": ";
                cin >> val;
                insertAtEnd(list2, val);
            }

            cout << "\nList 1 (Your Current Main List): ";
            Display(list);
            cout << "List 2: ";
            Display(list2);

            // Generate the third merged list using your main list as list1
            Node* thirdList = mergeLists(list, list2);

            cout << "\n----------------------------------------" << endl;
            cout << ">>> MERGED (THIRD) LIST OUTPUT: ";
            Display(thirdList);
            cout << "----------------------------------------" << endl;

            char makeActive;
            cout << "Do you want to make this merged list your main active list? (y/n): ";
            cin >> makeActive;
            if (makeActive == 'y' || makeActive == 'Y') {
                list = thirdList;
                cout << "Success! Merged list is now your main active list.\n" << endl;
            } else {
                cout << "Merged list displayed successfully.\n" << endl;
            }
            break;
        }

        case 9:
        {
            cout << "\n--- Original List Before Removing Duplicates ---" << endl;
            Display(list);

            removeDuplicates(list);

            cout << ">>> LIST AFTER REMOVING DUPLICATES: ";
            Display(list);
            cout << endl;
            break;
        }

        case 0:
            cout << "Program Ended" << endl;
            break;

        default:
            cout << "invalid Choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
