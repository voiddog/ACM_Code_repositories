#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
char AGCT[5] = {"AGCT"};
int main(){
    freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int test;
    test = rand()%5+1;
    while(test--){
	int n = rand()%5+1;
	printf("%d\n", n);
	for(int i=0; i<n; i++){
	    int len = rand()%5+1;
	    for(int j=0; j<len; j++){
		putchar(AGCT[rand()%4]);
	    }
	    putchar('\n');
	}
	int len = rand()%10+1;
	for(int i=0; i<len; i++){
	    putchar(AGCT[rand()%4]);
	}
	putchar('\n');
    }
    puts("0");
    return 0;
}
