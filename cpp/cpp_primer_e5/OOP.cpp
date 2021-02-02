#include <bits/stdc++.h>

using namespace std;

namespace ns1 {
  class Based {
   public:
	virtual void f ()
	{
	  cout << "Based #include <bits/stdc++.h>

using namespace std;

namespace ns1 {
  class Based {
   public:
	virtual void f ()
	{
	  cout << "Based : f()" << endl;
	}
  };
  
  class Derived final : public Based {
   public:
	//虚函数是隐含的
	/* virtual */ void f () override
	{
	  cout << "Derived : f()" << endl;
	}
  //  void F() override { }
  };
  
  //抽象基类
  class AbstractBased {
	//纯虚函数
	virtual void f () const = 0;
  };
}

namespace ns2 {
  class Base {
   public:
	virtual int fcn() {
	  cout << "Base : fcn()" << endl;
	}
  };

  class D1 : public Base {
   public:
	//隐藏而不是覆盖
	int fcn(int) {
	  cout << "D1 : fcn(int)" << endl;
	}

	virtual void f2() {
	  cout << "D1 : f2()" << endl;
	}
  };

  class D2 : public D1 {
   public:
	//隐藏
	int fcn(int) {
	  cout << "D2 : fcn(int)" << endl;
	}

	//覆盖
	int fcn() {
	  cout << "D2 : fcn()" << endl;
	}

	//覆盖
	void f2() {
	  cout << "D2 : f2()" << endl;
	}
  };
}

int main (int argc, char *argv[]) {
  {
	using namespace ns1;
	//保留符而非关键字
	int override, final;

	//只有通过基类引用或指针，才发生动态绑定
	Based b;
	Derived d;
	Based bd = d;
	b.f ();
	d.f ();
	bd.f ();

	Based &rb = b;
	Based &rd = d;
	b.f ();
	d.f ();

	Based *pb = &b;
	Based *pd = &d;
	b.f ();
	d.f ();

	//不能创建抽象基类的对象代码
	//  AbstractBased ab;
  }

  {
	using namespace ns2;

	Base b;
	D1 d1;
	D2 d2;
	Base *bpb = &b, *bpd1 = &d1, *bpd2 = &d2;

	//名字查找先于类型检查
	//从静态类型开始
	bpb->fcn();
	bpd1->fcn();
	bpd2->fcn();

	D1 *d1pd1 = &d1;
	D2 *d2pd2 = &d2;

	//从静态类型开始...
	//Base没有f2
//	bpd1->f2();
	d1pd1->f2();
	d2pd2->f2();
  }

  return 0;
}: f()" << endl;
	}
  };
  
  class Derived final : public Based {
   public:
	//虚函数是隐含的
	/* virtual */ void f () override
	{
	  cout << "Derived : f()" << endl;
	}
  //  void F() override { }
  };
  
  //抽象基类
  class AbstractBased {
	//纯虚函数
	virtual void f () const = 0;
  };
}

namespace ns2 {
  class Base {
   public:
	virtual int fcn() {
	  cout << "Base : fcn()" << endl;
	}
  };

  class D1 : public Base {
   public:
	//隐藏而不是覆盖
	int fcn(int) {
	  cout << "D1 : fcn(int)" << endl;
	}

	virtual void f2() {
	  cout << "D1 : f2()" << endl;
	}
  };

  class D2 : public D1 {
   public:
	//隐藏
	int fcn(int) {
	  cout << "D2 : fcn(int)" << endl;
	}

	//覆盖
	int fcn() {
	  cout << "D2 : fcn()" << endl;
	}

	//覆盖
	void f2() {
	  cout << "D2 : f2()" << endl;
	}
  };
}

int main (int argc, char *argv[]) {
  {
	using namespace ns1;
	//保留符而非关键字
	int override, final;

	//只有通过基类引用或指针，才发生动态绑定
	Based b;
	Derived d;
	Based bd = d;
	b.f ();
	d.f ();
	bd.f ();

	Based &rb = b;
	Based &rd = d;
	b.f ();
	d.f ();

	Based *pb = &b;
	Based *pd = &d;
	b.f ();
	d.f ();

	//不能创建抽象基类的对象代码
	//  AbstractBased ab;
  }

  {
	using namespace ns2;

	Base b;
	D1 d1;
	D2 d2;
	Base *bpb = &b, *bpd1 = &d1, *bpd2 = &d2;

	//名字查找先于类型检查
	//从静态类型开始
	bpb->fcn();
	bpd1->fcn();
	bpd2->fcn();

	D1 *d1pd1 = &d1;
	D2 *d2pd2 = &d2;

	//从静态类型开始...
	//Base没有f2
//	bpd1->f2();
	d1pd1->f2();
	d2pd2->f2();
  }

  return 0;
}
