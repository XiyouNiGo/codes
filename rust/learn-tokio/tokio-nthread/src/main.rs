use tokio;

fn main() {
    let rt = tokio::runtime::Builder::new_multi_thread()
        .worker_threads(8)
        .enable_io()
        .enable_time()
        .build()
        .unwrap();
    std::thread::sleep(std::time::Duration::from_secs(1000));
}
