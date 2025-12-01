bool isCircular(Node* head) {
    
    if (!head) return false;
    Node* temp = head->next;
    while (temp && temp != head) temp = temp->next;
    return (temp == head);
}
