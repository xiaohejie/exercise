#include <iostream>
using namespace std;

void exercise(int* num , int k) {
    int length = 0;  //�ó�k�Ǽ�λ��Ч����
    int k1 = k;
    int k2 = sizeof(num) / sizeof(num[0]) - 1;
    while (k1 > 0) {
        length++;
        k1 /= 10;
    }
    //�����߽��бȽϣ���˭��λ������
    int arrLength = k2 > length ? k2 : length;
    //����������
    int* resArray = (int*)malloc(sizeof(int)*(arrLength + 1) );
    int isOver = 0;//�ж��Ƿ񳬹�10
    int index = 0;
    int a = 0;
    while (k2 >= 0) {
        a = num[k2];
        k2--;
    }
    while (arrLength--) {
        int sum = 0;
        sum = a + k % 10 + isOver;
        k /= 10;
        if (sum > 9) {
            sum -= 10;
            isOver = 1;
        }
        else {
            isOver = 0;
        }
        resArray[index] = sum;
        index++;
    }
    int start = 0;
    int end = index - 1;
    while (start < end) {
        int temp = resArray[start];
        resArray[start] = resArray[end];
        resArray[end] = temp;
        start++;
        end--;
    }
    return resArray;
}
int main() {
    int num[] = { 0,1,2,4,5,8 };
    int k = 56288;
    exercise(num , k);
	system("pause");
	return 0;
}