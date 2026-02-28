/**
 * Task 3: Built-in types, operators, and aggregate types in TypeScript.
 */

// ---- Aggregate type: interface (record/struct-like) ----
interface Point {
  x: number;
  y: number;
}

function main(): void {
  // ---- Built-in: number ----
  // + - * / % on numbers -> result is number
  const a = 10;
  const b = 3;
  const sum: number = a + b;
  const diff: number = a - b;
  const prod: number = a * b;
  const quot: number = Math.floor(a / b); // integer division (truncate)
  const rem: number = a % b;
  console.log("number ops:", sum, diff, prod, quot, rem);

  // ---- Built-in: number (floats) ----
  const x = 10.0;
  const y = 3.0;
  const fquot: number = x / y;
  console.log("float div:", fquot);

  // ---- Built-in: boolean ----
  const t = true;
  const f = false;
  const and: boolean = t && f;
  const or: boolean = t || f;
  const cmp: boolean = 3 < 5;
  console.log("boolean:", and, or, cmp);

  // ---- Built-in: string ----
  const s1 = "hello";
  const s2 = " world";
  const combined: string = s1 + s2; // + concatenates strings -> string
  console.log("string:", combined);

  // ---- null / undefined (absence of value) ----
  const n: null = null;
  let u: undefined = undefined;
  console.log("null:", n, "undefined:", u);

  // ---- Aggregate: interface ----
  const p: Point = { x: 1.0, y: 2.0 };
  const sumXY: number = p.x + p.y;
  console.log("Point:", p, "x+y:", sumXY);
}

main();
export { Point };
