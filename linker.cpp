#include <iostream>
using namespace std;

// Khai báo kiểu dữ liệu node
typedef struct TagNode
{
    int data;
    TagNode *Next;
} Node;

// Kiểu dữ liệu con trỏ quản lí đầu cuối
typedef struct TagNodel
{
    Node *Head;
    Node *Tail;
} NodeList;
// Khởi tạo một danh sách rỗng
void CreatList(NodeList &l)
{
    l.Head = NULL;
    l.Tail = NULL;
}
// Khởi tạo Node
Node *CreatNode(int x)
{
    Node *p = new Node;
    if (p == NULL)
    {
        exit(1);
    }
    else
    {
        p->data = x;
        p->Next = NULL;
    }
    return p;
}

// Hàm add Node
void AddHead(NodeList &l, Node *p)
{
    if (l.Head == NULL)
    {
        l.Head = l.Tail = p;
    }
    else
    {
        p->Next = l.Head;
        l.Head = p;
    }
}
void AddTail(NodeList &l, Node *p)
{
    if (l.Head == NULL)
    {
        l.Head = l.Tail = p;
    }
    else
    {
        l.Tail->Next = p;
        l.Tail = p;
    }
}
void AddAfter(NodeList &l, Node *p)
{
    int x;
    cout << "Enter Location : ";
    cin >> x;
    cout << endl;
    Node *q = CreatNode(x);

    for (Node *q_new = l.Head; q_new != NULL; q_new = q_new->Next)
    {
        if (q_new == l.Head && q_new->Next == NULL)
        {
            AddTail(l, p);
        }
        if (q->data == q_new->data)
        {   Node *t = CreatNode();
            p->Next = q_new->Next;
            q_new->Next = p;
        }
    }
}
void AddBefor(NodeList &l, Node *p)
{
    int x;
    cout << "Enter Location : ";
    cin >> x;
    cout << endl;
    Node *q = CreatNode(x);

    for (Node *q_new = l.Head; q_new != NULL; q_new = q_new->Next)
    {
        if (q_new->data == l.Head->data && q_new == NULL)
        {
            AddHead(l, p);
            return;
        }
        if (q_new->Next->data == q->data)
        {
            p->Next = q_new->Next;
            q_new->Next = p;
            return;
        }
    }
}

void Print(NodeList l)
{

    for (Node *k = l.Head; k != NULL; k = k->Next)
    {
        cout << k->data << " ";
    }
    cout << endl;
}

int main()
{
    int n, x;
    NodeList l;
    CreatList(l);
    cout << "Enter the number of value : ";
    cin >> n;
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter the value " << i << " : ";
        cin >> x;
        Node *p = CreatNode(x);
        AddTail(l, p);
    }
    Print(l);

    cout << "Value";
    int c;
    cin >> c;
    Node *p = CreatNode(c);
     AddAfter(l, p);
     Print(l);
    
    system("pause");
}