/**
 * Task 1: Identifier naming, variable declarations, and scoping in TypeScript.
 * Naming: camelCase for variables/functions; identifiers can use letters, digits, _, $.
 */

// ---- Declarations ----
// const: immutable binding (cannot reassign)
const x = 5;

// let: block-scoped, can be reassigned
let y = 10;
y = 20; // allowed

// Explicit type annotation (optional)
const z: number = 0;

// ---- Block scope ----
// Variables declared with let/const are only visible inside the block
{
  const inner = 1;
  console.log("inner inside block:", inner);
}
// console.log(inner); // would be ReferenceError - inner is not in scope

// ---- Shadowing ----
// A new binding with the same name in an inner scope hides the outer one
let a = 5;
{
  let a = 10; // shadows outer a inside this block
  console.log("a inside block:", a); // 10
}
console.log("a outside block:", a); // 5 (outer binding unchanged)

// Shadowing: inner block reuses the name; outer 'b' is hidden until block ends
let b = 1;
{
  const b = 2; // inner 'b' shadows outer for this block
  console.log("b inside block:", b); // 2
}
console.log("b outside block:", b); // 1 (outer binding unchanged)

export {};
