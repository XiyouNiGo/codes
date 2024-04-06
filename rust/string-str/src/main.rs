struct Person<'a> {
    name: &'a str,
    color: String,
    age: i32,
}
// &String &str
fn print(data: &str) {
    println!("{}", data);
}

// 只能&String
fn print_string_borrow(data: &String) {
    println!("{}", data);
}

fn main() {
    // String &str
    let name = String::from("Value C++");
    // String::from
    // to_string()
    // to_owned()
    let course = "Rust".to_string();
    let new_name = name.replace("C++", "CPP");
    println!("{name} {course} {new_name}");
    let rust = "\x52\x75\x73\x74"; // ascii
    println!("{rust}");

    // String &str
    let color = "green".to_string();
    let name = "John";
    let people = Person {
        name: name,
        color: color,
        age: 89,
    };
    // func
    let value = "value".to_owned();
    print(&value);
    print("data");
    // print_string_borrow("dd");
    print_string_borrow(&value);
}
