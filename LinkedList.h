#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <iostream>

class Node{
    private:
        int contents;
        Node* next;
    public:
        Node();
        friend class LinkedList;
        friend std::ostream& operator << (std::ostream &out, const Node &o){
            out<<o.contents;
            return out;
        };
        int getContents(){
            return contents;
        }
        Node* getNext(){
            return next;
        }
        ~Node(){};

};
Node::Node(){
    this->contents=0;
    this->next = nullptr;
}

class LinkedList{
    private:
        Node *head;
        int size;
    public:
        LinkedList();
        void Insert(int);
        void Remove(int);
        ~LinkedList();
        void print();
        friend std::ostream& operator << (std::ostream &out, const LinkedList &o);
};

LinkedList::LinkedList(){
    head = nullptr;
    size = 1;
}
void LinkedList::Insert(int content){
    Node* n = new Node();
    n->contents = content;
    n->next = nullptr;
    size++;
    Node* temp = head;
    Node* temp2 = nullptr;
    while((temp != nullptr)&&(temp->contents < content)){
        temp2 = temp;
        temp = temp->next;
    }
    if(temp == head){
        head = n;
    }else{
        temp2->next = n;
    }
    n->next = temp;
}

void LinkedList::print(){
    Node* temp = head;
        for(int i=0;i<size-1;i++){
            std::cout<< temp->contents<<" -> ";
            temp = temp->next;
        }    
}


std::ostream& operator << (std::ostream &out, const LinkedList &o){
    Node* temp = o.head;
    out<<temp->getContents()<<" -> ";
    for(int i=0;i<o.size-2;i++){
        temp=temp->getNext();
        out<<temp->getContents()<<" -> ";
    }
    return out;
}

void LinkedList::Remove(int pos){
    Node* temp = head;
    Node* temp2= temp->next;
    if (pos < 1 || pos > size) {
        std::cout << "Fuera de rango " << "\n";
    } else if (pos == 1) {
        head = temp->next;
    } else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                Node* aux_node = temp2;
                temp->next = temp2->next;
                delete aux_node;
                size--;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
    }
}

LinkedList::~LinkedList(){
}



#endif