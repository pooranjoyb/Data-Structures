#include "search.h"
#include <stdio.h>
int main() {
  int n, key, loc;
  printf("Enter the size of 1D array : ");
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    printf("Enter element %d : ", i + 1);
    scanf("%d", &arr[i]);
  }
  printf("Enter the number you want to search : ");
  scanf("%d", &key);
  loc = linearsearch(arr, n, key);
  if (loc == 0) {
    printf("\nElement not found");
  } else
    printf("\nThe element is found at the location %d", loc);
  printf("\n");
  return 0;
}
