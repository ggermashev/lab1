#ifndef ERROR_H
#define ERROR_H

struct Error {
	int num;
	char* happend;
	char* where_;
	struct Error* next;
};

struct List {
	struct Error* head;
	struct Error* tail;
};

//создать элемент списка
struct Error* create_err();

//ошибка: различные размеры
void dif_size(struct Error* err);

//создать список
struct List* create_list();

//вывод ошибок
void output_err(struct List* list);

//добавить ошибку в список
void add_error(void* (*func) (struct List* list), struct List* list);

//ошибка: определитель равен нулю
void zero_det(struct Error* err);

//ошибка: нулевой указатель
void null_ptr(struct Error* err);
#endif
//очистить список с ошибками
void dlt_err(struct List* list);