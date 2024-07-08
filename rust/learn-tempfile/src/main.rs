use std::fs::File;
use std::io::{Read, Seek, SeekFrom, Write};

fn main() {
    // Write
    let mut tmpfile: File =
        tempfile::tempfile_in("/Users/bytedance/codes/rust/learn-tempfile").unwrap();
    write!(tmpfile, "Hello World!").unwrap();

    // Seek to start
    tmpfile.seek(SeekFrom::Start(0)).unwrap();

    // Read
    let mut buf = String::new();
    tmpfile.read_to_string(&mut buf).unwrap();
    assert_eq!("Hello World!", buf);
}
