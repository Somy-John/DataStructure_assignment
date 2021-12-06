#include <iostream>

using namespace std;

void my_sort(int *p,int num);

int main( )
{
	int  list[10] = { 23, 11, 15, 8, 17, 33, 7, 14, 19, 21 };
	int  i ; 
      	my_sort(list, 10);   // 배열 list의 원소 10개를 sort하는 함수
      	for (i = 0; i< 10; i++)
		cout << list[i] << '\n';
      	return 0;
}

void my_sort(int *p,int num){
 	int i,j,tmp;
	for(i=0;i<num;i++){
		for(j=0;j<num-1-i;j++){
			if(p[j]>p[j+1]){
				tmp=p[j];
				p[j]=p[j+1];
				p[j+1]=tmp;
			}
		}
	}
}
