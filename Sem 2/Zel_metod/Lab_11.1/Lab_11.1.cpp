#include <iostream>
using namespace std;

struct ListElem
{
    int data;
    ListElem* next;
};

ListElem* createList(int n)
{
    ListElem* start;
    ListElem* prev, * curr;
    start = new ListElem;
    cin >> start->data;
    start->next = nullptr;
    prev = start;
    for (int i = 0; i < n - 1; i++)
    {
        curr = new ListElem;
        cin >> curr->data;
        curr->next = nullptr;
        prev->next = curr;
        prev = curr;
    }
    return start;
}

void insert_element(ListElem* &start, int pos, int k, int &size)
{
    size++;
    ListElem* first = start;
    for (int i = 1; i < pos - 1; i++)
    {
        first = first->next;
    }

    ListElem* new_element = new ListElem;
    cout << "Type data: ";
    cin >> new_element->data;

    if (pos == 1)
    {
        new_element->next = first;
        start = new_element;
    }
    else
    {
        new_element->next = first->next;
        first->next = new_element;
    }
}
void insert_elements(ListElem* &list, int pos, int k, int &size)
{
    for (int i = 0; i < k; i++)
    {
        insert_element(list, pos + i, k, size);
    }
}

void delete_element(ListElem* &start, int pos, int k, int &size)
{
    size--;
    ListElem* first = start;
    ListElem* last;
    for (int i = 1; i < pos - 1; i++)
    {
        first = first->next;
    }
    if (pos == 1)
    {
        start = first->next;
        first->next = start;
    }
    else
    {
        last = first->next->next;
        first->next = last;
    }
}

void delete_elements(ListElem* &start, int pos, int k, int &size)
{
    size -= k;
    ListElem* first = start;
    ListElem* last;
    for (int i = 1; i < pos - 1; i++)
    {
        first = first->next;;
    }
    last = first;

    for (int i = 0; i < k; i++)
    {
        last = last->next;
    }

    if (pos == 1)
    {
        start = last;
    }
    else
    {
        first->next = last->next;
    }
}

void search_element(ListElem* start, int element)
{
    ListElem* curr = start;
    int pos = 0;
    while (curr->data != element && curr->next != nullptr)
    {
        curr = curr->next;
        pos++;
    }
    if (curr->data == element)
    {
        cout << "Element's founded" << endl;
    }
    else
    {
        cout << "Did not found" << endl;
    }
}

void printList(ListElem* start, int n)
{
    ListElem* curr = start;
    for (int i = 0; i < n; i++)
    {
        cout << curr->data << ' ';
        curr = curr->next;
    }
    cout << endl;
}

void deleteList(ListElem* list)
{
    delete list;
}

int main()
{
    int size, pos, k, element;
    cout << "Type size: ";
    cin >> size;
    cout << "Type elements' data: ";
    ListElem* list = createList(size);
    cout << "Your list is" << endl;
    printList(list, size);
    cout << "Type where to insert element: ";
    cin >> pos;
    insert_element(list, pos, 1, size);
    printList(list, size);
    cout << "Where and how many elements you want to insert: ";
    cin >> pos;
    cin >> k;
    insert_elements(list, pos, k, size);
    printList(list, size);
    cout << "Which element to delete: ";
    cin >> pos;
    delete_element(list, pos, 1, size);
    printList(list, size);
    cout << "From which index and how many elements you want to delete: ";
    cin >> pos;
    cin >> k;
    delete_elements(list, pos, k, size);
    printList(list, size);
    cout << "What element to find?: ";
    cin >> element;
    search_element(list, element);
    deleteList(list);
    return 0;
}
