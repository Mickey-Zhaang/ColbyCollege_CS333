fn main() {
 /*
  * binds x to 5
  * **immutable**
  * Rust infers x as i32 (default integer type)
  */
 let _x = 5;

 /*
  * assigns y to 10
  * **mutable**
  * essentally overwriting memory by letting it be mutable
  */
 let _y = 10;

 /*
  * assigns z to 0
  * explicit typing
  * - default integer type specifically i32
  */
 let _z: i32 = 0;

 /*
  * {} start's a "block"
  * this is like block scoping
  * as inner is like an access modifier that only exists inside this block
  */
 {
  let _inner = 1;
 }

 /*
  * Shadowing
  * the second let x = x + 1 doesn't change/mutate x
  * instead it hides x = 5 so x is now x is bound to the value 6
  */
 let x = 5;
 let _x = x + 1;
}
