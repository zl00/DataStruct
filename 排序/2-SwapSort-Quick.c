/**
 - 逻辑
 -- [粗调]
    选择“枢纽”，将比其大的数据交换到右侧，反之左侧；递归调用至结束。
 
 -- [精调] 因递归是相似逻辑的套用，所以只须分析递归内的过程。
    1. 对象
    Object: 扫描对象是 [low...high] 之间数组；
    Axis: 定位“枢纽”，默认low位置
    Cursor: i指向首，j指向尾
 
    2. 逻辑
    what i,j朝中间扫描，每次遇到不符合顺序的item，将其交换到“相应位置”去。
    who j先行，因以low作为”枢纽“，也就是i先让出位置。所以j先扫描。
    where 什么是“相应位置”？ j的数据放到i位置去。
 
 
 - 复杂度
 -- [时间]
    O(n*log₂ᴺ)
    
 -- [空间] 因为递归，所以空间都出在函数压栈上
    O(log₂ᴺ)
 */
void QuickSort(int R[], int low, int high) {
    if (low >= high) { 
        return
    }

    int i = low, j = high;
    int temp = R[i];

    while (i < j) {
        // right
        while (i < j && R[j] >= temp) { j--; }
        if (i < j) {
            R[i] = R[j];
            i++;
        }

        // left
        while (i < j && R[i] <= temp) { ++i; }
        if (i < j) {
            R[j] = R[i];
            j--;
        }
    }

    R[i] = temp;

    QuickSort(R, low, i-1);
    QuickSort(R, i+1, high);
}