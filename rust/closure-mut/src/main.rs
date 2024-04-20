fn main() {
    // Fn不可变引用获取外部参数
    let s1 = String::from("1111111111111111111");
    let s2 = String::from("2222222222222222222");
    let fn_func = |s| {
        println!("{s1}");
        println!("I am {s}");
        println!("{s1}");
    };
    fn_func("yz".to_owned());
    fn_func("原子".to_owned());
    println!("{s1} {s2}");

    // FnMut 可变引用获取外部参数
    let mut s1 = String::from("1111111111111111111");
    let mut s2 = String::from("2222222222222222222");
    let mut fn_func = |s| {
        s1.push_str("😀");
        s2.push_str("😀");
        println!("{s1}");
        println!("I am {s}");
        println!("{s1}");
    };
    fn_func("yz".to_owned());
    fn_func("原子".to_owned());
    println!("{s1} {s2}");
    // 所有权转移 由编译器根据我们的代码来判读
    let s1 = String::from("1111");
    let fn_Once_func = || {
        println!("{s1}");
        std::mem::drop(s1);
    };
    fn_Once_func();
    // println!("{s1}");
    let s1 = String::from("1111");
    // move：强制转移所有权
    let move_fn = move || {
        println!("{s1}");
    }; // Fn : FnMut : FnOnce
    move_fn();
    // println!("{s1}");
    let s1 = String::from("1111");
    std::thread::spawn(move || println!("d  {s1}"));
}
