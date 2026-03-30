#include <stdio.h>

int main() {
	int array[] = {1, 1, 1, 1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 8, 9};
	int length = sizeof(array) / sizeof(*array);
	for (int i = 0, j = 1, k = 0; i < length; i++) {
		if (array[i] == array[j]) {
			array[k++] = array[++j];
			i = j;
		}else{
			
		}
	}
}
