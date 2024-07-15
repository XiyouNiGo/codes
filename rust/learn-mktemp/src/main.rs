fn main() -> Result<(), Box<dyn std::error::Error>> {
    let path = mktemp::Temp::new_path_in("./");
    println!("{:?}", path);
    for _ in 0..9 {
        let path = mktemp::Temp::new_path();
        println!("{:?}", path);
    }
    let file = mktemp::Temp::new_file_in("./")?;
    println!("{:?}", file);
    Ok(())
}
