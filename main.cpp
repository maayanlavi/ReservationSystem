#include <iostream>
#include <string>
#include <vector>

using namespace std;

class foodType {
public:
	foodType() {}
};

class ReservationSystem {
public:
	ReservationSystem(vector<foodType> allFood) : _AllFood(allFood) {}
private:
	vector<foodType> _AllFood;
	static ReservationSystem* ptr;
	
};


class ItalianFood : public foodType {
public:
	ItalianFood(): _name("Italian") {}

private:
	string _name;
};

class Pizza : public ItalianFood {
public:
	Pizza() {}
	virtual void preparepizza() = 0;
	virtual void servePizza() = 0;

};

class NewYorkPizza : public Pizza {
public:
	NewYorkPizza() {}
	virtual void preparepizza() {
		cout << "Your New-York pizza is in preparation" << endl;
	}
	virtual void servePizza() {
		cout << "Your pizza order summary:" << endl << "New-York pizza" << endl;
	}

};

class NapolitanaPizza : public Pizza {
public:
	NapolitanaPizza() { }
	virtual void preparepizza() {
		cout << "Your Napolitana pizza is in preparation" << endl;
	}
	virtual void servePizza() {
		cout << "Your pizza order summary:" << endl << "Napolitana pizza" << endl;
	}

};

class MargaritaPizza : public Pizza {
public:
	MargaritaPizza() { }
	virtual void preparepizza() {
		cout << "Your margarita pizza is in preparation" << endl;
	}
	virtual void servePizza() {
		cout << "Your pizza order summary:" << endl << "Margarita pizza" << endl;
	}

};

class Decorator : public Pizza {
public:
	Decorator(Pizza* pizza): _pizza(pizza) {}
	virtual void preparepizza() = 0;
	virtual void servePizza() = 0;

protected:
	Pizza* _pizza;
};

class PizzaWithTomato : public Decorator {
public:
	PizzaWithTomato(Pizza* pizza): Decorator(pizza) {}
	virtual void preparepizza() {
		cout << "OK, we've added tomatoes to your pizza!" << endl;
	}
	virtual void servePizza() {
		_pizza->servePizza();
		cout << "+Tomato" << endl;
	}

};

class PizzaWithBasel : public Decorator {
public:
	PizzaWithBasel(Pizza* pizza) : Decorator(pizza) {}
	virtual void preparepizza() {
		cout << "OK, we've added Basel to your pizza!" << endl;
	}
	virtual void servePizza() {
		_pizza->servePizza();
		cout << "+Basel" << endl;
	}

};

class PizzaWithMushrooms : public Decorator {
public:
	PizzaWithMushrooms(Pizza* pizza) : Decorator(pizza) {}
	virtual void preparepizza() {
		cout << "OK, we've added mushrooms to your pizza!" << endl;
	}
	virtual void servePizza() {
		_pizza->servePizza();
		cout << "+mushrooms" << endl;
	}

};

class PizzaWithCorn : public Decorator {
public:
	PizzaWithCorn(Pizza* pizza) : Decorator(pizza) {}
	virtual void preparepizza() {
		cout << "OK, we've added Corn to your pizza!" << endl;
	}
	virtual void servePizza() {
		_pizza->servePizza();
		cout << "+Corn" << endl;
	}

};


int main()
{
	vector<foodType> MyAllFood;
	ReservationSystem* MyRestaurant = new ReservationSystem(MyAllFood);
	cout << "WELCOME to MY Restaurant! choose your food type: press 1 for Italian Food" << endl;
	int res;
	int res2;
	int res3;
	int res4;
	cin >> res;
	if (res != 1)
		throw "only Italian Food is available";
	ItalianFood* it = new ItalianFood();
	cout << "choose your dish: press 1 for PIZZA" << endl;
	cin >> res2;
	if (res2 != 1)
		throw "only PIZZA is available";
	cout << "choose your Pizza Type:" << endl << "1 - New-York Pizza" << endl << "2- Napolitana Pizza" << endl << "3- Margarita Pizza" << endl;
	cin >> res3;
	Pizza* p=nullptr;
	switch (res3)
	{
	case 1:
		p = new NewYorkPizza();
		break;
	case 2:
		p = new NapolitanaPizza();
		break;
	case 3:
		p = new MargaritaPizza();
		break;
	}
	p->preparepizza();

	cout << "Would you like extra tomatoes?" << endl << " 1- yes" << endl << " 2-no" << endl;
	cin >> res4;
	if (res4 == 1) {
		p = new PizzaWithTomato(p);
		p->preparepizza();
	}

	cout << "Would you like extra Basel?" << endl << " 1- yes" << endl << " 2-no" << endl;
	cin >> res4;
	if (res4 == 1) {
		p = new PizzaWithBasel(p);
		p->preparepizza();
	}

	cout << "Would you like extra mushrooms?" << endl << " 1- yes" << endl << " 2-no" << endl;
	cin >> res4;
	if (res4 == 1) {
		p = new PizzaWithMushrooms(p);
		p->preparepizza();
	}

	cout << "Would you like extra corn?" << endl << " 1- yes" << endl << " 2-no" << endl;
	cin >> res4;
	if (res4 == 1) {
		p = new PizzaWithCorn(p);
		p->preparepizza();
	}




	p->servePizza();





}


