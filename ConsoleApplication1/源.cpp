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
//	cout << "��title : " << mybook.title << endl;
//	cout << "��name : " << mybook.name << endl;
//	cout << "��id : " << mybook.book_id << endl;
//
//	printbook_value(mybook);
//	cout << "��id : " << mybook.book_id << endl;
//	cin.get();
//}
//
//void printbook_add(struct book *books)
//{
//	//cout << "��title : " << books->title << endl;
//	//cout << "��name : " << books->name << endl;
//	//cout << "��id : " << books->book_id << endl;
//	books->book_id = 111111;
//}
//
//void printbook_value(struct book books)
//{
//	//cout << "��title : " << books.title << endl;
//	//cout << "��name : " << books.name << endl;
//	//cout << "��id : " << books.book_id << endl;
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
//	// ���� + ����������ڰ����� Box �������
//	Box operator+(const Box b)
//	{
//		Box box;
//		box.length = this->length + b.length;
//		box.breadth = this->breadth + b.breadth;
//		box.height = this->height + b.height;
//		return box;
//	}
//private:
//	double length;      // ����
//	double breadth;     // ���
//	double height;      // �߶�
//};
//
//int main()
//{
//	Box Box1;                // ���� Box1������Ϊ Box
//	Box Box2;                // ���� Box2������Ϊ Box
//	Box Box3;                // ���� Box3������Ϊ Box
//	double volume = 0.0;     // ������洢�ڸñ�����
//
//	// Box1 ����
//	Box1.setLength(6.0);
//	Box1.setBreadth(7.0);
//	Box1.setHeight(5.0);
//
//	// Box2 ����
//	Box2.setLength(12.0);
//	Box2.setBreadth(13.0);
//	Box2.setHeight(10.0);
//
//	// Box1 �����
//	volume = Box1.getVolume();
//	cout << "Volume of Box1 : " << volume << endl;
//
//	// Box2 �����
//	volume = Box2.getVolume();
//	cout << "Volume of Box2 : " << volume << endl;
//
//	// ������������ӣ��õ� Box3
//	Box3 = Box1 + Box2;
//
//	// Box3 �����
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
//// �����������
//int main()
//{
//	Shape *shape;
//	Rectangle rec(10, 7);
//	Triangle  tri(10, 5);
//
//	// �洢���εĵ�ַ
//	shape = &rec;
//	// ���þ��ε���������� area
//	shape->area();
//
//	// �洢�����εĵ�ַ
//	shape = &tri;
//	// ���������ε���������� area
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
//	Line(int len);             // �򵥵Ĺ��캯��
//	Line(const Line &obj);      // �������캯��
//	~Line();                     // ��������
//
//private:
//	int *ptr;
//
//};
//
//// ��Ա�������壬�������캯��
//Line::Line(int len)
//{
//	cout << "���ù��캯��" << endl;
//	// Ϊָ������ڴ�
//	ptr = new int;
//	*ptr = len;
//}
//
//Line::Line(const Line &obj)
//{
//	cout << "���ÿ������캯����Ϊָ�� ptr �����ڴ�" << endl;
//	ptr = new int;
//	*ptr = *obj.ptr; // ����ֵ
//
//	cout << "ptr = " << ptr << endl;
//	cout << "sizeof(ptr) = " << sizeof(ptr) << endl;
//	cout << "*ptr = " << *ptr << endl;
//}
//
//Line::~Line(void)
//{
//	cout << "�ͷ��ڴ�" << endl;
//	delete ptr;
//}
//int Line::getLength(void)
//{
//	return *ptr;
//}
//
//void display(Line obj)
//{
//	cout << "line ��С : " << obj.getLength() << endl;
//}
//
//// �����������
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
		cout << "�����ڳԷ�" << endl;
	}
	virtual void sleep() {
		cout << "������˯��" << endl;
	}
	virtual void run();
};

int Animal::age = 20;

void Animal::run(){
	cout << "��������" << endl;
}

class cat :public Animal {
	int num = 80;
	static int age;
public:
	cat() {};
	void eat() {
		cout << "è�ڳԷ�" << endl;
	}
	static void sleep() {
		cout << "è��˯��" << endl;
	}
	void run() {
		cout << "è����" << endl;
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