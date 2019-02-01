#include <stdio.h>
#include <stdlib.h>
#define NUMBER 7

int arr[] = { 1,4,2,7,6,5,9 };
int tree[4 * NUMBER];


int init(int start, int end, int node) { //node는 tree의 1부터 시작

	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node*2) + init(mid + 1, end, node*2+1);
}

//start: 시작인덱스, end:끝 인덱스
//left, right: 구간합을 구하고자하는 범위
int sum(int start, int end, int node, int left, int right) { // tree의 leaf 계산들만 한경우

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
	if (left <= start && end <= right) return tree[node];      // 이경우를 sum0에서는 leaf 까지 다구해서 합했을 뿐이다.
	int mid = (start + end) / 2;
	return sum1(start, mid, node * 2, left, right) + sum1(mid + 1, end, node * 2 + 1, left, right);


}


int main() {

	init(0, NUMBER - 1, 1);
	printf("%d\n",sum(0, NUMBER - 1, 1, 2, 4)); //15출력
	printf("%d\n",sum1(0, NUMBER - 1, 1, 2, 4));

}
