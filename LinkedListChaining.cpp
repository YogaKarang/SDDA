#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

const int SIZE = 10;
Node* table[SIZE];

int hashFunction(string nama) {
    int sum = 0;

    for (char c : nama) {
        sum += int(c);
    }

    return sum % SIZE;
}

void insert(string nama) {
    int index = hashFunction(nama);

    Node* newNode = new Node;
    newNode->nama = nama;
    newNode->next = NULL;

    if (table[index] == NULL) {
        table[index] = newNode;
    } 
    else {
        Node* temp = table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display() {
    cout << "\n===== HASIL HASH TABLE (Linked List Chaining) =====\n\n";

    for (int i = 0; i < SIZE; i++) {
        cout << setw(2) << i << " : ";

        Node* temp = table[i];

        if (temp == NULL) {
            cout << "-";
        } else {
            while (temp != NULL) {
                cout << temp->nama;
                if (temp->next != NULL) {
                    cout << " -> ";
                }
                temp = temp->next;
            }
        }

        cout << endl;
    }

    cout << "\n==================================================\n";
}

int main() {

    for (int i = 0; i < SIZE; i++) {
        table[i] = NULL;
    }

    string data[] = {
        "Ando", "Beni", "Citra", "Doni", "Eka",
        "Eko", "Gina", "Intan", "Joko", "Kevin"
    };

    int n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++) {
        insert(data[i]);
    }

    display();

    return 0;
}