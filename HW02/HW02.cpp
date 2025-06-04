#include <iostream>
#include <ctime>

using namespace std;

class Animal
{
public:
	virtual void makeSound() = 0;
	virtual void move() = 0;
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
	void move() override
	{
		cout << "개가 달린다" << endl;
	}
};

class Cat : public Animal
{
	void makeSound() override
	{
		cout << "야옹야옹" << endl;
	}
	void move() override
	{
		cout << "고양이가 달린다" << endl;
	}
};

class Cow : public Animal
{
	void makeSound() override
	{
		cout << "음메" << endl;
	}
	void move() override
	{
		cout << "소가 달린다" << endl;
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
			animals[i]->move();
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

Animal* createRandomAnimal()
{
	int random = rand() % 3;
	switch (random)
	{
	case 0:
		return new Dog;
	case 1:
		return new Cat;
	case 2:
		return new Cow;
	default:
		return nullptr;
	}
}

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
	srand(static_cast<unsigned int>(time(nullptr)));

	zoo.addAnimal(createRandomAnimal());
	zoo.addAnimal(createRandomAnimal());
	zoo.addAnimal(createRandomAnimal());
	zoo.addAnimal(createRandomAnimal());
	zoo.addAnimal(createRandomAnimal());
	zoo.addAnimal(createRandomAnimal());
	zoo.addAnimal(createRandomAnimal());
	zoo.addAnimal(createRandomAnimal());
	zoo.addAnimal(createRandomAnimal());
	zoo.addAnimal(createRandomAnimal());

	zoo.addAnimal(createRandomAnimal());
	zoo.addAnimal(createRandomAnimal());
	zoo.addAnimal(createRandomAnimal());
	zoo.addAnimal(createRandomAnimal());

	zoo.performActions();

}