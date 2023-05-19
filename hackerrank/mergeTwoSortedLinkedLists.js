function mergeLists(head1, head2) {
    const result = new SinglyLinkedList();
    let cur = result;
    
    while(head1 !== null && head2 !== null){
        if(head1.data <= head2.data){
            cur.next = head1;
            head1 = head1.next;        
        } else{
            cur.next = head2;
            head2 = head2.next;
        }
        cur = cur.next;
    }
    
    cur.next = head1 === null ? head2 : head1;

    return result.next;
}
