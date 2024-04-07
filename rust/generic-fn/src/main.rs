// 交换
fn swap<T>(a: T, b: T) -> (T, T) {
    (b, a)
}

struct Point<T> {
    x: T,
    y: T,
}

impl<T> Point<T> {
    fn new(x: T, y: T) -> Self {
        Point { x, y }
    }
    // 方法
    fn get_coordinates(&self) -> (&T, &T) {
        (&self.x, &self.y)
    }
}

fn main() {
    let result = swap::<f64>(0.1, 1.0);
    let result: (f64, f64) = swap(0.1, 1.0);
    println!("{:?}", result);
    let str2 = swap("hh", "tt");
    println!("str2.0 {} str2.1 {}", str2.0, str2.1);
    let str2 = swap(str2.0, str2.1);
    println!("str2.0 {} str2.1 {}", str2.0, str2.1);

    let i32_point = Point::new(2, 3);
    let f64_point = Point::new(2.0, 3.0);
    let (x1, y1) = i32_point.get_coordinates();
    let (x2, y2) = f64_point.get_coordinates();
    println!("i32 point: x= {} y= {}", x1, y1);
    println!("f64 point: x= {} y= {}", x2, y2);
    // String 不要用&str
    let string_point = Point::new("xxx", "yyyy");
    println!("string point x = {} y = {}", string_point.x, string_point.y);
}
