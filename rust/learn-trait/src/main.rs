trait Greeter {
    fn greet(&self);
    fn hello() {
        println!("hello");
    }
}

struct Person {
    name: String,
}

impl Greeter for Person {
    fn greet(&self) {
        println!("greet {}", self.name);
    }
}

fn main() {
    let person = Person {
        name: "Yz".to_owned(),
    };
    person.greet();
    Person::hello();
}
