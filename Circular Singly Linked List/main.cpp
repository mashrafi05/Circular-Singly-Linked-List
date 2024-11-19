#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

struct CLLS {
    Node *head = NULL;

    void InsertAtHead(int d);
    void InsertAtEnd(int d);
    void InsertAtAnyposition(int d, int position);
    void DeleteHead();
    void DeleteTail();
    void DeleteAnyPosition(int position);
    int MaximumValue();
    int MinimumValue();
    void SearchItem(int value);

    void print();
};

void CLLS::print() {
    if (head == NULL) {
        cout << "List is empty" << endl;
    } else {
        Node *h = head;
        do {
            cout << h->data << " ";
            h = h->next;
        } while (h != head);
        cout << endl;
    }
}

void CLLS::InsertAtHead(int d) {
    Node *n = new Node(d);

    if (head == NULL) {
        head = n;
        n->next = head;
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        n->next = head;
        temp->next = n;
        head = n;
    }
}

void CLLS::InsertAtEnd(int d) {
    Node *n = new Node(d);
    if (head == NULL) {
        head = n;
        n->next = head;
    } else {
        Node *h = head;
        while (h->next != head) {
            h = h->next;
        }
        h->next = n;
        n->next = head;
    }
}

void CLLS::InsertAtAnyposition(int d, int position) {
    Node *n = new Node(d);
    if (position == 1) {
        InsertAtHead(d);
    } else {
        Node *h = head;
        for (int i = 1; i < position - 1 && h->next != head; i++) {
            h = h->next;
        }
        n->next = h->next;
        h->next = n;
    }
}

void CLLS::DeleteHead() {
    if (head == NULL) {
        cout << "The List Is Empty" << endl;
    } else if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node *temp = head;
        Node *last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        delete temp;
    }
}

void CLLS::DeleteTail() {
    if (head == NULL) {
        cout << "The List is empty" << endl;
    } else if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node *h = head;
        while (h->next->next != head) {
            h = h->next;
        }
        Node *g = h->next;
        h->next = head;
        delete g;
    }
}

void CLLS::DeleteAnyPosition(int position) {
    if (head == NULL) {
        cout << "List is empty" << endl;
    } else if (position == 1) {
        DeleteHead();
    } else {
        Node *h = head;
        for (int i = 1; i < position - 1 && h->next != head; i++) {
            h = h->next;
        }
        Node *g = h->next;
        h->next = g->next;
        delete g;
    }
}

int CLLS::MaximumValue() {
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return -1;
    }

    Node *h = head;
    int maxvalue = head->data;
    do {
        if (h->data > maxvalue) {
            maxvalue = h->data;
        }
        h = h->next;
    } while (h != head);
    cout << "Max Value: " << maxvalue << endl;
    return maxvalue;
}

int CLLS::MinimumValue() {
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return -1;
    }

    Node *h = head;
    int minvalue = head->data;
    do {
        if (h->data < minvalue) {
            minvalue = h->data;
        }
        h = h->next;
    } while (h != head);
    cout << "Min Value: " << minvalue << endl;
    return minvalue;
}

void CLLS::SearchItem(int value) {
    Node *h = head;
    int position = 1;
    do {
        if (h->data == value) {
            cout << "Value " << value << " found at position " << position << endl;
            return;
        }
        h = h->next;
        position++;
    } while (h != head);
    cout << "Value " << value << " not found in the list" << endl;
}

int main() {
    CLLS lists;
    lists.InsertAtHead(10);
    lists.InsertAtHead(14);
    lists.InsertAtHead(1);
    lists.InsertAtHead(1);
    lists.InsertAtEnd(599);
    lists.InsertAtAnyposition(333, 2);
    lists.DeleteAnyPosition(3);
    lists.MaximumValue();
    lists.MinimumValue();
    lists.SearchItem(599);

    lists.print();
}
