#include "mydef.h"

template<class T>
void removeduplicate(Node<T>* head) {
	Node<T>* cur=head;
	Node<T>* remaining;
	while(cur->next) {
		remaining=cur->next;
		while(remaining) {
			if (cur->data == remaining->data) {
				cur->next = remaining->next;
				delete remaining;
				remaining = cur->next;
			} else {
				remaining = remaining->next;
			}
		}
	}
}