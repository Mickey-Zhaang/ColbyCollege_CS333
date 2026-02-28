fn main() {
    fn binary_search(arr: &[i32], target: i32) -> Option<usize> {
        let mut low: usize = 0;
        let mut high: usize = arr.len();

        while low < high {
            let mid = low + (high - low) / 2;
            if arr[mid] < target {
                low = mid + 1;
            } else if arr[mid] > target {
                high = mid;
            } else {
                return Some(mid);
            }
        }
        None
    }

    // initiate arr and target
    let arr = [1, 3, 4, 6, 7, 9];
    let target = 7;

    // run the binary search
    let res = binary_search(&arr, target);

    // check res
    if res == None {
        println!("Found Nothing!");
    } else {
        println!("Found {} at index {}", target, res.unwrap());
    }
}
