#include<iostream>
using namespace std;

class Node{
  public:
     int data;
     Node *next;
  };

void InsertFront(Node **head_ref,int key){
  Node *new_node=new Node();
  new_node->data=key;
  if(*head_ref ==NULL){
      *head_ref=new_node;
      new_node->next=*head_ref;}
  else{
      new_node->next=*head_ref;
      Node *ptr=*head_ref;
      while(ptr->next!=*head_ref)
        ptr=ptr->next;
      *head_ref=new_node;
      ptr->next=*head_ref;
      }
  }

void print(Node *head_ref){
    if(head_ref ==NULL)
        cout<<"list is empty";
    else{
        Node *curr_ptr=head_ref;
        do  {
            cout<<" "<<curr_ptr->data;
            curr_ptr=curr_ptr->next;
            }
        while(curr_ptr!=head_ref);
        }
    }

int main(){
  Node *head=NULL;
  InsertFront(&head,3);
  InsertFront(&head,4);
  InsertFront(&head,5);
  print(head);
  return 0;
  }
