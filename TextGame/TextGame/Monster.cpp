#include "Monster.h"
#include <iostream>

Monster::Monster(std::string name, int power, int health, int gold)
{	
	m_name = name;
	m_attackpower = power;
	m_health = health;
	m_gold = gold;
}

Monster::~Monster()
{
	std::cout << "Monster died." << std::endl;
}

void Monster::DisplayName()
{
	std::cout << "Name of monster: " << m_name << std::endl;
	std::cout << "Desc of mosnter: " << m_description << std::endl;
}

void Monster::DisplayStats()
{
	std::cout << "Attack power: " << m_attackpower << std::endl;
	std::cout << "Health bonus: " << m_health << std::endl;
	std::cout << "Loot: " << m_gold << std::endl;
}

void Monster::SetPower(int power)
{
	m_attackpower = power;
}

void Monster::SetHealth(int health)
{
	m_health = health;
}


void Monster::SetGold(int gold)
{
	m_gold = gold;
}

void Monster::SetName(std::string name)
{
	m_name = name;
}

void Monster::SetDescription(std::string description)
{
	m_description = description;
}

void Monster::RedPower(int rpower)
{
	m_attackpower = m_attackpower - rpower;
}

void Monster::SetStats(std::string name,
	int power, int health, int gold)
{
	m_attackpower = power;
	m_health = health;
	m_gold = gold;
	m_name = name;
}
