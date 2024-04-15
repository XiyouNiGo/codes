#[derive(Debug)]
struct Stack<T> {
    items: Vec<T>,
}

impl<T> Stack<T> {
    fn new() -> Self {
        Stack { items: Vec::new() }
    }
    // 入栈
    fn push(&mut self, item: T) {
        self.items.push(item);
    }
    // 出栈
    fn pop(&mut self) -> Option<T> {
        self.items.pop()
    }
    // 不可变引用
    fn iter(&self) -> std::slice::Iter<T> {
        self.items.iter()
    }
    fn iter_mut(&mut self) -> std::slice::IterMut<T> {
        self.items.iter_mut()
    }
    fn into_iter(self) -> std::vec::IntoIter<T> {
        self.items.into_iter()
    }
}

fn main() {
    let mut my_stack = Stack::new();
    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(3);

    for item in my_stack.iter() {
        println!("Item {}", item);
    }
    println!("{:?}", my_stack);

    for item in my_stack.iter_mut() {
        *item *= 2;
    }
    println!("{:?}", my_stack);
    for item in my_stack.into_iter() {
        println!("{}", item);
    }
    // println!("{:?}", my_stack);
}
