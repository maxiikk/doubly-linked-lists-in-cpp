#include <iostream>

using namespace std;

struct node{
    int value;
    struct node *prev;
    struct node *next;
};
typedef struct node nodet;
nodet *createnode(int val){
    nodet *result = new nodet;
    result->value = val;
    result->next = NULL;
    return result;
}
nodet *createnode2(int val, nodet *temp){
    nodet *result = new nodet;
    result->value = val;
    result->next = NULL;
    result->prev = temp;
    temp->next = result;
    return result;
}
void printlist (nodet *where, int mode){
	nodet *temp = where;
    while (temp != NULL){
        cout << temp->value <<"\n";
        if (mode == 1){
        	temp = temp->next;
		}
		else if (mode == 0) {
			temp = temp->prev;
		}
    }

}

int main()
{
    nodet *head = NULL;
    nodet *tail = NULL;
    nodet *temp;
    nodet *temp2;
    for (int i = 0; i < 20; i++){
    	if (i == 0){
    		temp2 = createnode(i);
    		tail = temp2;
		}
		else{
			temp2 = createnode2(i, head);
		}
        temp2->prev = head;
        head = temp2;
    }
	printlist(head, 0);
	cout << "\n";
	printlist (tail, 1);

    return 0;
}
