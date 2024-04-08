use std::ops::Add;

// 编译时
#[derive(Debug)]
struct Point<T> {
    x: T,
    y: T,
}

// T的这样类型 它可以执行相加的操作
impl<T> Add for Point<T>
where
    T: Add<Output = T>,
{
    type Output = Self;
    fn add(self, rhs: Self) -> Self::Output {
        Point {
            x: self.x + rhs.x,
            y: self.y + rhs.y,
        }
    }
}

fn main() {
    let i1 = Point { x: 1, y: 2 };
    let i2 = Point { x: 1, y: 3 };
    let sum = i1 + i2;
    println!("{:?}", sum);
    let f1 = Point { x: 1.0, y: 2.2 };
    let f2 = Point { x: 1.0, y: 3.0 };
    let sum = f1 + f2;
    println!("{:?}", sum);
}
