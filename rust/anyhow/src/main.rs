use anyhow::{Context, Result};

fn main() -> Result<()> {
    let path = "test.txt";
    // 能存储下原始错误
    let content =
        std::fs::read_to_string(path).with_context(|| format!("could not read file `{}`", path))?;
    println!("file content: {}", content);
    Ok(())
}
