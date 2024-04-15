#[derive(Debug)]
struct User {
    name: String,
    score: u64,
}
// sort_by_key
// fn sort_score(users: &mut Vec<User>) {
//     users.sort_by_key(sort_helper);
// }

// fn sort_helper(u: &User) -> u64 {
//     u.score
// }
fn sort_score_closure(users: &mut Vec<User>) {
    users.sort_by_key(|u| u.score);
}

fn main() {
    let f = |a, b| a + b;
    println!("{}", f(1.0, 2.0));

    let a = User {
        name: "U1".to_owned(),
        score: 100,
    };
    let b = User {
        name: "U2".to_owned(),
        score: 80,
    };
    let c = User {
        name: "U3".to_owned(),
        score: 40,
    };
    let d = User {
        name: "U4".to_owned(),
        score: 90,
    };
    let mut users = vec![a, b, c, d];
    // sort_score(&mut users);
    sort_score_closure(&mut users);
    println!("{:?}", users);
}
