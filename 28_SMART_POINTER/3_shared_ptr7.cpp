#include <iostream>
#include <memory>

void foo(void* p) { free(p); }

int main()
{
	// 삭제자 변경
	// std::shared_ptr<int>  sp1(new int); // ok, 소멸자가 delete 수행
	std::shared_ptr<int>  sp1(static_cast<int*>(malloc(sizeof(int)))); 
		// bug, 할당은 malloc인데, 소멸자는 delete임. 

	
	std::shared_ptr<int>  sp1(static_cast<int*>(malloc(sizeof(int))), foo); 
						// ok. 소멸자에서 delete 아닌 foo호출해달라.
	std::shared_ptr<int>  sp1(static_cast<int*>(malloc(sizeof(int))), free); 
	std::shared_ptr<int>  sp1(static_cast<int*>(malloc(sizeof(int))), 
								[](int*p){free(p);}); 

	// std::make_shared : 사용자가 직접 객체 생성이 아닌 make_shared내부에서 
	//						new 사용
	std::shared_ptr<int> sp4 = std::make_shared<int>();

	//  아래처럼 쓸수도 있지만 하지마라.
	std::shared_ptr<FILE> sp5(fopen("a.txt","wt"), fclose);

}