static MY_STATIC: i32 = 42;
static mut MY_MUT_STATIC: i32 = 42;

fn main() {
    // const
    const SECOND_HOUR: usize = 3_600;
    const SECOND_DAY: usize = 24 * SECOND_HOUR; // compile-time constant

    {
        const SE: usize = 1_000;
        println!("{SE}");
    }

    // println!("{SE}");
    println!("{}", SECOND_DAY);
    // MY_STATIC = 2;
    println!("{MY_STATIC}");
    unsafe {
        MY_MUT_STATIC = 32;
        println!("{MY_MUT_STATIC}");
    }
    // println!("{MY_MUT_STATIC}");
}
