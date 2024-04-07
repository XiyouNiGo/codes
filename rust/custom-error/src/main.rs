#[derive(Debug)]
struct MyError {
    detail: String,
}

impl std::fmt::Display for MyError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "Custom Error: {}", self.detail)
    }
}

impl std::error::Error for MyError {
    fn description(&self) -> &str {
        &self.detail
    }
    // &String => &str
}

fn func() -> Result<(), MyError> {
    Err(MyError {
        detail: "CustomError".to_owned(),
    })
    // Ok(())
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    match func() {
        Ok(_) => println!("func ok"),
        Err(err) => println!("Error: {}", err),
    }
    func()?;
    println!("oo");
    Ok(())
}
