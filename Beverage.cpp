#include <iostream>
using namespace std;

class Beverage {
private:
	string* name;
public:
	void setName(string b) { name = new string(b); }
	string getName() { return *name; }
	Beverage() { name = new string("TBD"); }
	Beverage(string b):name(new string(b)){}
	virtual void output() = 0;
	virtual ~Beverage() {
		cout << "==> (Beverage) destructor was called." << endl;
		delete name;
	}
	Beverage(Beverage& b) {
		cout << "==> (Beverage) copy constructor was called." << endl;
		name = new string((b.getName()));
	}
	Beverage& operator=(Beverage& b) {
		cout << "==> (Beverage) assignment operator was called." << endl;
		name = new string(b.getName());
		return b;
	}
};

class Soda : public Beverage {
private:
	double* price;
public:
	void setPrice(double n) { price = new double(n); }
	double getPrice() { return *price; }
	Soda() :Beverage() { price = new double(0); }
	Soda(string n, double x) :Beverage(n) { price = new double(x); }
	void output() override {
		cout << "Name: " << getName() << " " << "Price: " << getPrice() << endl;
	}
	~Soda() {
		cout << "==> (Soda) destructor was called." << endl;
		delete price;
	}
	Soda(Soda& s) {
		cout << "==> (Soda) copy constructor was called." << endl;
	    price = new double(s.getPrice());
	}
	Soda& operator=(Soda& s) {
		cout << "==> (Soda) assignment operator was called." << endl;
		price = new double(s.getPrice());
		return s;
	}
};

class Beer : public Beverage {
private:
	double* alcohol_percentage;
public:
	void setPercentage(double x) { alcohol_percentage = new double(x); }
	double getPercentage() { return *alcohol_percentage; }
	Beer() :Beverage() { alcohol_percentage = new double(0); }
	Beer(string n, double x) :Beverage(n) {
		alcohol_percentage = new double(x);
	}
	void output() override {
		cout << "Name: " << getName() << ", " << "Alcohol Percentage: " << getPercentage() << endl;
	}
	~Beer() {
		cout << "==> (Beer) destructor was called." << endl;
		delete alcohol_percentage;
	}
	Beer(Beer& b) {
		cout << "==> (Beer) copy constructor was called." << endl;
		alcohol_percentage = new double(b.getPercentage());
	}
	Beer& operator=(Beer& b) {
		cout << "==> (Beer) assignment operator was called." << endl;
		alcohol_percentage = new double(b.getPercentage());
		return b;
	}
};

int main() {
	// part 1
	Beverage* p, * q;
	p = new Soda("Gatorade", 1.99);
	p->output(); // print "Name: Gatorade, Price: 1.99"
	q = new Beer("Budweiser", 3.6);
	q->output(); // print "Name: Budweiser, Alcohol Percentage: 3.6"
	// part 2
	delete p;
	/* print
	==> Soda destrcutor
	==> Beverage destructor
	*/
	delete q;
	/* print
	==> Beer destructor
	==> Beverage destructor
	*/
}