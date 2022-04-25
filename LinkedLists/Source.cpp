// Refrencing these WebPages for Structured Code : 
//
// https://www.geeksforgeeks.org/insert-value-sorted-way-sorted-doubly-linked-list/
// https://www.geeksforgeeks.org/bubble-sort/
// https://www.geeksforgeeks.org/insert-value-sorted-way-sorted-doubly-linked-list/ 

// Refrences ^^


#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;
using namespace chrono;

// A doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head;
struct Node* tail;
void init()
{
    head = NULL;
    tail = NULL;
}

//inserts node at the front of the list
void insert_front(unsigned new_data)
{
    //allocate memory for New node
    struct Node* newNode = new Node;
    
    if (head == NULL) {
        head = newNode;
        newNode->prev = NULL;
        newNode->data = new_data;
        newNode->next = NULL;
        tail = newNode;
    }
    else 
    {
        newNode->next = head;
        newNode->data = new_data;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
    }
}


// This function prints contents of linked list starting from the given node
void displayList(struct Node* node) {
    struct Node* last;

    while (node != NULL) {
        cout << node-> data << "<==>";
        last = node;
        node = node->next;
    }
    if (node == NULL)
        cout << "NULL";
}

// this function will search the elements 
struct Node* searchItem(unsigned new_data) 
{
    struct Node* temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp -> data == new_data)
        {
            return temp;
            break;
        }
        temp = temp->next;
    }
    return NULL;
}

// Bubble sort the Linked List
void bubbleSort(struct Node* start) {
    int swapped, i;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    // Checking for empty list
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1->data, ptr1->next->data);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

//sort's what's inserted into Linked List
void sorted_Insertion(struct Node** head_point, struct Node* newNode)
{
    struct Node* base;

    // if list is empty 
    if (*head_point == NULL)
        *head_point = newNode;

    // Checks to see if it needs to be inserted in the start of the list
    else if ((*head_point)->data >= newNode->data) {
        newNode->next = *head_point;
        newNode->next->prev = newNode;
        *head_point = newNode;
    }

    else {
        base = *head_point;

        //Locates the node the new node needs to be inserted before
        while (base->next != NULL &&
            base->next->data < newNode->data)
            base = base->next;

        newNode->next = base->next;

        // Checks if the node is inserted at the end
        if (base->next != NULL)
            newNode->next->prev = newNode;

        base->next = newNode;
        newNode->prev = base;
    }
}

void insert_Sorting(struct Node** head_point)
{
    // Initialize a sorted doubly linked list 
    struct Node* sorted = NULL;

    // Sorts the list 
    struct Node* base = *head_point;
    while (base != NULL) {

        // Stores the Next Number 
        struct Node* next = base->next;

        // Creating our base
        base->prev = base->next = NULL;

        // inserts the sorted iteration 
        sorted_Insertion(&sorted, base);

        // Update base 
        base = next;
    }

    // Update head_point to point to sorted doubly linked list 
    *head_point = sorted;
}

// This will delete the selected Item
void deleteItem(unsigned new_data)
{
    struct Node* temp;
    temp = head;
    if (head == tail)
    {
        if (head-> data != new_data)
        {
            cout << "could not delete" << endl;
            return;
        }
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    if (head-> data == new_data)
    {
        head = head->next;
        head->prev = NULL;
        delete temp;
        return;
    }
    else if (tail-> data == new_data)
    {
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        return;
    }
    while (temp-> data != new_data)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            cout << "element not found" << endl;
            return;
        }
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
}

int main() {

    init();

    // Sets up our initial list of numbers
    for (int i = 0; i < 100; i++)
    {
        int x = rand() % 100;
        insert_front(x);
    }


    int Cancel = 0;
    int input;
    unsigned Inputs;

    
    while (1)
    { 
        cout << "What would you like to do?" << endl;

        cout << "[1] . Input new" << endl;
        cout << "[2] . Show List" << endl;
        cout << "[3] . Bubble Sort List" << endl;
        cout << "[4] . Inseration Sort List" << endl;
        cout << "[5] . Search For Item" << endl;
        cout << "[6] . Delete Item" << endl;
        cout << "[7] . End Program" << endl;

        cin >> input;

        if (input == 1) {

            cout << "Please Input a Number!" << endl;

            cin >> Inputs;

            insert_front(Inputs);
        

        }
        else if (input == 2) {

            cout << "This is our Doubly Linked List! :D " << endl;

            displayList(head);
            cout << " " << endl;
            

        }
        else if (input == 3)
        {
            cout << "Starting Bubble Sort and Clock! :D" << endl;
            high_resolution_clock::time_point t1 = high_resolution_clock::now(); // starting time
            bubbleSort(head);
            high_resolution_clock::time_point t2 = high_resolution_clock::now(); // ending timer
            duration<double> time_span = duration_cast<duration<double>>(t2 - t1); // seeing how much time has passed

            
            displayList(head);//Printing list after sorting
            cout << " " << endl;
            cout << " It took " << time_span.count() << " Seconds to run the sort!" << endl;
        }
        else if (input == 4)
        {
            cout << "Starting Insertion Sort and Clock! :D" << endl;
            high_resolution_clock::time_point t1 = high_resolution_clock::now(); // starting time
            insert_Sorting(&head);
            high_resolution_clock::time_point t2 = high_resolution_clock::now(); // ending timer
            duration<double> time_span = duration_cast<duration<double>>(t2 - t1); // seeing how much time has passed


            displayList(head);//Printing list after sorting
            cout << " " << endl;
            cout << " It took " << time_span.count() << " Seconds to run the sort!" << endl;
        }
        else if (input == 5) {

            int item;
            cout << "Input Desired Search" << endl;

            cin >> item;

            struct Node* ans = searchItem(item);
            if (ans != NULL) cout << "FOUND : " << ans->data << endl;
            else cout << " DATA NOT FOUND " << endl;


        }
        else if (input == 6) {

            int new_data;

            cout << "What item would you like Deleted?" << endl;

            cin >> new_data;


            deleteItem(new_data);
            displayList(head);


        }
        else if (input == 7) {

            cout << " Ending Program, Have a great day! :D" << endl;

            break;
            
        }

    
    }
    return 0;
}