class BrowserHistory {
private:
    struct Node {
        string url;
        Node* next;
        Node* prev;

        Node (string domain){
            url = domain;
            next = nullptr;
            prev = nullptr;
        }
    };
public:

    Node* homeNode;
    Node* curr;
    int size;

    BrowserHistory(string homepage) { 
        homeNode = new Node(homepage);
        curr = homeNode;
    } 
    
    void visit(string url) {
        Node* temp = curr->next;
        while (temp != nullptr) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }

        Node* new_page = new Node(url);
        new_page->prev = curr;
        curr->next = new_page;

        curr = new_page;
    }
    
    string back(int steps) {
        for(int i=steps; i > 0; i--) {
            if (curr->prev == nullptr) {
                return curr->url;
            }
            curr = curr->prev;
        }    
        return curr->url;
    }
    
    string forward(int steps) {
        for(int i=steps; i > 0; i--) {
            if(curr->next == nullptr) {
                return curr->url;
            }
            curr = curr->next;
        } 
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */