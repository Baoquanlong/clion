#include "cstdio"
#include "malloc.h"
#include "Strings.h"

void StrAssign(String &s, char cStr[]) {
    int i = 0;
    while (cStr[i] != '\000') {
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
    for (i; t.data[i] != '\000'; i++) {
        if (t.data[i] != s.data[i]) {
            return false;
        }
    }
    return true;
}


int StrLength(String s) {
    return s.length;
}


String ConCat(String s, String t) {
    String new_S;
    int i = 0;
    while (s.data[i] != '\0') {
        new_S.data[i] = s.data[i];
        new_S.length++;
        i++;
    }
    //用于将i拉回到0开始计数
    int temp = new_S.length;
    while (t.data[i - temp] != '\0') {
        new_S.data[i] = t.data[i - temp];
        new_S.length++;
        i++;
    }
    return new_S;
}

//从第i个开始连续个字符组成的子串
String SubString(String s, int i, int j) {
    String retS;
    int k = i - 1;
    int dist = k;
    for (k; k < i - 1 + j; k++) {
        retS.data[k-dist] = s.data[k];
    }
    retS.length = j;
    return retS;
}


//将串s2插入到串s1的第i个位置。
String InsStr(String s1, int i, String s2) {
    if (i < 1 || i > s1.length + 1) {
        printf("i is out of range");
        String retS;
        int i = 0;
        while (i < MaxSize) {
            retS.data[i] = '\000';
            i++;
        }
        retS.length = 0;
        return retS;
    }
    // 当i在范围内时：
    int k = s1.length;
    int j = 0;
    for (k;k>i-1;k--){
        s1.data[k-1+s2.length] = s1.data[k-1];
    }
    for (k = i-1 ;k<i-1+s2.length;k++){
        s1.data[k] = s2.data[j];
        j++;
    }
    s1.length += s2.length ;
    return s1;
}

//从串s1中删除从第i个字符开始长度为j的子串，返回新串
String DelStr(String s1,int i , int j){
    int k;
    for (k = i;s1.data[k] != '\0';k++) {
        s1.data[k-1] = s1.data[k-1+j];
    }
    s1.length = s1.length-j;
    return s1;
}

//替换，在串s中将第i个字符开始的j个字符构成的子串用串t替换，并返回新串
String RepStr(String s, int i, int j, String t){
    int k = 0;
    for (k = i;k<i+j;k++) {
        s.data[k-1] = t.data[k-i];
    }
    return s;
}


//输出，输出串s的所有字符值
void DispStr(String s){
    int j ;
    for (j = 0;j<s.length;j++){
        printf("%c",s.data[j]);
    }
    printf("\n");
}



int Index_BF(String s , String t){
    int i = 0 ;
    int j = 0 ;
    while ( i<s.length && j<t.length) {
        if (s.data[i] == t.data[j]){
            i++;
            j++;
        }else if(s.data[i] != t.data[j]){
            i = i-j+1;
            j = 0 ;
        }
        if (j>=t.length){
            return i-j+1;
        }
    }

    return -1;
}


//KMP算法主要是求next[j]数组
void  GetNextj(String t, int next[]){
    //next[]数组存的是前缀和后缀相等的最大数目。由于我们是从0开始的，所以next[]数组得到的也直接是应该让模式串开始匹配的地方
    int j,k;
    j = 0;
    k = -1;
    next[0] = -1;
    while(j<t.length-1){
        if (k == -1 || t.data[j] == t.data[k]){
            j++;
            k++;
            next[j] = k;
        } else{
            k = next[k] ;
        }
    }
}


int Index_KMP(String s, String t){
    //i 指的是 s
    int i = 0 ;
    //j 指的是 t
    int j = 0 ;

    int next[t.length] ;
    GetNextj(t,next);

    while ( i < s.length && j< t.length ) {
        if ( j == -1 || s.data[i] == t.data[j]){
            i++;
            j++;
        } else{
            j = next[j];
        }
        if (j>=t.length){
            return i-t.length+1;
        }
    }


    return -1;
}

