fn move_func(p1: i32, p2: String) {
    println!("p1 is {}", p1);
    println!("p2 is {}", p2);
}

// borrow
fn print_value(value: &i32) {
    println!("{}", value);
}

fn string_func_borrow(s: &String) {
    println!("{}", (*s).to_uppercase());
}

#[derive(Debug)]
struct Point {
    x: i32,
    y: i32,
}

fn modify_point(point: &mut Point) {
    (*point).x += 2;
    point.y += 2;
}

fn main() {
    let n = 12;
    let s = String::from("oo");
    move_func(n, s);
    println!("n is {}", n);
    // println!("s is {}", s);
    let s = String::from("oo");
    print_value(&n);
    print_value(&n);
    string_func_borrow(&s);
    println!("s is {}", s);
    let mut p = Point { x: 0, y: 0 };
    println!("{:?}", p);
    modify_point(&mut p);
    println!("{:?}", p);
}
