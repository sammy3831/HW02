#include <iostream>

using namespace std;

class Animal
{
public:
	virtual void makeSound() = 0;
	virtual ~Animal();
};

Animal::~Animal()
{
}

class Dog : public Animal
{
	void makeSound() override
	{
		cout << "멍멍" << endl;
	}
};

class Cat : public Animal
{
	void makeSound() override
	{
		cout << "야옹야옹" << endl;
	}
};

class Cow : public Animal
{
	void makeSound() override
	{
		cout << "음메" << endl;
	}
};

class Zoo
{
private:
	Animal* animals[10];
	int addCount;

public:
	void addAnimal(Animal* animal)
	{
		int animalsLength = 10;

		if (addCount >= animalsLength)
		{
			cout << "자리가 없습니다" << endl;
		}

		for (int i = 0; i < animalsLength; i++)
		{
			if (animals[i] == nullptr)
			{
				animals[i] = animal;
				i = animalsLength;
				addCount++;
			}
		}
	}

	void performActions()
	{
		int animalsLength = 10;

		for (int i = 0; i < animalsLength; i++)
		{
			animals[i]->makeSound();
		}
	}

	~Zoo()
	{
		for (int i = 0; i < 10; i++)
		{
			delete animals[i];
			animals[i] = nullptr;
		}
	}
};

int main()
{
	Animal* pAnimalGroup[3]{};
	Dog dog{};
	Cat cat{};
	Cow cow{};

	pAnimalGroup[0] = &dog;
	pAnimalGroup[1] = &cat;
	pAnimalGroup[2] = &cow;

	for (int i = 0; i < 3; i++)
	{
		pAnimalGroup[i]->makeSound();
	}

	////////////////////////////////////////////////////////////

	Zoo zoo{};
	zoo.addAnimal(new Dog);
	zoo.addAnimal(new Cat);
	zoo.addAnimal(new Cow);
	zoo.addAnimal(new Dog);
	zoo.addAnimal(new Cat);
	zoo.addAnimal(new Cow);
	zoo.addAnimal(new Cat);
	zoo.addAnimal(new Cow);
	zoo.addAnimal(new Cat);
	zoo.addAnimal(new Cow);

	zoo.addAnimal(new Cat);
	zoo.addAnimal(new Dog);
	zoo.addAnimal(new Cow);
	zoo.addAnimal(new Dog);

	zoo.performActions();

}