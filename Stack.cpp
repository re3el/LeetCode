#include <iostream>
#include<malloc.h>
using namespace std;
#define MAXLEN 1000

/* using arrays: simple but not dynamic
class Stack
{
    int top;
    int arr[MAXLEN];

    public:
    Stack() {
        top = -1;
    }
    void push(int val);
    bool isEmpty();
    int pop();
};

bool Stack::isEmpty()
{
    return top < 0 ;
}

void Stack::push(int val)
{
    if(top == MAXLEN)
    {
        cout<<"Stack overflow"<<endl;
        return;
    }
    arr[++top] = val;
}

int Stack::pop()
{
    if(top < 0)
    {
        cout<<"Stack underflow ";
        return -1;
    }
    int res = arr[top--];
    return res;
}

int main()
{
    Stack stk;
    stk.push(100);
    stk.push(10);
    cout<<stk.pop()<<endl;
    cout<<stk.pop()<<endl;
    cout<<stk.pop()<<endl;
    return 0;
}
*/

/* using linkedlists: dynamic */
struct Node{
    int val;
    Node *next;
    Node(int data){
        val = data;
        next = NULL;
    }
}*node = NULL;

void push(int val)
{
    Node *newNode = new Node(val);
    newNode->next = node;
    node = newNode;
}

int pop()
{
    Node *old = node;
    int val = node->val;
    node = node->next;
    delete(old);
    return val;
}

bool isEmpty()
{
    return node==NULL;
}

int main()
{
    push(10);
    push(100);
    push(1000);
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    return 0;
}
