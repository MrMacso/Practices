#include <iostream>
#include "Inventory.h"

Inventory::Inventory(std::string name, std::string description,
	int power, int health, int price, int amount)
{
	m_name = name;
	m_description = description;
	m_attackpower = power;
	m_health = health;
	m_price = price;
	m_amount = amount;
}

Inventory::~Inventory()
{
	std::cout << "Inventory item destroyed." << std::endl;
}

void Inventory::DisplayName()
{
	std::cout << "Name of item: " << m_name << std::endl;
	std::cout << "Desc of item: " << m_description << std::endl;
}
void Inventory::DisplayStats()
{
	std::cout << "Attack power: " << m_attackpower << std::endl;
	std::cout << "Health bonus: " << m_health << std::endl;
	std::cout << "Price: " << m_price << std::endl;
	std::cout << "In stock: " << m_amount << std::endl;
}

void Inventory::SetPower(int power)
{
	m_attackpower = power;
}
void Inventory::SetHealth(int health)
{
	m_health = health;
}
void Inventory::SetPrice(int price)
{
	m_price = price;
}
void Inventory::SetName(std::string name)
{
	m_name = name;
}
void Inventory::SetDescription(std::string description)
{
	m_description = description;
}
void Inventory::SetAmount(int amount)
{
	m_amount = amount;
}
void Inventory::RedAmount(int ramount)
{
	m_amount = m_amount - ramount;
}



void Inventory::SetStats(std::string name, std::string description,
	int power, int health, int price)
{
	m_attackpower = power;
	m_health = health;
	m_price = price;
	m_name = name;
	m_description = description;
}
