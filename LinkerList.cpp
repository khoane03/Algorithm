#include <iostream>
using namespace std;
// khai báo node
struct node
{
    int data;           // dữ liệu trong 1 node'
    struct node *pNext; // con trỏ dùng để lk các node với nhau
};
typedef struct node NODE;

// khai báo cấu trúc của dslkd
struct list
{
    NODE *pHead; // Đầu ds
    NODE *pTail; // Cuối ds
};
typedef struct list LIST;

// khởi tạo
void khoitao(LIST &l)
{
    // cho 2 node trỏ đến null vì mới kt chưa có dl
    l.pHead = NULL;
    l.pTail = NULL;
}
// Hàm khởi tạo 1 node
NODE *KhoitaoNode(int x)
{
    NODE *p = new NODE; // cấp phát vùng nhớ cho p
    if (p == NULL)
    { // Hết bộ nhớ Ram !
        cout << "ERROR ! ";
        return p;
    }
    p->data = x;     // truyền x cho data
    p->pNext = NULL; // trỏ đến node tiếp theo và o giá trị null
    return p;        // trả về giá trị p
}

void AddHead(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p; // danh sách rỗng, cả pHead và pTail trỏ vào p
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void AddTail(LIST &l, NODE *p)
{
    if (l.pTail == NULL)
    {
        l.pHead = l.pTail = p; // danh sách rỗng, cả pHead và pTail trỏ vào p
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
// hàm thêm giữa
void addAfter_q(LIST &l, NODE *p)
{
    int n;
    cout << "Vi tri node can them phia sau : ";
    cin >> n;
    NODE *q = KhoitaoNode(n);
    if (q->data == l.pHead->data && q->pNext == NULL)
    {
        AddTail(l, p);
        return;
    }
    else
    {
        NODE *k = l.pHead;

        while (k != NULL)
        {
            if (q->data == k->data)
            {
                NODE *h = KhoitaoNode(p->data); // khởi tạo node h mới để thêm vào sau q h=p
                NODE *g = k->pNext;             // cho node g trỏ đến node sau node q
                h->pNext = g;                   // cho con rỏ tạo mối liên kết từ node p đến g <=> mối lk node p đến node sau q
                k->pNext = h;
                return; // tạo mối lk từ node q đến node p
            }
            k = k->pNext;
        }
    }
}
void addBefore_q(LIST &l, NODE *p)
{
    int n;
    cout << "Vi tri node can them phia truoc : ";
    cin >> n;
    NODE *q = KhoitaoNode(n);
    if (q->data == l.pHead->data && q == NULL)
    {
        AddHead(l, p);
    }
    else
    {
        NODE *k = l.pHead;

        while (k != NULL)
        {
            if (k->pNext->data == q->data) // con trỏ k trỏ đến data của k = dta của q
            {
                NODE *h = KhoitaoNode(p->data); // khởi tạo node h mới để thêm vào sau q h=p

                h->pNext = k->pNext; // cho con rỏ tạo mối liên kết từ node p đến q
                k->pNext = h;        // tạo mối lk từ node q đến node p
                return;
            }
            k = k->pNext;
        }
    }
}
void Delete(LIST &l)
{
    NODE *k = l.pHead;
    while (k != NULL && k->data < 0)
    {
        l.pHead = k->pNext;
        delete k;
        k = l.pHead;
    }
    NODE *p = l.pHead;
    while (p != NULL && p->pNext != NULL)
    {
        if (p->pNext->data < 0)
        {
            NODE *q = p->pNext;
            p->pNext = q->pNext;
            delete q;
        }
        else
        {
            p = p->pNext;
        }
    }
    return;
}

// hàm xuất
void Xuat(LIST l)
{
    NODE *k = l.pHead;
    while (k != NULL)
    {
        cout << k->data << " ";
        k = k->pNext;
    }
}
void Menu(LIST l)
{
    int option;
    while (1)
    {
        system("cls");
        cout << "========== Menu ==========" << endl;
        cout << "= 1.Them vao dau " << endl;
        cout << "= 2.Them vao cuoi" << endl;
        cout << "= 3.Them vao sau q" << endl;
        cout << "= 4.Them vao truoc q" << endl;
        cout << "= 5.Xuat" << endl;
        cout << "========== End ==========" << endl;

        cout << "Nhap Lua chon : ";
        cin >> option;
        if (option < 0 && option > 7)
        {
            cout << "Sai lua chon" << endl;
        }
        else if (option == 1)
        {
            int x;
            cout << "Nhap gia tri : ";
            cin >> x;
            NODE *p = KhoitaoNode(x);

            AddHead(l, p);
        }
        else if (option == 2)
        {
            int x;
            cout << "Nhap gia tri : ";
            cin >> x;
            NODE *p = KhoitaoNode(x);

            AddTail(l, p);
        }
        else if (option == 3)
        {
            int n;
            cout << "Nhap Node them phia sau : ";
            cin >> n;
            NODE *p = KhoitaoNode(n);
            addAfter_q(l, p);
        }
        else if (option == 4)
        {
            int n;
            cout << "Nhap Node them phia truoc : ";
            cin >> n;
            NODE *p = KhoitaoNode(n);
            addBefore_q(l, p);
        }
        else if (option == 5)
        {
            Xuat(l);
            cout << endl;
            system("pause");
        }
        else if(option == 6 ){
            Delete(l);
        }

        else
        {
            break;
        }
    }
}
int main()
{
    LIST l;
    khoitao(l); // luon phải gọi trước khi thực hiện các hàm còn lại

    Menu(l); // gọi hàm menu
}
