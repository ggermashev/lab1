
#include "mystring.h"

void memcpy(char *s, char *c, int k){
        for (int i = 0; i < k; i++){
                s[i] = c[i];
        }
}


int strlen(char *s){
        int i = 0;
        while (s[i] != '\0'){
                i++;
        }
        return(i);
}

int strspn(char *s1, char *s2){
        int dl = 0;
        for (int i = 0; i < strlen(s1); i++){
                int flag =0;
                for (int j = 0; j < strlen(s2); j++){
                        if (s1[i] == s2[j]) flag = 1;
                }
                if (flag == 0) return dl;
                dl++;
        }
}

int strcspn(char *s1, char *s2){
        int dl=0;
        for (int i=0; i<strlen(s1); i++){
                int flag =0;
                for (int j=0; j<strlen(s2); j++){
                        if (s1[i] == s2[j]) {flag = 1;}
                }
                if (flag == 1) {return dl;}
                dl++;
        }
        return dl;
}
