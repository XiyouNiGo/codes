#[derive(Debug)]
struct Point<T> {
    x: T,
    y: T,
}

#[derive(Debug)]
struct PointTwo<T, E> {
    x: T,
    y: E,
}
fn main() {
    let c1 = Point { x: 1.0, y: 2.0 };
    let c2 = Point { x: 'x', y: 'y' };
    println!("c1 {:?} c2{:?}", c1, c2);
    let c = PointTwo { x: 1.0, y: 'z' };
    println!("{:?}", c);
    // Zero-Cost Abstraction
}
