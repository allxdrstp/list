#include <iostream>
#include <list>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

class List
{
public:
    List();
    List(int data);
    bool Addel(int data);
    int Delel(int data);
    bool Findel(int data);
    bool Insert(int data, int pos);
    void Print();
    bool Search(int data);
    void Remove(int data);
    void insert(int data, int pos);
    Node* first;
    Node* last;
};

List::List()
{
    first = nullptr;
    last = nullptr;
}

List::List(int data)
{
    Node* nd = new Node{ data };

    first = nd;
    last = nd;

    last->next = nullptr;
}

bool List::Addel(int data)
{
    Node* nd = new Node{ data, nullptr };

    if (last == nullptr)
    {
        first = nd;
        last = nd;

        return true;
    }

    last->next = nd;
    last = nd;
    return true;
}

void List::Print()
{
    Node* lm = first;
    int c = 0;
    while (lm)
    {
        c = lm->data;
        cout << c << " ";

        lm = lm->next;
    }
}

bool List::Search(int data)
{
    Node* lm = first;

    int i = 0;

    while (lm)
    {
        if (lm->data == data)
        {
            i = 1;
        }
        lm = lm->next;
    }
    if (i == 0)
    {
        return false;
    }
    else return true;
}

void List::Remove(int data)
{
    Node* Obj = first;
    Node* Elem = first->next;
    if (Obj->data == data) {
        first = Elem;
        delete Obj;
        return;
    }
    while (Elem && Elem->data != data) {
        Elem = Elem->next;
        Obj = Obj->next;
    }
    if (Elem) {
        Obj->next = Elem->next;
        delete Elem;
    }
}

bool List::Insert(int data, int pos) {
    Node* nd1 = first;
    Node* nd2 = new Node{ data, nullptr };

    if (pos == 0) {
        nd2->next = first;
        first = nd2;
        return true;
    }

    int i = 0;
    while (nd1 && i < pos - 1) {
        nd1 = nd1->next;
        i++;
    }

    if (nd1) {
        nd2->next = nd1->next;
        nd1->next = nd2;
        if (nd1 == last) {
            last = nd2;
        }
        return true;
    }

    delete nd2;
    return false;
}

int main()
{
    List NN;

    NN.Addel(5);
    NN.Addel(6);
    NN.Addel(7);
    NN.Addel(10);
    NN.Addel(6);
    NN.Addel(7);

    NN.Print();

    cout << "\n";

    int a = NN.Search(111);

    NN.Remove(10);

    NN.Insert(16, 4);

    NN.Print();

    cout << "\n";
    cout << a;
    cout << "\n";

    return 0;
}