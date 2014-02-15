#include "list.h"
#include <stdio.h>

#define MAX 20

void list_dump(List *list) {
    ListElmt *l = list->head;
    while(l->next) {
        printf("data %p  %d, %p\n", l, *(int*)(l->data), l->data);
        l = l->next;
    }
}

int main() {
    unsigned int i = 0;

	printf("list test:\n");
	
	List *list;
	if((list = (List *) malloc(sizeof(List))) == NULL)
		return -1;
	
	printf("list init\n");
	list_init(list, (void (*)(void*))my_destroy);

    for(i = 0; i < MAX; ++i) {
		int *tmp = (int *) malloc(sizeof(int));
		*tmp = i;
        printf("insert %d, list size %d\n", i, list_size(list));
        list_ins_next(list, NULL, tmp);
    }    

    list_destroy(list);
	
    //list_dump(list);	
	return 0;
}
