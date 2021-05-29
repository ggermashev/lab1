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

//������� ������� ������
struct Error* create_err();

//������: ��������� �������
void dif_size(struct Error* err);

//������� ������
struct List* create_list();

//����� ������
void output_err(struct List* list);

//�������� ������ � ������
void add_error(void* (*func) (struct List* list), struct List* list);

//������: ������������ ����� ����
void zero_det(struct Error* err);

//������: ������� ���������
void null_ptr(struct Error* err);
#endif
//�������� ������ � ��������
void dlt_err(struct List* list);