#include <chrono>
#include <iostream>
#include <semaphore>
#include <thread>

std::binary_semaphore smphSignalMainToThread(0), smphSignalThreadToMain(0);

void thread_proc() {
  smphSignalMainToThread.acquire();

  std::cout << "[thread] Got the signal\n";

  using namespace std::literals;
  std::this_thread::sleep_for(3s);

  std::cout << "[thread] Send the signal\n";  // message

  smphSignalThreadToMain.release();
}

int main() {
  std::thread worker(thread_proc);

  std::cout << "[main] Send the signal\n";

  /* p */
  smphSignalMainToThread.release();

  /* v */
  smphSignalThreadToMain.acquire();

  std::cout << "[main] Got the signal\n";
  worker.join();
}