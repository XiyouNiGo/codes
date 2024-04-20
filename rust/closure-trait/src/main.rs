fn apply_closure<F: Fn(i32, i32) -> i32>(closure: F, x: i32, y: i32) -> i32 {
    closure(x, y)
}

fn main() {
    let x = 5;
    let add_closure = |a, b| {
        println!("x is: {}", x);
        a + b + x
    };
    let result = apply_closure(add_closure, 5, 6);
    println!("{}", result);
}
