class Rect
{
	int x, y, w, h;

public:
	Rect(int a, int b, int c, int d)
		: x{a}, y{b}, w{c}, h{d} {}

	int getArea() { return w * h; }
	int getArea() const { return w * h; } // add const to fix
};

// void foo(Rect r)	   // call by value : very inefficient
void foo(const Rect &r)
{
	int n = r.getArea(); // ???
}

int main()
{
	Rect r(1, 1, 10, 10); // ?
	int n = r.getArea();  // ?

	foo(r); //
}
