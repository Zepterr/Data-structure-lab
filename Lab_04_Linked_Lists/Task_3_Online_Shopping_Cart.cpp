#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string productID;
    Node* next;
};

int main()
{
    Node* head = NULL;
    int n;

    cout << "Enter number of products: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Node* newNode = new Node;

        cout << "Enter Product ID: ";
        cin >> newNode->productID;

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
    cout << "\nShopping Cart:\n";

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->productID;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }
    string removeID;

    cout << "\n\nRemove Product: ";
    cin >> removeID;
    if (head != NULL && head->productID == removeID)
    {
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
    }
    else
    {
        temp = head;

        while (temp != NULL &&
               temp->next != NULL &&
               temp->next->productID != removeID)
        {
            temp = temp->next;
        }

        if (temp != NULL && temp->next != NULL)
        {
            Node* deleteNode = temp->next;

            temp->next = deleteNode->next;

            delete deleteNode;
        }
    }
    cout << "\nUpdated Cart:\n";

    temp = head;

    while (temp != NULL)
    {
        cout << temp->productID;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    return 0;
}
