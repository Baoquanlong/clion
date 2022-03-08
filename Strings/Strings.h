#ifndef STRINGS_STRINGS_H
#define STRINGS_STRINGS_H
#define MaxSize 20
typedef char ElemType;
typedef struct {
    ElemType data[MaxSize];
    int length;
}String;

void StrAssign(String &s, char cStr[]);
void  GetNextj(String t, int next[]);
void DispStr(String s);
int Index_KMP(String s, String t);
int Index_BF(String s , String t);


String RepStr(String s, int i, int j, String t);
String DelStr(String s1,int i , int j);
String InsStr(String s1, int i, String s2);



String SubString(String s, int i, int j);
String ConCat(String s, String t);



int StrLength(String s);
bool StrEqual(String s, String t) ;
void StrCopy(String &s, String t);
void DestroyStr(String &s);


#endif //STRINGS_STRINGS_H
