bool isPalindrome(DoublyLinkedList& dlist) {
    if (!dlist.head) return true;
    Node* left = dlist.head;
    Node* right = dlist.head;
    while (right->next) right = right->next;
    while (left != right && left->prev != right) {
        if (left->data != right->data) return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}
