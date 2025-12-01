int sizeDoubly(DoublyLinkedList& dlist) {
    int count = 0;
    Node* temp = dlist.head;
    while (temp) { count++; temp = temp->next; }
    return count;
}

int sizeCircular(CircularLinkedList& clist) {
    if (!clist.head) return 0;
    int count = 1;
    Node* temp = clist.head->next;
    while (temp != clist.head) { count++; temp = temp->next; }
    return count;
}
