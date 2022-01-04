// 建造者模式

#include <bits/stdc++.h>

#include <utility>

class Product {
 public:
  Product() = default;
  ~Product() = default;

  void SetPart1(std::string part) { part1_ = std::move(part); }
  void SetPart2(std::string part) { part2_ = std::move(part); }
  void SetPart3(std::string part) { part3_ = std::move(part); }

  void Show() {
    assert(!part1_.empty() && !part2_.empty() && !part3_.empty());
    std::cout << "part1 = " << part1_ << " ,part2 = " << part2_
              << " ,part3 = " << part3_;
  }

 private:
  std::string part1_;
  std::string part2_;
  std::string part3_;
};

class Builder {
 public:
  Builder() = default;
  virtual ~Builder() = default;

  virtual void BuildPart1(std::string part) = 0;
  virtual void BuildPart2(std::string part) = 0;
  virtual void BuildPart3(std::string part) = 0;

  Product* GetProduct() { return product_; }

 protected:
  Product* product_ = new Product();
};

class ConcretBuilder : public Builder {
 public:
  ConcretBuilder() = default;

  ~ConcretBuilder() = default;

  void BuildPart1(std::string part) {
    std::cout << "ConcretBuilder: building part1" << std::endl;
    product_->SetPart1(part);
  }

  void BuildPart2(std::string part) {
    std::cout << "ConcretBuilder: building part2" << std::endl;
    product_->SetPart2(part);
  }
  void BuildPart3(std::string part) {
    std::cout << "ConcretBuilder: building part3" << std::endl;
    product_->SetPart3(part);
  }
};

class Director {
 public:
  Director(Builder* builder) : builder_(builder) {}

  ~Director() = default;

  Product* Construct() {
    std::cout << "Director: contructing product" << std::endl;
    builder_->BuildPart1("part1");
    builder_->BuildPart2("part2");
    builder_->BuildPart3("part3");
    return builder_->GetProduct();
  }

 private:
  Builder* builder_;
};

int main(int argc, char* argv[]) {
  Builder* builder = new ConcretBuilder();
  Director director(builder);
  Product* product = director.Construct();
  product->Show();
  return 0;
}