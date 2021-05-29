#include "Error.h"
#include <stdlib.h>

struct Error* create_err() {
	struct Error* err = (struct Error*)calloc(1, sizeof(struct Error));
	err->num = 0;
}

void dif_size(struct Error* err) {
	err->num = 1;
	err->happend = calloc(16, sizeof(char));
	err->happend = "different sizes";
	err->next = create_err();
}

struct List* create_list() {
	struct List* list = (struct List*)calloc(1, sizeof(struct List));
	list->head = NULL;
	list->tail = NULL;
}

void output_err(struct List* list) {
	struct Error* ptr = list->head;
	while (ptr->next) {
		printf("ERROR %d::\n", ptr->num);
		printf("%s\n", ptr->happend);
		printf("In:%s\n", ptr->where_);
		printf("--------------------------\n");
		ptr = ptr->next;
	}
	if (ptr->num != 0) {
		printf("ERROR %d::\n", ptr->num);
		printf("%s\n", ptr->happend);
		printf("In:%s\n", ptr->where_);
	}
}

void add_error(void* (*func) (struct List* list), struct List *list) {
	if (list->tail) {
		struct Error* ptr = list->tail->next;
		func(ptr);
		list->tail = ptr;
	}
	else
	{
		struct Error* err = create_err();
		func(err);
		list->head = err;
		list->tail = err;
	}
}

void zero_det(struct Error* err) {
	err->num = 2;
	err->happend = calloc(17, sizeof(char));
	err->happend = "determiner == 0!";
	err->next = create_err();
}

void null_ptr(struct Error* err) {
	err->num = 3;
	err->happend = calloc(9, sizeof(char));
	err->happend = "NULL PTR";
	err->next = create_err();
}

void dlt_err(struct List* list) {
	struct Error* ptr = list->head;
	while (ptr->next) {
		struct Error* ptr_next = ptr->next;
		free(ptr);
		ptr = ptr_next;
	}
	free(ptr);
	free(list);
	list = create_list();
}