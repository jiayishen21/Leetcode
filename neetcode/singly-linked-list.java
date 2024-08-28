/*
Design Singly Linked List
Neetcode easy
https://neetcode.io/problems/singlyLinkedList
time: 25 minutes
notes: haven't touched java in a while. had to look up syntax for java classes and methods
*/

class Node {
	int val;
	Node next;

	public Node(int val) {
		this.val = val;
		this.next = null;
	}

	public Node(int val, Node next) {
		this.val = val;
		this.next = next;
	}
}

class LinkedList {
	Node head;

    public LinkedList() {
		head = null;
    }

    public int get(int index) {
		Node cur = head;
		for(int i = 0; i < index; i ++) {
			if(cur == null) {
				return -1;
			}
			cur = cur.next;
		}
		if(cur == null) {
			return -1;
		}
		return cur.val;
    }

    public void insertHead(int val) {
		Node newHead = new Node(val, head);
		head = newHead;
    }

    public void insertTail(int val) {
		Node cur = head;

		if(head == null) {
			head = new Node(val);
			return;
		}

		while(cur.next != null) {
			cur = cur.next;
		}
		cur.next = new Node(val);
    }

    public boolean remove(int index) {
		if(head == null) {
			return false;
		}

		// edge case to remove head
		if(index == 0) {
			head = head.next;
			return true;
		}

		Node cur = head;
		for(int i = 0; i < index - 1; i ++) {
			if(cur == null) {
				return false;
			}
			cur = cur.next;
		}

		if(cur == null || cur.next == null) {
			return false;
		}

		cur.next = cur.next.next;
		return true;
    }

    public ArrayList<Integer> getValues() {
		ArrayList<Integer> values = new ArrayList<>();
		Node cur = head;
		while(cur != null) {
			values.add(cur.val);
			cur = cur.next;
		}
		return values;
    }
}
