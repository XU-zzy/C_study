//多维数组转置


#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define MAXSIZE 1000
#define Type int

typedef struct {
    int row;
    int col;
    Type value;
}Triple;

typedef struct{
    Triple data[MAXSIZE];
    int rows,clos,nums;
}TSMatrix;

TSMatrix* Insert_TSMatrix(int rows,int clos){
    cout << "请输入数组:" << endl;
    TSMatrix *arr = (TSMatrix*)malloc(sizeof(TSMatrix));
    arr->rows = rows;
    arr->clos = clos;
    arr->nums = 1;
    int n;
    for(int i = 1;i <= rows;i++){
        for(int j = 1;j <= clos;j++){  
            cin >> n;
            if(n != 0){  
                arr->data[arr->nums].value = n;
                arr->data[arr->nums].row = i;
                arr->data[arr->nums].col = j;
                arr->nums++;
            }
        }
    }
    if(arr->nums != 0){
        arr->nums -= 1;
    }
    return arr;
}

void print_TSMatrix(TSMatrix *arr){
    for(int i = 1;i <= arr->nums;i++){
        cout << arr->data[i].row << ' ' << arr->data[i].col << ' ' << arr->data[i].value << endl;
    }
}

void TransposeTSMatrix_1(TSMatrix *arr,TSMatrix *arr_t){
    arr_t->rows = arr->clos;
    arr_t->clos = arr->rows;
    arr_t->nums = 1;

    if(arr_t->nums){
        for(int k = 1;k <= arr->clos;k++){
            for(int i = 1;i <= arr->nums;i++){
                if(arr->data[i].col == k){
                    arr_t->data[arr_t->nums].row = arr->data[i].col;
                    arr_t->data[arr_t->nums].col = arr->data[i].row;
                    arr_t->data[arr_t->nums].value = arr->data[i].value;
                    arr_t->nums++;
                    cout << arr_t->data[arr_t->nums-1].value << endl;
                }
            }
        }

    }
    if(arr_t->nums > 0){
        arr_t->nums -= 1;
    }
}

void TransposeTSMatrix_2(TSMatrix *arr,TSMatrix *arr_t){
    int num[MAXSIZE],position[MAXSIZE];
    int col;
    arr_t->rows = arr->clos;
    arr_t->clos = arr->rows;
    arr_t->nums = arr->nums;

    if(arr_t->nums){
        //初始化num
        for(col = 1;col <= arr->clos;col++){
            num[col] = 0;
        }
        
        //遍历一次 arr ，给 num 赋值
        for(int i = 1;i <= arr->clos;i++){
            num[arr->data[i].col]++;
        }
        
        //初始化position
        position[1] = 1;

        //position 赋值
        for(col = 2;col <= arr->clos;col++){
            position[col] = position[col-1] + num[col-1];
        }

        //赋值
        for(int i = 0;i <= arr->nums;i++){
            col = arr->data[i].col;
            int j = position[col];
            arr_t->data[j].row = arr->data[i].col;
            arr_t->data[j].col = arr->data[i].row;
            arr_t->data[j].value = arr->data[i].value;
            //position 指向下一个
            position[col]++;
        }
    }
}

int main(){
    int rows,clos,nums;
    cout << "请输入行数和列数:" << endl;
    cin >> rows >> clos;
    nums = rows*clos;
    TSMatrix *arr = Insert_TSMatrix(rows,clos);

    /* print_TSMatrix(arr); */

    TSMatrix *arr_t = (TSMatrix*)malloc(sizeof(TSMatrix));
    /* TransposeTSMatrix_1(arr,arr_t); */
    TransposeTSMatrix_2(arr,arr_t);
    print_TSMatrix(arr_t);
}
