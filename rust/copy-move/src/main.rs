#[derive(Debug, Clone, Copy)]
struct Book {
    page: i32,
    rating: f64,
}

fn main() {
    let x = vec![1, 2, 3, 4];
    let y = x.clone();
    println!("{:?}", y);
    println!("{:?}", x);

    let x = "ss".to_string();
    let y = x.clone();
    println!("{:?}", x);

    let b1 = Book {
        page: 1,
        rating: 0.1,
    };
    let b2 = b1; // move
    println!("{:?}", b1);
}
