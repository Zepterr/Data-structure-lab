#include <iostream>
using namespace std;

struct Node {
    int roll;
    Node* next;
};

class StudentList {
    Node* head;

public:
    StudentList() {
        head = NULL;
    }

    // add student at the end
    void addStudent(int r) {
        Node* newNode = new Node;
        newNode->roll = r;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // show all students
    void display() {
        if (head == NULL) {
            cout << "No students registered." << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->roll;
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    // search by roll number
    bool search(int r) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->roll == r) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    ~StudentList() {
        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    StudentList list;

    list.addStudent(101);
    list.addStudent(105);
    list.addStudent(108);
    list.addStudent(112);

    cout << "Registered Students:" << endl;
    list.display();

    int key;
    cout << "\nEnter Roll Number to Search: ";
    cin >> key;

    if (list.search(key)) {
        cout << "Student Found" << endl;
    } else {
        cout << "Student Not Found" << endl;
    }

    return 0;
}
