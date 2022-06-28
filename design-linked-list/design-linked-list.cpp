class MyLinkedList {
public:
    
    class Node{
    public:    
        int val;
        Node* next;
        
        Node(int x){
            val = x;
            next = NULL;
        }
    };
    
    Node* head;
    int len;
    MyLinkedList() {
        head = NULL;
        len=0;
        cout << "len= "<<len<<"\n"; 
    }
    
    int get(int index) {
        if(index >= len)
            return -1;
        
        Node* tmp = head;
        int counter = 0;
        while(counter++ < index)
            tmp = tmp->next;
        
        return tmp->val;
    }
    
    void addAtHead(int val) {
        Node* nhead = new Node(val);
        nhead->next = head;
        head = nhead;
        len++;
        cout << "len= "<<len<<"\n"; 
    }
    
    void addAtTail(int val) {
        if(!head){
            addAtHead(val);
            return;
        }
            
        
        else{
            Node* tmp = head;
            while(tmp and tmp->next != NULL){
                tmp = tmp->next;
            }
            tmp->next = new Node(val);            
        }
        len++;
        cout << "len= "<<len<<"\n\n"; 
    }
    
    void addAtIndex(int index, int val) {
        if(index>len)
            return;
        
        if(index==0){
            this->addAtHead(val);
            return;
        }
            
        else{
            int ind=1;
            Node* tmp = head;
            while(ind++ < index){
                tmp = tmp->next;
            }

            Node* nnode = new Node(val);
            nnode->next = tmp->next;
            tmp->next = nnode;    
            
        }
        len++;
        cout << "len= "<<len<<"\n"; 
        
    }
    
    void deleteAtIndex(int index) {
        if(index >= len)
            return;
        
        if(index == 0){
            head = head->next;
        }
        else{
            int ind=1;
            Node* tmp = head;
            while(ind++ < index){
                tmp = tmp->next;
            }
            tmp->next = tmp->next->next;
               
        }
        len--;
        cout << "len= "<<len<<"\n"; 
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