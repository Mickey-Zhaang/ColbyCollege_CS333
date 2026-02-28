/**
 * Task 2: Binary search on a sorted array.
 * Demonstrates function syntax and control flow (while, if/else).
 */

function binarySearch(arr: number[], target: number): number | null {
  let low = 0;
  let high = arr.length; // exclusive upper bound

  while (low < high) {
    const mid = low + Math.floor((high - low) / 2);

    if (arr[mid] < target) {
      low = mid + 1;
    } else if (arr[mid] > target) {
      high = mid;
    } else {
      return mid;
    }
  }
  return null;
}

const arr = [1, 3, 4, 6, 7, 9];
const target = 7;

const result = binarySearch(arr, target);

if (result === null) {
  console.log("Not found");
} else {
  console.log(`Found ${target} at index ${result}`);
}

export { binarySearch };
