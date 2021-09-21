#include <assert.h>
#include <leveldb/db.h>
#include <string.h>

#include <iostream>

int main(int argc, char** argv) {
  leveldb::DB* db;
  leveldb::Options options;

  options.create_if_missing = true;
  // Create database.
  leveldb::Status status = leveldb::DB::Open(options, "/tmp/my_leveldb", &db);
  assert(status.ok());

  std::string key = "key";
  std::string value = "value";

  // Add K-V
  status = db->Put(leveldb::WriteOptions(), key, value);
  assert(status.ok());

  // Get K-V
  status = db->Get(leveldb::ReadOptions(), key, &value);
  assert(status.ok());
  std::cout << value << std::endl;

  //  Delete K-V
  status = db->Delete(leveldb::WriteOptions(), key);
  return 0;
}