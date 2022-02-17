#include "stdio.h"
#include "sqlist.h"
//unionSet
void unionSet(list* LA, list* LB, list* &LC){
    int i=0;
    int j=0;
    int k=0;
    //i记录LC，j记录LA，k记录LB
    LC->list[i] = LA->list[j];
    LC->length++;
    j++;
    i++;
    while (1){

        if(j>=LA->length && k>=LB->length) {
            break;
        }


        int m;
        for (m=0;m<=i;m++){
            if(LC->list[m] == LA->list[j] || LA->list[j] == 0 || j>=LA->length) {
                j++;
                break;
            }
            if (m == i){
                LC->list[i++] = LA->list[j++];
                LC->length++;
                break;
            }
        }

        int n;
        for (n=0;n<=i;n++){
            if(LC->list[n] == LB->list[k] || LB->list[k] ==0 || k>=LB->length) {
                k++;
                break;
            }
            if (n == i){
                LC->list[i++] = LB->list[k++];
                LC->length++;
                break;
            }
        }


    }
}



//int main(){
//    int setA[MaxSize] = {1,2,3,4,1,11,1,199};
//    int setB[MaxSize] = {2,2,5,6,7,20,3999,10};
//    int setC[MaxSize] = {0};
//    //求A并B
//    list* LA;
//    list* LB;
//    list* LC;
//    CreateList(LA);
//    CreateList(LB);
//    CreateList(LC);
//    InitList(LA,setA);
//    InitList(LB,setB);
//    InitList(LC,setC);
//    unionSet(LA,LB,LC);
//    DispList(LC);
//
//
//    return 0;
//}