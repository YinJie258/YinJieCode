#include <stdio.h>

int main() {
	int array[] = {1, 1, 1, 1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 8, 9};
	int length = sizeof(array) / sizeof(*array);
	int p = 0;
	for (int s = 0; s < length - p - 1; s++) {
		if (array[s] == array[s + 1]) {
			p++;
			for (int k = s + 1; k < length - p - 1; k++) {
				array[k] = array[k + 1];
			}
			s--;
		}
	}

	for (int i = 0; i < length - p; ++i)
		printf("%d ", array[i]);
	return 0;
}
