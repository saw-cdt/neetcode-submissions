class MyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node (int value) {
            data = value;
            prev = nullptr;
            next = nullptr;
        }
    };

public:
    // creamos los dummies
    Node* head;
    Node* tail;

    MyLinkedList() {
        // dummy initialization
        head = new Node(0);
        tail = new Node(0);

        // dummy connection
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int index) {
        if (index < 0) {
            return -1;
        }

        Node* curr = head->next; 
        int i = 0;
        
        while (curr != tail) {
            if (index == i) {
                return curr->data;
            }
            curr = curr->next;
            i++;
        } 

        return -1;
    }
    
    void addAtHead(int val) {
        Node* new_node = new Node(val);
        Node* first_node = head->next; // our curr index 0 element

        new_node->next = first_node;
        new_node->prev = head;
        
        first_node->prev = new_node;
        head->next = new_node; 
    }
    
    void addAtTail(int val) {
       Node* new_node = new Node(val);
       Node* last_node = tail->prev; // our curr last index element 

       new_node->next = tail;
       new_node->prev = last_node;

       last_node->next = new_node;
       tail->prev = new_node;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0) {
            return;
        }

        Node* new_node = new Node(val);
        Node* curr = head; 
        int i = 0;
        
        while (curr != tail) {
            if (index == i) {
                Node* next_node = curr->next;

                new_node->prev = curr;
                new_node->next = next_node;

                curr->next = new_node;
                next_node->prev = new_node;
                
                return;
            }
            curr = curr->next;
            i++;
        } 

        return;    
    }
    
    void deleteAtIndex(int index) {
        if (index < 0) {
            return;
        }

        Node* curr = head->next;
        int i = 0;

        while (curr != tail) {
            if (index == i) {
                Node* prev_node = curr->prev;
                Node* next_node = curr->next;
    
                prev_node->next = next_node;
                next_node->prev = prev_node; 

                delete curr;

                return;
            }

            curr = curr->next;
            i++;
        }
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */