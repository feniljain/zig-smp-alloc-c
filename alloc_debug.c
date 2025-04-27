#include<stdio.h>
#include<stdlib.h>

int main() {
		size_t len = 131103801258240;
		int *arr = malloc(len);
		printf("%p\n", arr);
		// realloc(arr, len + 8192);
		free(arr);

		int *arr1 = malloc(len);
		free(arr1);

		// for(int j = 0; j < 256; j++) {
		// 				int *arr =  malloc(j * sizeof(int));

		// 				for(int i = 0; i < j; i++) {
		// 						arr[i] = i;
		// 						printf("%d\n", arr[i]);
		// 				}
		// 				printf("%p\n", arr);

		// 				if(j % 10 == 0) {
		// 						free(arr);
		// 				}
		// }

    return 0;
}
