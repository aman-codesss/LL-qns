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
 Node* reverse( Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next= prev;
        
        prev = curr;
        curr = next;
    }
    return prev;
    
}
//Function to add two numbers represented by linked list.
Node* addTwoLists( Node* first,  Node* second)
{
    // code here
    first = reverse(first);
    second = reverse(second);
    
    int sum =0;
    int carry = 0;
    
    Node*temp=NULL;
    Node*head=NULL;
    Node*tail=NULL;
    
    while(first!=NULL || second!=NULL){
        sum = carry +(first?first->data:0)+(second?second->data:0);
        carry =(sum>=10)?1:0;
        sum = sum%10;
        temp = new Node(sum);
        
        if(head==NULL){
            head = temp;
        }
        else{
            tail->next = temp;
        }
        tail=temp;
        if(first)first = first->next;
        if(second)second= second->next;
        
    }
        if(carry>0){
            tail->next = new Node(carry);
        }
        head = reverse(head);
        return head;
}
void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
    
}


int main(){
    //creating 1st LL
Node* a=new Node(5);
Node* tail = a;
Node* head = a;
insertAtTail(tail,7);
insertAtTail(tail,3);
insertAtTail(tail,4);

//creating 2nd LL
Node* b=new Node(5);
 tail = b;
 head = b;
insertAtTail(tail,4);
insertAtTail(tail,3);
insertAtTail(tail,8);

Node* sum = addTwoLists(a,b);
printLL(sum);
}