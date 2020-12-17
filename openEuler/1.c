#include <stdio.h>
typedef struct node {
    int start;
    int end;
};
int main(void) {
    int n;
    scanf("%d", &n);
    struct node input[n];
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &input[i].start, &input[i].end);
    }
// 对每个活动按照结束时间从先到后排序
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n-i-1; j++) {
            if (input[i].end > input[j].end) {
                struct node temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }
//定义结束时间为第一个活动的结束时间
    int endTime = input[0].end;
//result 表示要安排的会场数， 初始化为 1
// flag 标记 用于更行结束时间
    int result = 1, flag = 0;
// 从第二个活动开始检索
    for (int i = 1; i < n; i++) {
//如果新活动的开始时间先于已分配会场活动的结束时间，需要重新分配会场
        if (input[i].start < endTime) {
            result++;
            continue;
        }
//如果活动时间晚于已分配会场的活动时间，会场可以复用 需要更新结束时间
        if (input[i].start >= endTime) {
            flag++;
            endTime = input[flag].end;
        }
    }
    printf("%d\n", result);
}
