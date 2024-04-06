use std::collections::btree_set::Union;

enum Color {
    Red,
    Yellow,
    Blue,
}

fn print_color(my_color: Color) {
    match my_color {
        Color::Red => println!("Red"),
        Color::Yellow => println!("Yellow"),
        Color::Blue => println!("Blue"),
    }
}

enum BuildingLocation {
    Number(i32),
    Name(String), // 不用&str
    Unknown,
}

impl BuildingLocation {
    fn print_location(&self) {
        match self {
            // BuildingLocation::Number(44)
            BuildingLocation::Number(c) => println!("building number {}", c),
            // BuildingLocation::Name("ok".to_string())
            BuildingLocation::Name(s) => println!("building name {}", *s),
            BuildingLocation::Unknown => println!("unknown"),
        }
    }
}

fn main() {
    let a = Color::Red;
    print_color(a);
    // let b = a;

    let house = BuildingLocation::Name("fdfd".to_string());
    let house = BuildingLocation::Number(1);
    let house = BuildingLocation::Unknown;
    house.print_location();
}
