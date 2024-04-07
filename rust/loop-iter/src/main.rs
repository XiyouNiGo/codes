fn main() {
    // loop {
    //     println!("Ctrl+C");
    //     std::thread::sleep(std::time::Duration::from_secs(1));
    // }
    let mut i = 0;
    while i < 10 {
        println!("{}", i);
        i += 1;
    }
    println!("for");
    let arr = [0, 1, 2, 3, 4, 5, 6, 7, 8];
    for element in arr {
        println!("{}", element);
    }
    for i in 0..10 {
        println!("{}", i);
    }
    for i in 0..=10 {
        println!("{}", i);
    }
    // break
    let arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11];
    for element in arr {
        if element == 10 {
            break;
        }
        println!("{element}");
    }
    let arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11];
    for element in arr {
        if element == 10 {
            continue;
        }
        println!("{element}");
    }
    'outer: loop {
        println!("outer");
        loop {
            println!("inner");
            // break;
            break 'outer;
        }
    }

    // 循环的写法
    let numbers = [1, 2, 3, 4, 5];
    let mut for_numbers = Vec::new();
    for &number in numbers.iter() {
        let item = number * number;
        for_numbers.push(item);
    }
    println!("for : {:?}", for_numbers);
    // 迭代的写法
    let numbers = [1, 2, 3, 4, 5].to_vec();
    let iter_number: Vec<_> = numbers.iter().map(|&x| x * x).collect();
    println!("iter : {:?}", iter_number);
}
