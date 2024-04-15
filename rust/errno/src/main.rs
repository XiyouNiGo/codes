use libc::{__errno_location, perror};
use nix::errno::Errno;
use std::ffi::CString;

fn main() {
    if Errno::EACCES as libc::c_int == libc::EACCES {
        println!("Errno::EACCES as libc::c_int == libc::EACCES");
    } else {
        println!("Errno::EACCES as libc::c_int != libc::EACCES")
    }

    let file_path = CString::new("/path/to/nonexistent/file").unwrap();
    let fd = unsafe { libc::open(file_path.as_ptr(), libc::O_RDONLY) };
    if fd == -1 {
        unsafe {
            perror(b"perror: open\0".as_ptr() as *const i8);
            println!("location {}", *__errno_location());
            let errno = Errno::last_raw();
            if errno == libc::ENOENT {
                println!("errno == libc::ENOENT");
            } else {
                println!("errno != libc::ENOENT");
            }
            println!("desc {}", Errno::E2BIG.desc());

            // segmentation fault
            let err_msg_cstr = CString::from_raw(libc::strerror(errno));
            println!("Error message: {:?}", err_msg_cstr);
        }
    }
}
