#include <iostream>
using namespace std;
typedef struct TagList
{
    int msv;
    char hoTen[30];
    float diem;
} sinhvien;

typedef struct tagNode
{
    sinhvien data;
    tagNode *Next;
} Node;

typedef struct List
{
    Node *head;
    Node *tail;
} DSdon;

void CreatList(DSdon &l)
{
    l.head = NULL;
    l.tail = NULL;
}

Node *CreatNode(sinhvien x)
{
    Node *p = new Node;
    p->data = x;
    p->Next = NULL;
    return p;
}

void themSv(DSdon &a, sinhvien sv)
{    Node *p = CreatNode(sv);
    
    if (a.head == NULL)
    {   a.head = p;
        a.tail = p;
    }else{
        a.tail->Next=p;
        a.tail=p;
    }
   
}
void dk(){
    
}
void prinf(DSdon &a)
{
    for (Node *k = a.head; k != NULL; k = k->Next)
    {
        cout << k->data.msv << " " << k->data.diem << endl;
    }
}

int main(){
    DSdon l;
    CreatList(l);
    sinhvien sv;
    for(int i=0;i<3;i++){
        cout<<"Nhap MSV: ";
        cin>>sv.msv;
        cout<<"diem";
        cin>>sv.diem;
        themSv(l,sv);
    }
    prinf(l);
}
