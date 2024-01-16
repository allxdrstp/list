#include <iostream>
#include <list>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

class List
{
public:
    List();
    List(int data);
    bool Addel(int data);
    void Delel(int data);
    bool Findel(int data);
    bool Insert(int data, int pos);
    void Print();
    void Reverseprint();
    void sort();
    Node* first;
    Node* last;
};
List::List() {
    first = nullptr;
    last = nullptr;
}
bool List::Addel(int data) {
    Node* nd = new Node{ data, nullptr };

    if (last == nullptr)
    {
        first = nd;
        last = nd;
    }
    else {
        nd->prev = last;
        last->next = nd;
        last = nd;
    }
    return true;
}

bool List::Findel(int data)
{
    Node* lm = first;

    while (lm != NULL)
    {
        if (lm->data == data)
            return 1;

        lm = lm->next;
    }

    return 0;
}
void List::Delel(int data) {
    Node* el = first;
    while (el != nullptr) {
        if (el->data == data) {
            if (el->prev != nullptr) {
                el->prev->next = el->next;
            }
            if (el->next != nullptr) {
                el->next->prev = el->prev;
            }
            if (el == first) {
                el->next = first;
            }
            if (el == last) {
                el->prev = last;
            }
            delete el;
            break;
        }
        el = el->next;
    }
}
void List::Print() {
    Node* pms = first;

    while (pms != NULL)
    {
        cout << pms->data << " ";
        pms = pms->next;
    }
}
void List::Reverseprint() {
    Node* pms = last;
    while (pms != NULL) {
        cout << pms->data << " ";
        pms = pms->prev;
    }
}
bool List::Insert(int data, int pos) {
    Node* mm = first;
    Node* pp = new Node{ data, nullptr, nullptr };

    if (pos == 0) {
        pp->next = first;
        first = pp;
        return true;
    }
    int i = 0;
    while (mm != nullptr) {
        if (i == pos - 1) {

            pp->prev = mm;
            pp->next = mm->next;

            if (mm->next != nullptr) {
                mm->next->prev = pp;
            }

            mm->next = pp;
            break;
        }
        mm = mm->next;
        i++;
    }
}
void List::sort()
{
    Node* k = first;
    while (k->next) {
        if (k->data > k->next->data) {
            swap(k->data, k->next->data);
            k = k->next;
            sort();
        }
        else {
            k = k->next;
        }
    }
}
int main()
{
    List l1;
    l1.Addel(111);
    l1.Addel(654);
    l1.Addel(458);
    l1.Addel(666);
    l1.Addel(777);
    l1.Addel(333);
    l1.Print();
    cout << endl;
    l1.Reverseprint();
    cout << endl;
    l1.Delel(458);
    l1.Print();
    cout << endl;
    cout << l1.Findel(11);
    cout << endl;
    l1.Insert(36, 1);
    l1.Print();
    l1.sort();
    cout << endl;
    l1.Print();
}