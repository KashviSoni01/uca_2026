class SearchLL {

    static class Node {
        int data;
        Node next;

        Node() {

        }

        Node(int data) {
            this.data = data;
        }
    }

    public static boolean search(Node head1, Node head2) {

        while(head2!=null) {

            if(head1.data==head2.data) {
                Node curr1=head1;
                Node curr2 = head2;

                while(curr1 != null && curr2 != null && curr1.data==curr2.data) {
                    curr1=curr1.next;
                    curr2=curr2.next;
                }
                if(curr1==null) return true;
            } else head2=head2.next;
        }
        return false;
    }

    static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {

        Node head1 = new Node(10);
        head1.next = new Node(20);

        Node head2 = new Node(5);
        head2.next = new Node(10);
        head2.next.next = new Node(20);


       if(search(head1, head2)) System.out.print("Yes");
       else System.out.print("No");
    }
}
