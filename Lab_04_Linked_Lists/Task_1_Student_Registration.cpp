#include <iostream>
using namespace std;

struct Node
{
    int rollNo;
    Node* next;
};

int main()
{
    Node* head = NULL;
    int n;

    cout << "Enter number of students: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Node* newNode = new Node;

        cout << "Enter Roll Number: ";
        cin >> newNode->rollNo;

        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
    cout << "\nRegistered Students:\n";

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->rollNo;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }
    int searchRoll;
    cout << "\n\nEnter Roll Number to Search: ";
    cin >> searchRoll;
    temp = head;
    bool found = false;
    while (temp != NULL)
    {
        if (temp->rollNo == searchRoll)
        {
            found = true;
            break;
        }

        temp = temp->next;
    }

    if (found)
        cout << "Student Found";
    else
        cout << "Student Not Found";

    return 0;
}
