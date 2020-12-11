#pragma once
#include <string>

class Inventory
{

public:

	Inventory(std::string name, std:: string descriptoin, 
		int power = 0, int health = 0, int price = 0, int amount = 0);
	~Inventory();

	
	void DisplayName();
	void DisplayStats();

	void SetPower(int power);
	void SetHealth(int health);
	void SetPrice(int price);
	void SetAmount(int amount);
	void SetName(std::string name);
	void SetDescription(std::string description);

	void RedAmount(int ramount);

	void SetStats(std::string name, std::string description,
		int power, int health, int price);

	int GetAmount()
	{
		return m_amount;
	}
	int GetHealth()
	{
		return m_health;
	}
	int GetPower()
	{
		return m_attackpower;
	}


private:

	int m_attackpower;
	int m_health;
	int m_price;
	int m_amount;

	std::string m_name;
	std::string m_description;

};

