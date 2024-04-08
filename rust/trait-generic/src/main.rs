trait Overview {
    fn overview(&self) -> String {
        String::from("Course")
    }
}

trait Another {
    fn hell(&self) {
        println!("welcome to hell");
    }
}

struct Course {
    headline: String,
    author: String,
}

impl Overview for Course {}
impl Another for Course {}

struct AnotherCourse {
    headline: String,
    author: String,
}

impl Overview for AnotherCourse {}

fn call_overview(item: &impl Overview) {
    println!("Overview {}", item.overview());
}

fn call_overview_generic<T: Overview>(item: &T) {
    println!("Overview {}", item.overview());
}

fn call_overviewT(item: &impl Overview, item1: &impl Overview) {
    println!("Overview {}", item.overview());
    println!("Overview {}", item1.overview());
}

fn call_overviewTT<T: Overview>(item: &T, item1: &T) {
    println!("Overview {}", item.overview());
    println!("Overview {}", item1.overview());
}
// 多绑定
fn call_mul_bind(item: &(impl Overview + Another)) {
    println!("Overview {}", item.overview());
    item.hell();
}

fn call_mul_bind_generic<T>(item: &T)
where
    T: Overview + Another,
{
    println!("Overview {}", item.overview());
    item.hell();
}

fn main() {
    let c0 = Course {
        headline: "ff".to_owned(),
        author: "yy".to_owned(),
    };
    let c1 = Course {
        headline: "ff".to_owned(),
        author: "yy".to_owned(),
    };

    let c2 = AnotherCourse {
        headline: "ff".to_owned(),
        author: "yz".to_owned(),
    };
    call_overview(&c1);
    call_overview_generic(&c1);
    call_overviewT(&c1, &c2);
    // println!("-------------------");
    call_overviewTT(&c1, &c0);
    call_overviewT(&c1, &c0);
    call_mul_bind(&c1);
    call_mul_bind_generic(&c1);
}
