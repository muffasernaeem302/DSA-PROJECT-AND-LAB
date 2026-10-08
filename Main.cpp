```cpp
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};


// ==========================================
// INSERT AT START
// ==========================================
void insertStart(Node*& head, int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}


// ==========================================
// INSERT AT END
// ==========================================
void insertEnd(Node*& head, int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}


// ==========================================
// INSERT AT POSITION
// ==========================================
void insertMiddle(Node*& head, int value, int pos)
{
    if (pos == 1)
    {
        insertStart(head, value);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Invalid Position\n";
        return;
    }

    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}


// ==========================================
// DELETE FROM START
// ==========================================
void deleteStart(Node*& head)
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    Node* temp = head;

    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}


// ==========================================
// DELETE FROM END
// ==========================================
void deleteEnd(Node*& head)
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    Node* temp = head;

    if (temp->next == NULL)
    {
        head = NULL;
        delete temp;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;

    delete temp;
}


// ==========================================
// DELETE FROM POSITION
// ==========================================
void deleteMiddle(Node*& head, int pos)
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    if (pos == 1)
    {
        deleteStart(head);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Invalid Position\n";
        return;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}


// ==========================================
// SWAP TWO VALUES
// ==========================================
void swapValues(Node* head, int value1, int value2)
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    if (value1 == value2)
    {
        cout << "Both values are same. No swap needed.\n";
        return;
    }

    Node* first = NULL;
    Node* second = NULL;

    Node* temp = head;


    // Find first value
    while (temp != NULL)
    {
        if (temp->data == value1)
        {
            first = temp;
            break;
        }

        temp = temp->next;
    }


    // Find second value
    temp = head;

    while (temp != NULL)
    {
        if (temp->data == value2)
        {
            second = temp;
            break;
        }

        temp = temp->next;
    }


    // Check first value
    if (first == NULL)
    {
        cout << value1 << " not found in the list.\n";
        return;
    }


    // Check second value
    if (second == NULL)
    {
        cout << value2 << " not found in the list.\n";
        return;
    }


    // Swap values
    int tempValue = first->data;

    first->data = second->data;

    second->data = tempValue;

    cout << "Values swapped successfully!\n";
}


// ==========================================
// DISPLAY FORWARD
// ==========================================
void display(Node* head)
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    Node* temp = head;

    cout << "NULL <-> ";

    while (temp != NULL)
    {
        cout << temp->data << " <-> ";

        temp = temp->next;
    }

    cout << "NULL\n";
}


// ==========================================
// REVERSE DISPLAY
// ==========================================
void reverseDisplay(Node* head)
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    Node* temp = head;


    // Move to the last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }


    // Now move backward using prev
    cout << "NULL <-> ";

    while (temp != NULL)
    {
        cout << temp->data << " <-> ";

        temp = temp->prev;
    }

    cout << "NULL\n";
}


// ==========================================
// MAIN
// ==========================================
int main()
{
    Node* head = NULL;

    int n;
    int value;
    int choice;
    int pos;

    int value1;
    int value2;


    cout << "===== CREATE DOUBLY LINKED LIST =====\n";

    cout << "Enter number of nodes: ";
    cin >> n;


    // Create initial list
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter value for node " << i << " : ";
        cin >> value;

        insertEnd(head, value);
    }


    // Display initial list
    cout << "\nInitial Linked List:\n";

    display(head);


    // ==========================================
    // MENU
    // ==========================================
    do
    {
        cout << "\n===== DOUBLY LINKED LIST MENU =====\n";

        cout << "1. Insert at Start\n";
        cout << "2. Insert at Position\n";
        cout << "3. Insert at End\n";

        cout << "4. Delete from Start\n";
        cout << "5. Delete from Position\n";
        cout << "6. Delete from End\n";

        cout << "7. Swap Two Values\n";
        cout << "8. Display\n";
        cout << "9. Reverse Display\n";

        cout << "10. Exit\n";


        cout << "\nEnter Choice: ";
        cin >> choice;


        switch (choice)
        {

            // ==========================================
            // INSERT START
            // ==========================================
            case 1:

                cout << "Enter Value: ";
                cin >> value;

                insertStart(head, value);

                cout << "After Insertion:\n";

                display(head);

                break;


            // ==========================================
            // INSERT POSITION
            // ==========================================
            case 2:

                cout << "Enter Value: ";
                cin >> value;

                cout << "Enter Position: ";
                cin >> pos;

                insertMiddle(head, value, pos);

                cout << "After Insertion:\n";

                display(head);

                break;


            // ==========================================
            // INSERT END
            // ==========================================
            case 3:

                cout << "Enter Value: ";
                cin >> value;

                insertEnd(head, value);

                cout << "After Insertion:\n";

                display(head);

                break;


            // ==========================================
            // DELETE START
            // ==========================================
            case 4:

                deleteStart(head);

                cout << "After Deletion:\n";

                display(head);

                break;


            // ==========================================
            // DELETE POSITION
            // ==========================================
            case 5:

                cout << "Enter Position: ";
                cin >> pos;

                deleteMiddle(head, pos);

                cout << "After Deletion:\n";

                display(head);

                break;


            // ==========================================
            // DELETE END
            // ==========================================
            case 6:

                deleteEnd(head);

                cout << "After Deletion:\n";

                display(head);

                break;


            // ==========================================
            // SWAP VALUES
            // ==========================================
            case 7:

                cout << "Enter first value: ";
                cin >> value1;

                cout << "Enter second value: ";
                cin >> value2;

                swapValues(head, value1, value2);

                cout << "After Swapping:\n";

                display(head);

                break;


            // ==========================================
            // DISPLAY
            // ==========================================
            case 8:

                display(head);

                break;


            // ==========================================
            // REVERSE DISPLAY
            // ==========================================
            case 9:

                cout << "Reverse Linked List:\n";

                reverseDisplay(head);

                break;


            // ==========================================
            // EXIT
            // ==========================================
            case 10:

                cout << "\nProgram Ended.\n";

                break;


            default:

                cout << "Invalid Choice!\n";
        }

    } while (choice != 10);


    return 0;
}
```
