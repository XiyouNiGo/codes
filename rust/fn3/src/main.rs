fn func_copy_back() -> i32 {
    let n = 42;
    n
}

fn func_non_copy_back() -> String {
    let s = String::from("hello");
    s
}

fn get_mess(mark: i32) -> &'static str {
    if mark == 0 {
        "😊😀"
    } else {
        "≧ ﹏ ≦😫"
    }
}

fn main() {
    let i = func_copy_back();
    println!("{}", i);
    let s = func_non_copy_back();
    println!("{}", s);
    println!("{}", get_mess(i));
}
