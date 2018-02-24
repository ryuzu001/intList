#include "IntList.h"

IntList::IntList() {
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);
    dummyHead->next = dummyTail;
    dummyHead->prev = 0;
    dummyTail->prev = dummyHead;
    dummyTail->next = 0;
}
IntList::~IntList(){
    IntNode* temp = dummyHead->next;
    while(!empty()){
        pop_back();
    }
}

void IntList::push_front(int val) {
    IntNode * temp = new IntNode(val);
    temp->next = dummyHead->next;
    temp->prev = dummyHead;
    dummyHead->next = temp;
    temp->next->prev = temp;
}

void IntList::pop_front() {
    if(empty()){
        return;
    }
    else{
        IntNode* temp = dummyHead->next->next;
        delete dummyHead->next;
        dummyHead->next = temp;
        temp->prev = dummyHead;
    }
}

void IntList::push_back(int val){
    IntNode* temp = new IntNode(val);
    // if(empty()){
    //     dummyHead->next = temp;
    //     temp->prev = dummyHead;
    //     temp->next = dummyTail;
    //     dummyTail->prev = temp;
    // }
    temp->next = dummyTail;
    temp->prev = dummyTail->prev;
    dummyTail->prev = temp;
    temp->prev->next = temp;
    // temp->prev = dummyTail->prev->prev;
}

bool IntList::empty() const{
    if(dummyHead->next == dummyTail){
        return true;
    }
    return false;
}

void IntList::pop_back() {
    if(!empty()) {
        IntNode * temp = dummyTail->prev;
        dummyTail->prev = temp->prev;
        temp->prev->next = dummyTail;
        delete temp;
    }
}
void IntList::printReverse() const {
    if(!empty()){
        for(IntNode* curr = dummyTail->prev; curr != dummyHead; curr = curr->prev){
            cout << curr->data;
            if(curr->prev != dummyHead){
                cout << ' ';
            }
        }
    }
}



ostream & operator<<(ostream &out, const IntList &rhs) {
    if(!rhs.empty()) {
        for(IntNode * curr = rhs.dummyHead->next; curr != rhs.dummyTail; curr = curr->next) {
            if(curr->next == rhs.dummyTail) {
                out << curr->data;
            }
            else {
                out << curr->data << ' ';
            }
        }
    }
    
    return out;
}