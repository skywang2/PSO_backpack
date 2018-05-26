#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//class Dog {
//	std::string name;
//	int weight;
//
//	Dog();
//
//	void setName(const std::string& dogsName);
//	void setWeight(int dogsWeight);
//
//	virtual void print() const;
//	//void bark() const { std::cout << name << " barks!\n" }
//	virtual ~Dog();
//};
//
//Dog::Dog()
//{
//	std::cout << "A dog has been constructed\n";
//}
//
//void Dog::print() const
//{
//	std::cout << "Dog is " << name << " and weighs " << weight << "kg\n";
//}



//int add(int x)
//{
//	return x + 1;
//}
//
//void main(void) {
//	//int add(int x);
//	int x1, x2;
//	int temp;
//	cin >> x1 >> x2;
//	//cin >> x2;
//	if (x1 < x2) 
//	{
//		cout << add(x1) << endl;
//	}
//	else 
//	{
//		cout << add(x2) << endl;
//	}
//
//
//	cin.get();
//	cin.get();
//	return;
//}



//const int Mm = 11;
//#define MM 12
//int main()
//{
//	int i = 1;
//	int &j = i;
//	int *h = &i;
//	cout << "i = " << i << endl;
//	cout << "h = " << h << endl;
//	cout << "j = " << j << endl;
//	cout << "i = " << i + 1 << endl;
//	i = i + 1;
//	cout << "j = " << j << endl;
//	cout << "h = " << h << endl;
//	cout << "&j = " << &j << endl;
//	cout << "&i = " << &i << endl;
//	cin.get();
//}

//#include"db.h"
//
//struct book{
//	char title[50];
//	char name[50];
//	int book_id;
//};
//
//void main() {
//	book mybook;
//
//	strcpy_s(mybook.title, "book1");
//	strcpy_s(mybook.name, "book of help");
//	mybook.book_id = 123;
//
//
//	cout << "书title : " << mybook.title << endl;
//	cout << "书name : " << mybook.name << endl;
//	cout << "书id : " << mybook.book_id << endl;
//
//	printbook_value(mybook);
//	cout << "书id : " << mybook.book_id << endl;
//	cin.get();
//}
//
//void printbook_add(struct book *books)
//{
//	//cout << "书title : " << books->title << endl;
//	//cout << "书name : " << books->name << endl;
//	//cout << "书id : " << books->book_id << endl;
//	books->book_id = 111111;
//}
//
//void printbook_value(struct book books)
//{
//	//cout << "书title : " << books.title << endl;
//	//cout << "书name : " << books.name << endl;
//	//cout << "书id : " << books.book_id << endl;
//	books.book_id = 22222;
//}

