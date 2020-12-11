#include "Player.h"
#include <iostream>

Player::Player(int power, int gold, int health)
{
	m_attackpower = power;
	m_gold = gold;
	m_health = health;
}

Player::~Player()
{
	std::cout << "You are dead." << std::endl;
}

void Player::DisplayName()
{
	std::cout << m_name;
}
void Player::DisplayStats()
{
	std::cout << "Attack power: " << m_attackpower << std::endl;
	std::cout << "Health bonus: " << m_health << std::endl;
	std::cout << "Gold: " << m_gold << std::endl;
}
void Player::SetPower(int power)
{
	m_attackpower = power;
}
void Player::SetHealth(int health)
{
	m_health = health;
}
void Player::SetGold(int gold)
{
	m_gold = gold;
}
void Player::SetName(std::string name)
{
	m_name = name;
}
void Player::AddGold(int gold)
{
	m_gold = m_gold + gold;
}


void Player::SetStats(std::string name,
	int power, int health, int gold)
{
	m_attackpower = power;
	m_health = health;
	m_gold = gold;
	m_name = name;
	
}
