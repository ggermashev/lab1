#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *get_str() {
    char buf[81] = {0};
    char *ptr = NULL;
    int len = 0;
    int n = 0;
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!ptr) {
                return NULL;
            }
        } else if (n > 0) {
            int chunk_len = strlen(buf);
            int str__len = len + chunk_len;
            ptr = realloc(ptr, str__len + 1);
            memcpy(ptr + len, buf, chunk_len);
            len = str__len;
        } else {
            scanf("%*c");
        }
    } while (n > 0);

    if (len > 0) {
        ptr[len] = '\0';
    } else {
        ptr = calloc(1, sizeof(char));
    }

    return ptr;
}


int find_size(char *s1, char *s){ // находим кол-во символов из которых будут состоять слова, чтобы выделить соответсв$
        int l = 0;// левая граница
        int k = 0;// кол-во элементов в новой строке s2
        int dl;//длина найденного участка
        while (l < strlen(s1)) {
                l = l + strspn(s1 + l, s);//ищем первый символ
                dl =  strcspn(s1 + l, s);// ищем длину слова, начинающегося с символа s[l]
                k = k + dl; // увеличиваем значнеие длины на длину найденного слова
                l = l + dl;// сдвигаем l на первый пробел ( или таб) после найденного слова
        }
        return k; //возвращаем длину новой строки
}
void *  new_(char *s1, int sz, char *s2, char *s, int m){ // создаем новую строку в которую записываем символы кроме п$
        int l = 0;// левая граница
        int dl = 0; //длина найденного участка
        int k = 0; // кол-во элементов в новой строке s2
        int n = m ;
        int dll = 0;;
        int i = 0;
        int j = 0;
        while (k < sz){
                i = 0;
                l = l + strspn(s1 + l, s);//ищем первый символ
                dl = strcspn(s1 + l, s);// ищем длину слова, начинающегося с символа s[l]
                dll = dl; //длина слова, которую необходимо записать(будет записываться по частям)
                while (dll >= n)  {
                        memcpy(s2 + k, s1 + l + i ,n);// дописываем это слово в основную строку s2
                        dll = dll - n;// уменьшили длину найденного слова в строке s1
                        k = k + n ;// записали k элементов в строку s2
                        i += n;//для сдвига в найденном слове строки s1
                        if ((k < sz) && ((k - j) % m ==0)) { //записываем пробел
                                s2[k] = ' '; //пробел
                                k++; //увеличиваем длину строки на 1
                                n = m;// слово записано полностью, поэтому снова записываем слово длиной m(см. (*))
                                j++;//учет пробелов в кол-ве символов для вычисления нового места где нужен пробел
                        }

                }
                if ((dll < n) && (dll)){
                        memcpy(s2 + k, s1 + l +i ,dll);
                        n = n - dll;//(*) записан весь участок слова в строке s1,
                                    //но в строке s2 слово из меньше чем M букв, поэтому из
                                    //следующего слова строки s1 запишем слово длиной n-dll в сторку s2,
                                    //чтобы получилось слово длиной n(т.е.m)
                        k = k + dll;// увеличиваем длину s2 на величину записанного участка слова
                }

                l = l + dl;//сдвигаем l на первый после слова пробел, далее снова будет выполняться поиск первого в сл$
        }
}

int dop_size(int l, int m){
        if (l % m == 0) {
                return l / m - 1;
        }
        else return l / m;
}
int main()
{
        double time_total = 0;
        int i = 0;

        char *s1 = NULL;
        char *s = NULL;
        s = " \t";

    do{
        printf("vvedite stroku \n");
        s1 = get_str();

        if (s1){
                        srand(time(NULL));
                        i++;
            int m;

            printf("vvedite m \n");
            scanf("%d", &m);
                scanf("%*c");// ввод

                        clock_t t = clock();

                        if (m < 1) {
                                free(s1);
                                printf("nedopustimoe m\n");
                                continue;
                        }

                        int size = find_size(s1, s);
                        int size_new = size + dop_size(size, m);// ищем размер

                        if (size_new < 0) {
                                size_new = 0;
                        }

                        char *s2 = NULL;
            s2 = (char *) calloc(size_new + 1, sizeof(char));
                        new_(s1, size_new, s2, s, m);
                        printf("s2=%s\n", s2);
                        free(s2);

                        t = clock() - t;
                double time = (double) t / CLOCKS_PER_SEC;
                time_total += time;
                        printf("avarage time =%.10f seconds\n", time_total / i);
        }
                free(s1);
        } while (s1);
    return 0;
}
