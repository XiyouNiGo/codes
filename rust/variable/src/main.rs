fn main() {
    // 不可变与命名
    let _nice_count = 100; // 自动推导i32
    let _nice_number: i64 = 54;
    // nice_count = 23;
    // 声明可变
    let mut _count = 3;
    _count = 4;
    // Shadowing
    let x = 5;
    {
        // 命名空间
        let x = 10;
        println!("inner x : {}", x);
    } // 内部的x被销毁了
    println!("Outer x: {x}");
    let x = "hello"; // 在同一作用域下重新声明了x，最终覆盖了之前的x
    println!("New x : {x}");
    // x = "hello";
    let mut x = "this";
    println!("x: {x}");
    x = "that";
    println!("Mut x: {x}");
    // 可以重定义类型 可变性
}
