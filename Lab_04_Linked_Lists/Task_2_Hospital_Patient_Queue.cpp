#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string patientID;
    Node* next;
};

int main()
{
    Node* head = NULL;
    int n;

    cout << "Enter number of patients: ";
    cin >> n;

    // Add patients
    for (int i = 0; i < n; i++)
    {
        Node* newNode = new Node;

        cout << "Enter Patient ID: ";
        cin >> newNode->patientID;

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
    cout << "\nWaiting Patients:\n";

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->patientID;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    // Remove first patient
    if (head != NULL)
    {
        Node* deleteNode = head;

        cout << "\n\nPatient " << head->patientID
             << " is being served.";

        head = head->next;

        delete deleteNode;
    }
    cout << "\n\nUpdated Queue:\n";

    temp = head;

    while (temp != NULL)
    {
        cout << temp->patientID;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    return 0;
}
