fn divide(a: i32, b: i32) -> Result<f64, String> {
    if b == 0 {
        return Err(String::from("cannot be zero"));
    }
    let a = a as f64;
    let b = b as f64;
    Ok(a / b)
}

fn find_element(array: &[i32], target: i32) -> Option<usize> {
    for (index, element) in array.iter().enumerate() {
        if (*element) == target {
            return Some(index);
        }
    }
    None
}

fn main() {
    // result
    match divide(1, 2) {
        Ok(number) => println!("{}", number),
        Err(err) => println!("{}", err),
    }

    match divide(1, 0) {
        Ok(number) => println!("{}", number),
        Err(err) => println!("{}", err),
    }

    // option
    let arr = [1, 2, 3, 4, 5];
    match find_element(&arr, 4) {
        Some(index) => println!("found in {}", index),
        None => println!("None"),
    }
    match find_element(&arr, 7) {
        Some(index) => println!("found in {}", index),
        None => println!("None"),
    }
    // panic
    let vec = vec![1, 2, 3, 4, 5];
    vec[43];
}