//class Box
//{
//public:
//
//	double getVolume(void)
//	{
//		return length * breadth * height;
//	}
//	void setLength(double len)
//	{
//		length = len;
//	}
//
//	void setBreadth(double bre)
//	{
//		breadth = bre;
//	}
//
//	void setHeight(double hei)
//	{
//		height = hei;
//	}
//	// 重载 + 运算符，用于把两个 Box 对象相加
//	Box operator+(const Box b)
//	{
//		Box box;
//		box.length = this->length + b.length;
//		box.breadth = this->breadth + b.breadth;
//		box.height = this->height + b.height;
//		return box;
//	}
//private:
//	double length;      // 长度
//	double breadth;     // 宽度
//	double height;      // 高度
//};
//
//int main()
//{
//	Box Box1;                // 声明 Box1，类型为 Box
//	Box Box2;                // 声明 Box2，类型为 Box
//	Box Box3;                // 声明 Box3，类型为 Box
//	double volume = 0.0;     // 把体积存储在该变量中
//
//	// Box1 详述
//	Box1.setLength(6.0);
//	Box1.setBreadth(7.0);
//	Box1.setHeight(5.0);
//
//	// Box2 详述
//	Box2.setLength(12.0);
//	Box2.setBreadth(13.0);
//	Box2.setHeight(10.0);
//
//	// Box1 的体积
//	volume = Box1.getVolume();
//	cout << "Volume of Box1 : " << volume << endl;
//
//	// Box2 的体积
//	volume = Box2.getVolume();
//	cout << "Volume of Box2 : " << volume << endl;
//
//	// 把两个对象相加，得到 Box3
//	Box3 = Box1 + Box2;
//
//	// Box3 的体积
//	volume = Box3.getVolume();
//	cout << "Volume of Box3 : " << volume << endl;
//
//	cin.get();
//	return 0;
////}
//
//#include <iostream> 
//using namespace std;
//
//class Shape {
//protected:
//	int width, height;
//public:
//	Shape(int a = 0, int b = 0)
//	{
//		width = a;
//		height = b;
//	}
//	virtual int area() = 0;
//	//{
//	//	cout << "Parent class area :" << endl;
//	//	return 0;
//	//}
//};
//class Rectangle : public Shape {
//public:
//	Rectangle(int a = 0, int b = 0) :Shape(a, b) { }
//	int area()
//	{
//		cout << "Rectangle class area :" << endl;
//		return (width * height);
//	}
//};
//class Triangle : public Shape {
//public:
//	Triangle(int a = 0, int b = 0) :Shape(a, b) { }
//	int area()
//	{
//		cout << "Triangle class area :" << endl;
//		return (width * height / 2);
//	}
//};
//// 程序的主函数
//int main()
//{
//	Shape *shape;
//	Rectangle rec(10, 7);
//	Triangle  tri(10, 5);
//
//	// 存储矩形的地址
//	shape = &rec;
//	// 调用矩形的求面积函数 area
//	shape->area();
//
//	// 存储三角形的地址
//	shape = &tri;
//	// 调用三角形的求面积函数 area
//	shape->area();
//
//	cin.get();
//	return 0;
//}

//struct book {
//	char name[50];
//	string title;
//	int id;
//};
//
//int main() {
//	book helloworld;
//	book *test_add;
//
//	helloworld.id = 14;
//	helloworld.title = "bbb";
//	strcpy(helloworld.name, "aaaa");
//
//	cout << helloworld.id << endl;
//	cout << helloworld.title.c_str << endl;
//	cout << helloworld.name << endl;
//	cout << "hello , wold" << endl;
//
//
//	return 0;
//}

//class Line {
//public:
//	int getLength(void);
//	Line(int len);             // 简单的构造函数
//	Line(const Line &obj);      // 拷贝构造函数
//	~Line();                     // 析构函数
//
//private:
//	int *ptr;
//
//};
//
//// 成员函数定义，包括构造函数
//Line::Line(int len)
//{
//	cout << "调用构造函数" << endl;
//	// 为指针分配内存
//	ptr = new int;
//	*ptr = len;
//}
//
//Line::Line(const Line &obj)
//{
//	cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
//	ptr = new int;
//	*ptr = *obj.ptr; // 拷贝值
//
//	cout << "ptr = " << ptr << endl;
//	cout << "sizeof(ptr) = " << sizeof(ptr) << endl;
//	cout << "*ptr = " << *ptr << endl;
//}
//
//Line::~Line(void)
//{
//	cout << "释放内存" << endl;
//	delete ptr;
//}
//int Line::getLength(void)
//{
//	return *ptr;
//}
//
//void display(Line obj)
//{
//	cout << "line 大小 : " << obj.getLength() << endl;
//}
//
//// 程序的主函数
//int main()
//{
//	Line line(10);
//
//	display(line);
//
//	cin.get();
//	return 0;
//}

class Animal {
	int num = 10;
	static int age;
public:
	Animal() {};
	virtual void eat() {
		cout << "动物在吃饭" << endl;
	}
	virtual void sleep() {
		cout << "动物在睡觉" << endl;
	}
	virtual void run();
};

int Animal::age = 20;

void Animal::run(){
	cout << "动物在跑" << endl;
}

class cat :public Animal {
	int num = 80;
	static int age;
public:
	cat() {};
	void eat() {
		cout << "猫在吃饭" << endl;
	}
	static void sleep() {
		cout << "猫在睡觉" << endl;
	}
	void run() {
		cout << "猫在跑" << endl;
	}
};

void main() {
	Animal *catA;
	cat cat1;

	catA = &cat1;


	catA->eat();
	catA->sleep();
	catA->run();

	cin.get();
}