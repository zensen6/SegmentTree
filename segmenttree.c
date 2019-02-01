#include <stdio.h>
#include <stdlib.h>
#define NUMBER 7

int arr[] = { 1,4,2,7,6,5,9 };
int tree[4 * NUMBER];


int init(int start, int end, int node) { //node�� tree�� 1���� ����

	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node*2) + init(mid + 1, end, node*2+1);
}

//start: �����ε���, end:�� �ε���
//left, right: �������� ���ϰ����ϴ� ����
int sum(int start, int end, int node, int left, int right) { // tree�� leaf ���鸸 �Ѱ��

	if (start == end) {
		return tree[node];
	}

	int mid = (start + end) / 2;

	if (left <= mid && right>mid) {

		return sum(start, mid, node * 2, left, mid) + sum(mid + 1, end, node * 2 + 1, mid + 1, right);

	}
	else if(left>mid){

		start = mid + 1;
		return sum(start, end, node * 2 + 1, left, right);
	}
	else if (right <= mid) {

		end = mid;
		return sum(start, end, node * 2, left, right);
	}
	

}

int sum1(int start, int end, int node, int left, int right) {

	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];      // �̰�츦 sum0������ leaf ���� �ٱ��ؼ� ������ ���̴�.
	int mid = (start + end) / 2;
	return sum1(start, mid, node * 2, left, right) + sum1(mid + 1, end, node * 2 + 1, left, right);


}


int main() {

	init(0, NUMBER - 1, 1);
	printf("%d\n",sum(0, NUMBER - 1, 1, 2, 4)); //15���
	printf("%d\n",sum1(0, NUMBER - 1, 1, 2, 4));

}
