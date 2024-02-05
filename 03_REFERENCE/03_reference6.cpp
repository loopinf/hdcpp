int main()
{
	int n = 0;

	n = 3;  //  n is lvalue
	// 3 = n;  // 3 is rvalue

	int& r1 = n;  // OK, 
	// int& r2 = 3;  // Error, 3 is rvalue
					  // int& : lvalue reference

	// C++11 rvalue reference
	// int&& r3 = n;  // Error, n is lvalue
	int&& r4 = 3;  // 

	// literal : rvalue
	// 3, 3.4, true, false, nullptr, 

	// Type&       : lvalue reference
	// const Type& : lvalue, rvalue reference
	// Type&&	   : rvalue reference
	// const Type&&: rvalue ONLY 

}