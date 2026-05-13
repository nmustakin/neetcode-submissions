class Node {
public:
    Node* next; 
    Node* prev;
    int val; 

    Node(int val){
        this->next = NULL;
        this->prev = NULL;
        this->val = val; 
    }

    Node(int val, Node* prev, Node* next){
        this->prev = prev;
        this->next = next;
        this->val = val; 
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }

    int get(int index) {
        int i = 0;
        Node* current = this->head;
        while(current != NULL){
            if(i == index) return current->val;
            i++;
            current = current->next; 
        }
        return -1;
    }

    void insertHead(int val) {
        Node* newHead = new Node(val); 
        newHead->next = this->head;
        if(this->head != NULL) this->head->prev = newHead;
        this->head = newHead; 
        if(this->tail == NULL) this->tail = newHead;
    }
    
    void insertTail(int val) {
        Node* newTail = new Node(val);
        newTail->prev = this->tail;
        if(this->tail != NULL) this->tail->next = newTail;
        this->tail = newTail;
        if(this->head == NULL) this->head = newTail;
    }

    bool remove(int index) {
        int i = 0;
        Node* prev = NULL;
        Node* current = this->head;
        while(current != NULL){
            if(i == index){
                if(current != this->head and current != this->tail){
                    prev->next = current->next;
                }
                else{
                    if(current == this->head){
                        this->head = current->next;
                    }
                    else{
                        this->tail = prev;
                    }
                }
                free(current);
                return true;
            }
            i++;
            prev = current; 
            current = current->next; 
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> values; 
        Node* current = this->head;
        while(current != NULL){
            values.push_back(current->val);
            current = current->next;
        }
        return values;
    }
};

