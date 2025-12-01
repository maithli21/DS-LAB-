void printCircularList(CircularLinkedList& clist) {
    if (!clist.head) return;
    Node* temp = clist.head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != clist.head);
    cout << endl;
}
