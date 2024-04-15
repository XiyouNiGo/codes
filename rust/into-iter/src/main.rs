fn main() {
    // vec
    let v = vec![1, 2, 3, 4, 5]; // intoIterator 特质 into_iter
                                 // 转换为迭代器
    let iter = v.into_iter(); // move 所有权转移 类似ppt中的Iter Iterator的特质对象
    let sum: i32 = iter.sum();
    println!("sum: {}", sum);
    // println!("{:?}", v)
    // array
    let array = [1, 2, 3, 4, 5];
    let iter: std::slice::Iter<'_, i32> = array.iter();
    let sum: i32 = iter.sum();
    println!("sum: {}", sum);
    println!("{:?}", array);
    // chars
    let text = "hello, world!";
    let iter = text.chars();
    let uppercase = iter.map(|c| c.to_ascii_uppercase()).collect::<String>();
    println!("uppercase: {}", uppercase);
    println!("{:?}", text);
}
