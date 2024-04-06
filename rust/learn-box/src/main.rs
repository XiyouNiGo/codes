struct Point {
    x: i32,
    y: i32,
}

fn main() {
    let boxed_point = Box::new(Point { x: 10, y: 20 });
    println!("x:{}, y:{}", boxed_point.x, boxed_point.y);

    let mut boxed_point = Box::new(32);
    println!("{}", *boxed_point);
    *boxed_point += 10;
    println!("{}", *boxed_point);
}
