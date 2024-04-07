fn main() {
    let mut s = String::from("Hello");
    // 不可变引用，可以同时有多个不可变引用
    let r1 = &s;
    let r2 = &s;
    println!("{} {}", r1, r2);

    let r3 = &mut s;
    println!("{}", r3);
    // println!("{} {}", r1, r2);

    let result: &str;
    {
        // result = "ff";
        let r4 = &s;
        result = ff(r4);
    }
    // println!("r4 {}", r4);
    println!("{}", result);
}

fn ff<'a>(s: &'a str) -> &'a str {
    s
}
