// Task 3: Built-in types, operators, and aggregate types in Rust

/// Aggregate type: struct groups named fields (like a record).
struct Point {
 x: f64,
 y: f64,
}

fn main() {
 // ---- Built-in: integers (i32) ----
 // Operators + - * / % on integers -> result is same integer type
 let a: i32 = 10;
 let b: i32 = 3;
 let sum: i32 =
  a + b; // + -> i32
 let diff: i32 =
  a - b; // - -> i32
 let prod: i32 =
  a * b; // * -> i32
 let quot: i32 =
  a / b; // / -> i32 (integer division, truncates)
 let rem: i32 =
  a % b; // % -> i32 (remainder)
 println!("i32 ops: sum={} diff={} prod={} quot={} rem={}", sum, diff, prod, quot, rem);

 // ---- Built-in: floats (f64) ----
 // + - * / on floats -> result is f64 (no % on f64 in std lib)
 let x: f64 = 10.0;
 let y: f64 = 3.0;
 let fsum: f64 =
  x + y;
 let fquot: f64 =
  x / y; // actual division, not truncation
 println!("f64 ops: sum={} quot={}", fsum, fquot);

 // ---- Built-in: bool ----
 // &&, ||, ! and comparisons (==, <, etc.) -> result is bool
 let t: bool = true;
 let f: bool =
  false;
 let and: bool =
  t && f;
 let or: bool =
  t || f;
 let cmp: bool =
  3 < 5;
 println!("bool: and={} or={} cmp={}", and, or, cmp);

 // ---- Built-in: char ----
 // Single Unicode scalar value; ==, < etc. -> bool
 let c1: char = 'a';
 let c2: char = 'b';
 let eq: bool =
  c1 == c2;
 println!(
  "char eq: {}",
  eq
 );

 // ---- Built-in: strings ----
 // &str = string slice; String = owned heap string
 // String + &str -> String (left must be String)
 let s: &str =
  "hello";
 let s2: String =
  String::from(
   " world",
  );
 let combined: String = s.to_string() + &s2;
 println!(
  "strings: {}",
  combined
 );

 // ---- Aggregate: struct ----
 // Fields used in expressions; operator result type is the field type
 let p = Point {
  x: 1.0,
  y: 2.0,
 };
 let sum_xy: f64 =
  p.x + p.y;
 println!("Point {{ x: {}, y: {} }} -> x+y={}", p.x, p.y, sum_xy);
}
