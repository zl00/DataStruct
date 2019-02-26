#include "String.h"

void getnext(String substr, int next[]) {
    int i = 0, j = -1
    next[i] = j

    while (i < substr.length - 1) {
        if (j == -1 || substr.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

void getnextvalue(String substr, int nextval[]) {
    int i = 0, j = -1
    nextval[i] = j

    while (i < substr.length - 1) {
        if (j == -1 || substr.ch[i] == substr[j]) {
            ++i;
            ++j;

            if (substr.ch[i] == substr.ch[j]) {
                nextval[i] = nextval[j];
            } else {
                nextval[i] = j;
            }
        } else {
            j = nextval[j];
        }
    }
}

int kmp(String str, String substr, int next[]) {
    int i = 0, j = -1
    while (i < str.length && j < substr.length) {
        if (j == -1 || str.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }

    if (j == substr.length) {
        return i - substr.length + 1
    } else {
        return -1;
    }
}