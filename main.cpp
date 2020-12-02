#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        next=nullptr;
    }
};
void print(Node *head){
    while(head!=nullptr){
        cout<< head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
Node *deleteNodeRecursively(Node *head,int pos){
    Node *temp = head;
    if(pos==-1){
        Node *a  = temp;
        temp=temp->next;
        delete a;
        return temp;
    }
    if(pos==0){
        Node *a = temp->next;
        Node *b = a->next;
        temp->next = b;
        delete a;
        return temp;
    }
    temp = temp->next;
    pos--;
    temp=deleteNodeRecursively(temp,pos);
    temp = head;
    return temp;
}
int main(){
    int data;
    cin>>data;
    Node *head = nullptr;
    Node *tail = nullptr;

    while(data!=-1){
        Node *newNode = new Node(data);
        if(head==nullptr){
            head=newNode;
            tail=newNode;
        }else {
            tail->next=newNode;
            tail=tail->next;
        }
        cin>>data;
    }
    print(head);
    cout<<"Enter the position ";
    int i;
    cin>>i;
    head=deleteNodeRecursively(head,i-1);
    print(head);
    return 0;
}
