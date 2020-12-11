#pragma once
#include <iostream>
#include <string>
#include "Inventory.h"

const int TOTAL_ITEMS = 6;

class Player
{

public:

	Player(int power = 0, int gold = 0, int health = 0);
	~Player();


	void DisplayName();
	void DisplayStats();

	void SetPower(int power);
	void SetHealth(int health);
	void SetGold(int gold);
	void AddGold(int gold);
	void SetName(std::string name);

	void SetStats(std::string name, int power, int health, int gold);

	void AddHealth()
	{
		m_health = m_health + 10;
	}
	void AddAttack()
	{
		m_attackpower = m_attackpower + 2;
	}

	std::string GetName()
	{
		return m_name;
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

};


