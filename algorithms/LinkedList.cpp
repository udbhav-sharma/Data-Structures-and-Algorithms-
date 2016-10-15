//
// Created by udbhav on 24/9/16.
//

#include <iostream>

using namespace std;

class Node{
public:
    int key;
    Node* next = NULL;

    Node(int key){
        this->key = key;
    }

    Node(int key, Node* next){
        this->key = key;
        this->next = next;
    }

    bool isEqual(Node* node){
        return this->key==node->key;
    }
};

class LinkedList{

private:
    Node* head = NULL;
    Node* tail = NULL;

public:
    Node* getHead(){
        return head;
    }

    Node* getTail(){
        return tail;
    }

    void insert(int key){
        Node* newNode = new Node(key);
        if(head==NULL)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
    }

    void insertNth(int key, int position) {
        if(head==NULL)
            head = new Node(key);
        else if(position==0)
            head = new Node(key,head);
        else {
            Node *link = head;
            for (int i = 0; i < position - 1; i++)
                link = link->next;
            link->next = new Node(key, link->next);
        }
    }

    void deleteNode(int position){
        Node* link = head;
        Node* prev = NULL;

        if(position==0)
            head = head->next;
        else{
            for(int i=0;i<position;i++){
                prev = link;
                link = link->next;
            }
            prev->next = link->next;
            delete(link);
        }
    }

    int getNode(int position){
        Node* link = head;
        for(int i=0;i<position;i++)
            link=link->next;
        return link!=NULL? link->key : -1;
    }

    int getNodeFromBack(int positionFromTail){
        int index = 0;
        Node* link = head;
        Node* result = head;

        while(link!=NULL){
            link=link->next;
            if(index++>positionFromTail){
                result=result->next;
            }
        }
        return result!=NULL? result->key : -1;
    }

    void display(){
        Node* link = this->head;
        while(link!=NULL){
            cout<<link->key<<" ";
            link=link->next;
        }
        cout<<endl;
    }

    void displayReverse(Node* link){
        if(link!=NULL) {
            displayReverse(link->next);
            cout<<link->key<<" ";
        }
    }
};

int main() {
    int N,key,position;
    LinkedList linkedList;

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>key>>position;
        linkedList.insertNth(key,position);
    }

    linkedList.display();
    linkedList.displayReverse(linkedList.getHead());
    return 0;
}
