#pragma once
#include <string>

class Monster
{

public:

	Monster(std::string name, int power = 0, int health = 0, int gold = 0);
	~Monster();

	
	void DisplayName();
	void DisplayStats();

	void SetPower(int power);
	void SetHealth(int health);
	void SetGold(int gold);
	void SetName(std::string name);
	void SetDescription(std::string description);
	void RedPower(int rpower);

	void SetStats(std::string name,
		int power, int health, int gold);

	std::string GetName()
	{
		return m_name;
	}
	std::string GetDescription()
	{
		return m_description;
	}
	int GetAttackPower()
	{
		return m_attackpower;
	}
	int GetHealth()
	{
		return m_health;
	}
	int GetGold()
	{
		return m_gold;
	}


private:

	int m_attackpower;
	int m_health;
	int m_gold;

	std::string m_name;
	std::string m_description;

};
