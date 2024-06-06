#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }

};
void printLL(Node* &head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"null"<<endl;
}
Node* reverse(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev=curr;
        curr=next;
        
    }
    return(prev);
}
      void insertAtTail(Node* &tail, int d){
        Node* temp = new Node(d);
        tail->next = temp;
        tail = temp;
        
    }
int main(){
Node* n1 = new Node(10);
Node* tail = n1;
Node* head = n1;
insertAtTail(tail,20);
insertAtTail(tail,30);
insertAtTail(tail,40);
printLL(head);
head = reverse(head);
printLL(head);
}