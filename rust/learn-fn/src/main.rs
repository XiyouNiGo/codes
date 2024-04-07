fn add(x: i32, y: i32) -> i32 {
    x + y
}

fn change_i32(mut x: i32) {
    x = x + 4;
    println!("fn {x}");
}

fn modify_i32(x: &mut i32) {
    *x += 4;
}

#[derive(Copy, Clone)]
struct Point {
    x: i32,
    y: i32,
}

fn print_point(point: Point) {
    println!("point x {}", point.x);
}

fn main() {
    let a = 1;
    let b = 2;
    let c = add(a, b);
    println!("c: {c}");
    let mut x = 1;
    change_i32(x);
    println!("x {x}");
    modify_i32(&mut x);
    println!("x {x}");
    let s = Point { x: 1, y: 2 };
    print_point(s); // 所有权已经消失
    println!("{}", s.x);
}
