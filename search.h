int linearsearch(int arr[], int size, int item) {

  int found;

  for (int i = 0; i < size; i++) {
    if (arr[i] == item) {
      found = i;
    }
  }
  if (found != 0) {
    return found+1;
  } else
    return 0;
}

int binarysearch(int arr[], int size, int item) {
  int flag, low = 0, high = size-1, mid;
  while (high >= low) {
    mid = (low + high) / 2;
    if (arr[mid] == item) {
      flag++;
      break;
    }

    else if (item > arr[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  if (flag != 0) {
    return mid+1;
  } else
    return 0;
}
