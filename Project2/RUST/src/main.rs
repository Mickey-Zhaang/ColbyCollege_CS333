fn main() {
    // Printing Hello World
    // println!("Hello World");

    // From an engineering perspective
    let s = String::from("I am the owner");

    take_ownership(s);


    /*
     * Transfer of Responsibility
     * - In C, passing a pointer is passing around an address
     *      where any function that has access to the address can mess with
     *      the value at the memory address -> leads to irresponsible memory (free)
     *
     * - In Rust, the variable s has its ownership moved to take_ownership.
     *      It is freed at the end of that function -> automatic freeing; the variable is
     *      invalidated in fn main (gone from this scope).
     */

    // println!("{}", s);

    /*
     * Borrowing vs Cloning
     * - Borrowing: essentially lending the data. The owner is still main and the memory is not freed
     *      fn some_func(s: &String): & -> lending?
     * 
     * - Cloning: deep copying data onto the heap. Requires reallocation which is really expensive
     *      fn some_func(s.clone()): where s.clone() is passed into some function
     */

}

fn take_ownership(some_string: String) {
    println!("Received: {}", some_string)
} // s: String was freed at the end of this function
