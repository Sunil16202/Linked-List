// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

class Pair{
    public:
    node * head;
    node * tail;
};

Pair reversell(node * head){
    if(head == NULL || head -> next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair revhead = reversell(head->next);
    node * tail = head -> next;
    tail -> next = head;
    head->next = NULL;

    Pair ans;
    ans.head = revhead.head;
    ans.tail = head;

    return ans;
}

struct node *reverse(struct node *head, int n)
{ 
    if(head == NULL || head -> next == NULL){
        return head;
    }
    
    if(n==0){
        return head;
    }
    
    node * head1 = head;
    node * tail1 = head;
    int count = 1;
    while(count != n && tail1-> next != NULL){
        tail1 = tail1 -> next;
        count++;
    }
    
    node * head2 = NULL;
    head2 = tail1 -> next;
    
    
    tail1 -> next = NULL;
    
    Pair rev = reversell(head1);
    
    node * ans = reverse(head2,n);
    
    rev.tail -> next = ans;
    return rev.head;

}