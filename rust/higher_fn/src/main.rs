fn func_twice(f: fn(i32) -> i32, x: i32) -> i32 {
    f(f(x))
}

fn mul(x: i32) -> i32 {
    x * x
}

fn add(x: i32) -> i32 {
    x + 10
}

fn main() {
    let result = func_twice(mul, 4);
    println!("{result}");
    let res = func_twice(add, 10);
    println!("{res}");
    // 数学计算
    let numbers = vec![1, 2, 3, 4, 5, 6, 7];
    let res: Vec<_> = numbers.iter().map(|&x| x + x).collect();
    println!("{:?}", res);
    // filter
    let numbers = vec![1, 2, 3, 4, 5, 6, 7];
    // ref ref_mut move
    let evens = numbers
        .into_iter()
        .filter(|&x| x % 2 == 0)
        .collect::<Vec<_>>();
    println!("{:?}", evens);
    let numbers = vec![1, 2, 3, 4, 5, 6, 7];
    let sum = numbers.iter().fold(0, |acc, &x| acc + x);
    println!("Sum: {}", sum);
}
