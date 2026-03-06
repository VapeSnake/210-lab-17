// COMSC-210 | Lab 17 | Noel Mier-Luna
// Continuing assignment
#include <iostream>
using namespace std;

// Functions to add
//  Function that adds node to head of list (Check)
//  Function that adds node to tail of list (Check)
//  Inserting a node at a specific location in the list (Check)
//  Deleting a node at a specific location in the list (Check)
//  Deleting the entire list (Check)
//  Leave output function as is.

const int SIZE = 7;

struct Node
{
    float value;
    Node *next;
};

void output(Node *, float);         // Doesn't need reference since it's only outputting list, not modifying it.
void addToHead(Node *&, float);     // Passes head by reference so that we can modify it in the function.
void addToTail(Node *&, float);     // Float parameter is the value to be added to the new node.
void insertAt(Node *&, float, int); // Int paramter will be used for position to insert/delete.
void deleteAt(Node *&, float, int);
void deleteList(Node *&);

int main()
{
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    /*
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;

        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    } 
    output(head);

    // deleting a node
    Node *current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry - 1); i++)
        if (i == 0)
            current = current->next;
        else
        {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current)
    { // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current)
    {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else
        {
            current = current->next;
            prev = prev->next;
        }
    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);

    // deleting the linked list
    current = head;
    while (current)
    {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);
*/
    addToHead(head, 10.5);
    addToTail(head, 20.5);
    insertAt(head, 15.5, 2); // Inserts 15.5 at position 2 (between 10.5 and 20.5)

    return 0;
}

void output(Node *hd)
{
    if (!hd)
    {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current)
    {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void addToHead(Node *&head, float value)
{
    if (!head)
    { // if this is the first node, it's the new head
        head = new Node;
        head->next = nullptr;
        head->value = value;
    }
    else
    { // its a second or subsequent node; place at the head
        Node *newVal = new Node;
        newVal->next = head;
        newVal->value = value;
        head = newVal;
    }
    output(head); // outputs the list after adding the new node to verify that it was added correctly.
}

void addToTail(Node *&head, float value)
{
    if (!head)
    { // Even if this function is used, checks for empty list.
        head = new Node;
        head->next = nullptr;
        head->value = value;
    }
    else
    { // its a second or subsequent node; place at the tail
        Node *current = head;
        while (current->next)
        { // traverse to the end of the list
            current = current->next;
        }
        Node *newVal = new Node;
        newVal->next = nullptr; // new tail node points to null
        newVal->value = value;
        current->next = newVal; // old tail node points to new tail node
    }
    output(head); // outputs the list after adding the new node to verify that it was added correctly.
}

void insertAt(Node *&head, float value, int pos)
{ // Instead of using cin, we can pass the position as a parameter to the function.
    cout << "List before inserting " << value << " at position " << pos << ":\n";
    output(head);
    if (pos == 1)
    {
        addToHead(head, value); // if the position to insert is 1, we can just call addToHead function
    }
    else
    {
        Node *current = head; // traverse to the position before where we want to insert
        for (int i = 1; i < (pos - 1) && current; i++)
        { // checks for current to be valid to avoid out of bounds.
            current = current->next;
        }
        if (current)
        { // if current is valid, we can insert the new node
            Node *newNode = new Node;
            newNode->value = value;
            newNode->next = current->next; // new node points to the next node in the list
            current->next = newNode;       // current node points to the new node
        }
    }
    cout << "List after inserting " << value << " at position " << pos << ":\n";
    output(head); // outputs the list after inserting the new node to verify that it was inserted correctly.
}

void deleteAt(Node *&head, float value, int pos)
{ // Similar to insertAt, except for deleting node
    cout << "List before deleting node at position " << pos << ":\n";
    output(head);
    if (pos == 1)
    {
        deleteList(head); // if the position to delete is 1, we can just call deleteList function to delete the entire list
    }
    else
    {
        Node *current = head; // Moves to current node to the position before the node we want to delete
        Node *prev = head; // Keeps track of the previous node to reroute pointers after deleting the current node
        for (int i = 1; i < (pos - 1) && current; i++)
        { // checks for current to be valid to avoid out of bounds.
            current = current->next;
            prev = prev->next;
        }
        if (current && current->next) // checks for current and current->next to be valid to avoid out of bounds.
        {
            Node *temp = current->next; // temp node to hold the node we want to delete
            current->next = temp->next; // current node points to the node after the node we want to delete
            delete temp;                // deletes the node we want to delete
            temp = nullptr;             // sets temp to null after deleting the node
        }
    }
    cout << "List after deleting node at position " << pos << ":\n";
    output(head); // outputs the list after deleting the node to verify that it was deleted correctly
}

void deleteList(Node *&head)
{
    cout << "List before deleting the entire list:\n";
    output(head);
    Node *current = head;
    while (current)
    {
        head = current->next; // moves head to the next node in the list
        delete current;       // deletes the current node
        current = head;      // moves current to the new head of the list
    }
    head = nullptr; // sets head to null after deleting the entire list
    cout << "List after deleting the entire list:\n";
    output(head); // outputs the list after deleting the entire list to verify that it was deleted correctly.
}