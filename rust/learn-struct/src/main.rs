// 不好的设计
struct MyString<'a> {
    text: &'a str, // String
}

impl<'a> MyString<'a> {
    fn get_length(&self) -> usize {
        self.text.len()
    }
    fn modify_data(&mut self) {
        self.text = "world";
    }
}

struct StringHolder {
    data: String,
}

impl StringHolder {
    fn get_length(&self) -> usize {
        self.data.len()
    }
    fn get_reference<'a>(&'a self) -> &'a String {
        &self.data
    }
    fn get_ref(&self) -> &String {
        &self.data
    }
}

fn main() {
    let str1 = String::from("value");
    let mut x = MyString {
        text: str1.as_str(),
    };
    x.modify_data();
    println!("{}", x.text);
    let holder = StringHolder {
        data: String::from("Hello"),
    };
    println!("{}", holder.get_reference());
    println!("{}", holder.get_ref());
}
