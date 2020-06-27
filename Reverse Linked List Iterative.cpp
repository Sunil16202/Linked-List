node* rev_linkedlist_itr(node* head)
{
    //write your iterative code here
    node * prev = NULL;
    node * current = head;
    node * nxt = NULL;
    
    while(current != NULL){
        nxt = current -> next;
        current -> next = prev;
        prev = current;
        current = nxt;
    }
    return prev;
}