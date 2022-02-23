#include "cstdio"
#include "malloc.h"
#include "Strings.h"

void StrAssign(String &s, char cStr[]) {
    int i = 0;
    while (cStr[i] != '\0') {
        s.data[i] = cStr[i];
        i++;
    }
    s.length = i;
}


void DestroyStr(String &s) {

}

//将t赋值给s
void StrCopy(String &s, String t) {
    int i = 0;
    while (t.data[i] != '\0') {
        s.data[i] = t.data[i];
        i++;
    }
    s.length = t.length;
}


bool StrEqual(String s, String t) {
    int i = 0;
    for (i; t.data[i] != '\0'; i++) {
        if (t.data[i] != s.data[i]) {
            printf("%s and %s aren't equal", s, t);
            return false;
        }
    }
    printf("%s and %s are equal", s, t);
    return true;
}


int StrLength(String s) {
    return s.length;
}


String *ConCat(String s, String t) {
    String *new_S;
    new_S = (String *) malloc(sizeof(String));
    int i = 0;
    while (s.data[i] != '\0') {
        new_S->data[i] = s.data[i];
        new_S->length++;
        i++;
    }
    //用于将i拉回到0开始计数
    int temp = new_S->length;
    while (t.data[i - temp] != '\0') {
        new_S->data[i] = t.data[i - temp];
        new_S->length++;
        i++;
    }
    return new_S;
}

//从第i个开始连续个字符组成的子串
String SubString(String s, int i, int j) {
    String retS;
    int k = i - 1;
    int diff = i;
    for (k; k < i + j; k++) {
        retS.data[k - diff + 1] = s.data[k];
    }
    return retS;
}


//将串s2插入到串s1的第i个位置。
String InsStr(String s1, int i, String s2) {
    if (i < 1 || i > s1.length + 1) {
        printf("i is out of range");
        String retS;
        int i = 0;
        while (i < MaxSize) {
            retS.data[i] = '\0';
            i++;
        }
        retS.length = 0;
        return retS;
    }
    // 当i在范围内时：
}
