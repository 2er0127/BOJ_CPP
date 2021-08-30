#include <iostream>
#include <algorithm>

using namespace std;

struct singly_ll_node {
    int data;
    singly_ll_node* next;
};

class singly_ll {
public:
    using node=singly_ll_node;
    using node_ptr=node*;
    
private:
    node_ptr head;
    
public:
    void push_front(int val) {
        auto new_node=new node {val, NULL};
        if(head!=NULL) {
            new_node->next=head;
            head=new_node;
        }
    }
    
    void pop_front() {
        auto first=head;
        if(head) {
            head=head->next;
            delete first;
        }
    }
};

int main() {
    
}
