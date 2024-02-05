void f1(int n) 		  { int a = n;}  // only read
void f2(const int& n) { int a = n;}  // only read

int main()
{
	int n = 10;
	f1(n);
	f2(n);
}


// not change the argument
// 1. primitive type(int, double, et etc) : call by value
//  void f1(int n)        : good
//  void f2(const int& n) : bad
// 2. struct, class : call by reference
//  void f2(std::string)
//  void f2(const std::string&)