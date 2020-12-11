#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "Player.h"
#include "Monster.h"
#include "Inventory.h"

//values
int command = 0;
int actualmonsterhealth = 0;
int actualplayerhealth = 0;

//system
void Intro();
void Start();
void Screen();
void FightScreen();

//Places
void Home();
void Field();
void Crossroads();
void Forest();
void RiverBank();
void PirateBay();
void Mountains();
void DragonsCastle();
void City();
void KingsCastle();
void Shop();
//Fighting mechanisms
void MonsterMeet();
void MonsterFightStat();
void MonsterFightGold();
void BossFight();
//function and variable for random number
int Random();
int randHundred = Random();



//Player stats
std::string playerName;
//attack/gold/health
Player player(500, 2000, 10000);

//Monster types/name/attack/health/gold
Monster troll("Angry Troll", 45, 180, 35);
Monster tiger("Furious Tiger",19, 100, 0);
Monster griffin("Loud Griffin",350, 1500, 80);
Monster pirate("Sticky Finger",420, 900, 50);
Monster elemental("Water Elemental",210, 800, 100);
Monster goblin("Tricky Goblin",70 , 500, 20);
Monster dragon("Murozond, the Black Dragon",450, 3000, 10000);

//a zero value monster to help solving the fights
Monster defaultMonster("", 0, 0, 0);


//items/name/description/attack/health/value/amountofN
Inventory sword("Deadly Sword", "[1] A very bloody sword", 100, 0, 300, 1);
Inventory helmet("Broken Helmet", "[2] Looks cool", 20, 350, 150, 1);
Inventory chest("Amazing chest", "[3] Fabuolus", 40, 550, 250, 1);
Inventory boots("Dirty Boots", "[4] At least confortable", 20, 300, 120, 1);
Inventory gloves("Warm Gloves", "[5] Great at cold times", 50, 220, 100, 1);
Inventory shoulders("Shiny Plate", "[6] Make you stronger", 40, 380, 200, 1);
Inventory flamereaper("Flamereaper", "Legendary weapon", 150, 100, 0, 1);

//skills
Inventory hpPotion("HP Potion", "restores health", 0, 500, 0, 5);
Inventory curse("Curse", "reduces enemies attack", -10, 0, 0, 1);

int main()
{
	Intro();

}
void Intro()
{
	//opening screen, asks the player name
	system("cls");
	std::cout << "#=============================================#\n" << std::endl;
	std::cout << "       Welcome to Exodar, adventurer!\n "         << std::endl;
	std::cout << "        Please, tell me your name!\n          "    << std::endl;
	std::cout << "#=============================================#"   << std::endl;
	std::cin >> playerName;

	player.SetName(playerName);//saves the players name

	
	system("cls");
	std::cout << "#=============================================#\n\n" << std::endl;
	std::cout << "         ";
	player.DisplayName();//prints out the players name
	std::cout << ", thats a cool name!\n\n" << std::endl;
	std::cout << "#=============================================#"     << std::endl;

	system("pause");
	Start();
}
void Start()
{	
	system("cls");
	//introduction for the game
	std::cout << "You are at home right now. Let me tell you everything about the game." << std::endl;
	std::cout << "This world is a magical place full with wonderful and ugly creatures." << std::endl;
	std::cout << "In this game you'll have to train yourself, explore new areas, fight with monsters" << std::endl;
	std::cout << "and in the end beat the powerful creature who keeps in terror every creature," << std::endl;
	std::cout << "Murozond the Black Dragon! First I recomend to go to the Crossroads to get informations." << std::endl;
	std::cout << "Pick up your potions! They are very powerful, but use them carefully, you can only use" << std::endl;
	std::cout << "5 under the game. Later on you'll be able to use curse magic. Okay, I think is enough to start." << std::endl;
	std::cout << "If we want to get to Crossroads, we have to pass the Arathi Highlands first!" << std::endl;
	system("pause");
	Home();
}
void Home()
{
	//introduction for the screen
	system("cls");
	Screen();
	std::cout << "This is your fighting screen, you can find all the important informations here!" << std::endl;
	std::cout << "If you are ready press [1] !" << std::endl;
	std::cin >> command;
	if (command == 1)
	{
		Field();
	}
	else
	{
		std::cout << "Oops.. Wrong command. Try again!" << std::endl;
		system("PAUSE");
		return Home();
	}
	return;
}
//all the different areas
void Field()
{
	//area for practise, you have 2 options, fight or go to the next place
	system("cls");
	Screen();
	std::cout << "You are in the fields. This is a great place to practise." << std::endl;
	std::cout << "[1]Fight with animals " << std::endl;
	std::cout << "[2]Go to Crossroads" << std::endl;
	std::cin >> command;
	if (command == 1)
	{
		defaultMonster = tiger;
		MonsterFightStat();

	}
	else if (command == 2)
	{
		Crossroads();
	}
	else
	{
		std::cout << "Oops.. Wrong command. Try again!" << std::endl;
		system("PAUSE");
		return Field();
	}
	return;
}
void Crossroads()
{
	//second area, multiple options to choose
	system("cls");
	Screen();
	std::cout << "You arrived to the Crossroads. I suggest you to speak with somebody." << std::endl;
	std::cout << "Let's find someone who has some quests for us. Careful with other areas!" << std::endl;
	std::cout << "[1] Forest" << std::endl;
	std::cout << "[2] River bank" << std::endl;
	std::cout << "[3] City" << std::endl;
	std::cout << "[4] Field" << std::endl;
	std::cout << "[5] Speak with the vendor" << std::endl;
	std::cin >> command;
	if (command == 1)
	{
		MonsterMeet();
		Forest();
	}
	else if (command == 2)
	{
		MonsterMeet();
		RiverBank();
	}
	else if (command == 3)
	{
		MonsterMeet();
		City();
	}
	else if (command == 4)
	{
		Field();
	}
	else if (command == 5)
	{
		if (player.GetHealth() == 100)//when players health at 100, prints out the text below
		{
			std::cout << "Hello there! My name is Kargath, I'm the vendor of this town." << std::endl;
			std::cout << "You Looking for adventures? Nooo my friend you are too weak for this cruel world." << std::endl;
			std::cout << "I suggest to go home and train yoursef, maybe the best way is to kill monsters in the fields." << std::endl;
			std::cout << "When your HP is below 200 come back and I'll give you some information." << std::endl;
			system("PAUSE");
			Crossroads();
		}
		else if(player.GetHealth() > 100 && player.GetHealth() < 200)
		{	//if players health between 100 and 200, prints out the text below
			std::cout << "Good to see you my friend, sorry but you are not strong enough, yet. As I said get 200 HP." << std::endl;
			std::cout << "I don't want you to send to death, train more and come back!" << std::endl;
			system("PAUSE");
			Crossroads();

		}
		else
		{
			//if players health is below 200, prints out the text below
			std::cout << "Heh long time no see, I can see you trained a lot! Okay my friend if you really want it" << std::endl;
			std::cout << "I tell you some information. People are saying the King is recruiting warriors to " << std::endl;
			std::cout << "beat the Black Dragon who's terrorizing the lands. Don't get exited, you still " << std::endl;
			std::cout << "have a lot to learn and you definitely need a gear. Go explore the other lands" << std::endl;
			std::cout << "collect gold by fighting monsters. One of my friend is an armorsmith in the City" << std::endl;
			std::cout << "I recomend you to go there, you'll find the best gear there!" << std::endl;
			std::cout << "That's all I can help my friend, good luck for your adventure!" << std::endl;
			system("PAUSE");
			Crossroads();
		}

	
	}
	else
	{
		std::cout << "Oops.. Wrong command. Try again!" << std::endl;
		system("PAUSE");
		return Crossroads();
	}
	return;
}
void RiverBank()
{
	system("cls");
	Screen();//4 options, 1 to fight, 3 to change location
	std::cout << "You arrived to the Starfall River. This magical place is very peaceful, but" << std::endl;
	std::cout << "be careful, the river is full with Elementals! Their attack power is around 200." << std::endl;
	std::cout << "[1] Fight with the elementals!" << std::endl;
	std::cout << "[2] Go to Booty Bay" << std::endl;
	std::cout << "[3] Go to the Crossroads" << std::endl;
	std::cout << "[4] Go to the Mountains" << std::endl;

	std::cin >> command;
	if (command == 1)
	{
		defaultMonster = elemental;
		MonsterFightGold();
	}
	else if (command == 2)
	{
		MonsterMeet();
		PirateBay();
	}
	else if (command == 3)
	{
		MonsterMeet();
		Crossroads();
	}
	else if (command == 4)
	{
		MonsterMeet();
		Mountains();
	}
	else
	{
		std::cout << "Oops.. Wrong command. Try again!" << std::endl;
		system("PAUSE");
		return RiverBank();
	}
	return;
}
void PirateBay()
{
	system("cls");
	Screen();//2 options, 1 to fight, 1 to change area
	std::cout << "You are in Booty Bay. This hidden  place is full with pirates. Be careful!" << std::endl;
	std::cout << "Don't even think to fight them without 1100 HP!" << std::endl;
	std::cout << "[1] Let's fight with the pirates!" << std::endl;
	std::cout << "[2] Go back to the river." << std::endl;
	std::cin >> command;
	if (command == 1)
	{
		defaultMonster = pirate;
		MonsterFightGold();
	}
	else if (command == 2)
	{
		MonsterMeet();
		RiverBank();
	}
	else
	{
		std::cout << "Oops.. Wrong command. Try again!" << std::endl;
		system("PAUSE");
		return PirateBay();
	}
	return;
}
void Mountains()
{
	system("cls");
	Screen();//4 options to choose, 1 to fight, 3 to change area
	std::cout << "You are in the mountains. This place is full of powerfull griffins." << std::endl;
	std::cout << "On the North you can find a beutifull river. I'm not recomend you to " << std::endl;
	std::cout << "to go there. That's the worlds most dangerous place the Dragon cave!" << std::endl;
	std::cout << "[1] Fight with griffins" << std::endl;
	std::cout << "[2] Go to the Dragons Cave" << std::endl;
	std::cout << "[3] Go to the River bank" << std::endl;
	std::cout << "[4] Go to the Forest" << std::endl;
	std::cin >> command;
	if (command == 1)
	{
		defaultMonster = griffin;
		MonsterFightGold();
	}
	else if (command == 2)
	{
		MonsterMeet();
		DragonsCastle();
	}
	else if (command == 3)
	{
		MonsterMeet();
		RiverBank();
	}
	else if (command == 4)
	{
		MonsterMeet();
		Forest();
	}
	else
	{
		std::cout << "Oops.. Wrong command. Try again!" << std::endl;
		system("PAUSE");
		return Mountains();
	}
	return;
}
void DragonsCastle()
{
	system("cls");
	Screen();//entrance to the final boss
	std::cout << "You are at the entrance of the Dragons Cave. Be careful!" << std::endl;
	std::cout << "[1] Enter to the cave" << std::endl;
	std::cout << "[2] Go back to the Mountains" << std::endl;
	std::cin >> command;
	if (command == 1)
	{	
		if (flamereaper.GetAmount() == 0)//only gives you acces if you have the legendary weapon
		{//if there's no more in stock that means you have it
			std::cout << "You entered the dragon cave." << std::endl;
			std::cout << "Strange noises echoes from the caves depth." << std::endl;

		}
		else
		{
			std::cout << "You don't have the King's permission and you are too weak to beat Murozond!" << std::endl;
			std::cout << "Don't come back without the Flamereaper!" << std::endl;
			system("pause");
			Mountains();
		}
	}
	else if (command == 2)
	{
		defaultMonster = griffin;
		MonsterMeet();//40% chance a griffin will attack you
		Mountains(); //goes to the Mountains
	}
	else
	{
		std::cout << "Oops.. Wrong command. Try again!" << std::endl;
		system("PAUSE");
		return DragonsCastle();
	}
	return;
}
void Forest()
{
	system("cls");
	Screen();//3 options,1 fight with trolls, 2 to change location
	std::cout << "You are in the Lunar Forest. This place is the home of trolls." << std::endl;
	std::cout << "I recomend to have at least 150 HP to fight them." << std::endl;
	std::cout << "[1] Fight with the trolls" << std::endl;
	std::cout << "[2] Go to the Mountains" << std::endl;
	std::cout << "[3] Go to the Crossroads" << std::endl;
	std::cin >> command;
	if (command == 1)
	{
		defaultMonster = troll;
		MonsterFightGold();//fight with trolls
	}
	else if (command == 2)
	{
		defaultMonster = griffin;
		MonsterMeet();//40% griffin attack
		Mountains();
	}
	else if (command == 3)
	{
		defaultMonster = goblin;
		MonsterMeet(); //40% goblin attack
		Crossroads();
	}
	else
	{
		std::cout << "Oops.. Wrong command. Try again!" << std::endl;
		system("PAUSE");
		return Forest();
	}
	return;
}
void City()
{
	system("cls");
	Screen();//3 options, 1 shop,2 to change location
	std::cout << "You are in Truesliver City. This is a peaceful place. You can find " << std::endl;
	std::cout << "the best shops here! The King lives in the middle of the city in the Great Castle." << std::endl;
	std::cout << "[1] Let's go to the shop" << std::endl;
	std::cout << "[2] Go to the Kings Castle" << std::endl;
	std::cout << "[3] Go to the Crossroads" << std::endl;
	std::cin >> command;
	if (command == 1)
	{
		Shop();
	}
	else if (command == 2)
	{
		KingsCastle();
	}
	else if (command == 3)
	{
		Crossroads();
	}
	else
	{
	std::cout << "Oops.. Wrong command. Try again!" << std::endl;
	system("PAUSE");
	return City();
	}
	return;
}
void Shop()
{
	system("cls");//displays the players gold and the items in the shop
	std::cout << "Gold: " << player.GetGold() << std::endl;
	std::cout << "Welcome to the shop! You can find the best gear here!" << std::endl;
	sword.DisplayName();
	sword.DisplayStats();
	std::cout << "============================" << std::endl;
	helmet.DisplayName();
	helmet.DisplayStats();
	std::cout << "============================" << std::endl;
	chest.DisplayName();
	chest.DisplayStats();
	std::cout << "============================" << std::endl;
	boots.DisplayName();
	boots.DisplayStats();
	std::cout << "============================" << std::endl;
	gloves.DisplayName();
	gloves.DisplayStats();
	std::cout << "============================" << std::endl;
	shoulders.DisplayName();
	shoulders.DisplayStats();
	std::cout << "============================" << std::endl;
	std::cout << "Buy the item by pressing its number:" << std::endl;
	std::cout << "Press [7] if you want to leave the shop:" << std::endl;
	std::cin >> command;//item numbers are visible in the displayStats
	if (command == 1)
	{

		if (sword.GetAmount() != 1)//allows only 1 purchase
		{
			std::cout << "You cannot buy more from this!" << std::endl;
			system("PAUSE");
			return Shop();
		}
		else if (player.GetGold() < 300)//checks the players gold
		{
			std::cout << "You don't have enough money! " << std::endl;
			system("PAUSE");
			return Shop();
		}
		else
		{//adds the items stats to the players,subtracts the gold and the amount of item
			player.SetPower(player.GetAttackPower() + 100);
			player.SetHealth(player.GetHealth() + 0);
			player.SetGold(player.GetGold() - 300);
			sword.SetAmount(sword.GetAmount() - 1);
			system("cls");
			Screen();
			std::cout << "You bought the Deadly Sword!" << std::endl;
			system("PAUSE");
			Shop();
		}
	}
	else if (command == 2)
	{

		if (helmet.GetAmount() != 1)//allows only 1 purchase
		{
			std::cout << "You cannot buy more from this!" << std::endl;
			system("PAUSE");
			return Shop();
		}
		else if (player.GetGold() < 150)//checks the players gold
		{
			std::cout << "You don't have enough money! " << std::endl;
			system("PAUSE");
			return Shop();
		}
		else//adds the items stats to the players,subtracts the gold and the amount of item
		{
			player.SetPower(player.GetAttackPower() + 20);
			player.SetHealth(player.GetHealth() + 80);
			player.SetGold(player.GetGold() - 150);
			helmet.SetAmount(helmet.GetAmount() - 1);

			system("cls");
			Screen();
			std::cout << "You bought the Broken Helmet!" << std::endl;
			system("PAUSE");
			Shop();
		}
	}
	else if (command == 3)
	{
		if (chest.GetAmount() != 1)//allows only 1 purchase
		{
			std::cout << "You cannot buy more from this!" << std::endl;
			system("PAUSE");
			return Shop();
		}
		else if (player.GetGold() < 250)//checks the players gold
		{
			std::cout << "You don't have enough money! " << std::endl;
			system("PAUSE");
			return Shop();
		}
		else//adds the items stats to the players,subtracts the gold and the amount of item
		{
			player.SetPower(player.GetAttackPower() + 40);
			player.SetHealth(player.GetHealth() + 150);
			player.SetGold(player.GetGold() - 250);
			chest.SetAmount(chest.GetAmount() - 1);

			system("cls");
			Screen();
			std::cout << "You bought the Amazing Chest!" << std::endl;
			system("PAUSE");
			Shop();
		}
	}
	else if (command == 4)
	{
		if (boots.GetAmount() != 1)//allows only 1 purchase
		{
			std::cout << "You cannot buy more from this!" << std::endl;
			system("PAUSE");
			return Shop();
		}
		else if (player.GetGold() < 120)//checks the players gold
		{
			std::cout << "You don't have enough money! " << std::endl;
			system("PAUSE");
			return Shop();
		}
		else//adds the items stats to the players,subtracts the gold and the amount of item
		{
			player.SetPower(player.GetAttackPower() + 20);
			player.SetHealth(player.GetHealth() + 90);
			player.SetGold(player.GetGold() - 120);
			boots.SetAmount(boots.GetAmount() - 1);

			system("cls");
			Screen();
			std::cout << "You bought the Dirty Boots!" << std::endl;
			system("PAUSE");
			Shop();
		}
	}
	else if (command == 5)
	{
		if (gloves.GetAmount() != 1)//allows only 1 purchase
		{
			std::cout << "You cannot buy more from this!" << std::endl;
			system("PAUSE");
			return Shop();
		}
		else if (player.GetGold() < 100)//checks the players gold
		{
			std::cout << "You don't have enough money! " << std::endl;
			system("PAUSE");
			return Shop();
		}
		else//adds the items stats to the players,subtracts the gold and the amount of item
		{
			player.SetPower(player.GetAttackPower() + 50);
			player.SetHealth(player.GetHealth() + 50);
			player.SetGold(player.GetGold() - 100);
			gloves.SetAmount(gloves.GetAmount() - 1);

			system("cls");
			Screen();
			std::cout << "You bought the Warm Gloves!" << std::endl;
			system("PAUSE");
			Shop();
		}
	}
	else if (command == 6)
	{
		if (shoulders.GetAmount() != 1)//allows only 1 purchase
		{
			std::cout << "You cannot buy more from this!" << std::endl;
			system("PAUSE");
			return Shop();
		}
		else if (player.GetGold() < 200)//checks the players gold
		{
			std::cout << "You don't have enough money! " << std::endl;
			system("PAUSE");
			return Shop();
		}
		else//adds the items stats to the players,subtracts the gold and the amount of item
		{
			player.SetPower(player.GetAttackPower() + 40);
			player.SetHealth(player.GetHealth() + 100);
			player.SetGold(player.GetGold() - 200);
			shoulders.SetAmount(shoulders.GetAmount() - 1);

			system("cls");
			Screen();
			std::cout << "You bought the Shiny Plate!" << std::endl;
			system("PAUSE");
			Shop();
		}
	}
	else if (command == 7)
	{
		City();//returns to the city
	}
	else
	{
		std::cout << "Oops.. Wrong command. Try again!" << std::endl;
		system("PAUSE");
		return Shop();;
	}
	system("PAUSE");
}
void KingsCastle()
{
	system("cls");
	Screen();//you can get the legendary weapon and acces to fight the black dragon
	std::cout << "You are in front of  the King's castle." << std::endl;
	std::cout << "[1] Go in to the castle, ask the king's blessing" << std::endl;
	std::cout << "[2] go bac to the City" << std::endl;
	std::cin >> command;
	if (command == 1)
	{
			std::cout << "You are standing in front of the King." << std::endl;

		if (flamereaper.GetAmount() == 1)//this loop allows only once to purchase the legendary weapon
		{
			//checks the players grear,if all out of stock it means the player has them
			if (sword.GetAmount() == 0 && helmet.GetAmount() == 0 && chest.GetAmount() == 0 &&
				gloves.GetAmount() == 0 && boots.GetAmount() == 0, shoulders.GetAmount() == 0)
			{
				std::cout << "King:" << std::endl;
				std::cout << "Many great warrior tried to defeat the Black Dragon, but the all failed." << std::endl;
				std::cout << "I can see your power level, I've never seen greater before!" << std::endl;
				std::cout << "Mighty Champion, you are worthy to face the Black Dragon!" << std::endl;
				std::cout << "I give you the legendary weapon, the Flamereaper! " << std::endl;
				std::cout << "Go " << playerName << ", set my people free from the Black Dragons terror!" << std::endl;
				system("PAUSE");
				//adds the legendary weapons stats
				player.SetPower(player.GetAttackPower() + 250);
				player.SetHealth(player.GetHealth() + 50);
				flamereaper.SetAmount(flamereaper.GetAmount() - 1);

				KingsCastle();
			}
			else
			{
				std::cout << "King:" << std::endl;
				std::cout << "You are not strong enough to swing the legendary sword and  face the" << std::endl;
				std::cout << "Black Dragon. I cannot put my people's destiny into your hands. Get out!!" << std::endl;
				system("PAUSE");
				KingsCastle();
			}
		}
		else
		{
			std::cout << "King:" << std::endl;
			std::cout << "Good to see you again " << playerName << "! How's the preparation?" << std::endl;
			std::cout << "I hope you face the dragon soon!" << std::endl;
			system("PAUSE");
			KingsCastle();
		}
	}
	else if (command == 2)
	{
		City();
	}
	else
	{
		std::cout << "Oops.. Wrong command. Try again!" << std::endl;
		system("PAUSE");
		return KingsCastle();
	}
	return;
}

//fighting mechanisms and 2 type of screens
//bugs to fix: unfortunately if the player presses a wrong key under a fight 
//all the actual values goes back to the maximum
void MonsterFightStat()
{	//fight mechanism, player gets stats after each fight until he reach 200 healt
	system("cls");
	Screen();
	actualmonsterhealth = defaultMonster.GetHealth();
	actualplayerhealth = player.GetHealth();

	std::cout << "You are fighting against a " << defaultMonster.GetName() << "! \n Choose!" << std::endl;
	while (actualplayerhealth > 0 && actualmonsterhealth > 0)//checks the caracters health
	{

		std::cout << "[1] Attack" << std::endl;
		std::cout << "[2] Use Health Potion [" << hpPotion.GetAmount() << "]" << std::endl;
		std::cin >> command;
		while (command != 1 && command != 2);
		{
			if (command == 1)
			{
				//attack, subtracks each characters attacks with each healts
				actualmonsterhealth = actualmonsterhealth - player.GetAttackPower();
				actualplayerhealth = actualplayerhealth - defaultMonster.GetAttackPower();
				system("cls");
				FightScreen();
				std::cout << "You dealt " << player.GetAttackPower() <<
					" dmg to the" << defaultMonster.GetName() << "!" << std::endl;

				std::cout << "The " << defaultMonster.GetName()
					<< " dealt " << defaultMonster.GetAttackPower() << " dmg to you!" << std::endl;

			}
			else if(command == 2)//health potion
			{
				if (hpPotion.GetAmount() > 0)//checks the nubmer of health potions
				{
					actualplayerhealth = actualplayerhealth + hpPotion.GetHealth() - defaultMonster.GetAttackPower();
					if (actualplayerhealth > player.GetHealth())//this function does not allow overhealing
					{
						actualplayerhealth = player.GetHealth();
					}
					hpPotion.RedAmount(1);//reduce the number of potions by 1
					system("cls");
					FightScreen();
					std::cout << "You healed " << hpPotion.GetHealth() << " Hp!" << std::endl;
					std::cout << "The " << defaultMonster.GetName() << " dealt "
						<< defaultMonster.GetAttackPower() << " dmg to you!" << std::endl;
					system("pause");
				}
				else
				{	//mesage if you ran out of potions
					actualplayerhealth = actualplayerhealth - defaultMonster.GetAttackPower();
					system("cls");
					FightScreen();
					std::cout << "You don't have potions!" << std::endl;
					std::cout << "The " << defaultMonster.GetName() << " dealt "
						<< defaultMonster.GetAttackPower() << " dmg to you!" << std::endl;
					system("pause");
				}

			}
			else
			{
				std::cout << "Oops.. Wrong command. Try again!" << std::endl;
				return MonsterFightStat();

			}


		}
	}
	//end of fight
	if (actualmonsterhealth <= 0 && actualplayerhealth > 0)//checks the fight
	{
		if (player.GetHealth() < 200)//checks is the player below 200 hp
		{
			player.AddHealth();//adds extra health
			player.AddAttack();//adds extra attack
			std::cout << "You killed the " << defaultMonster.GetName() << "!" << std::endl;
			std::cout << "You gained 5 attack and 10 health!" << std::endl;
			system("pause");
			defaultMonster.SetStats("", 0, 0, 0);
			Field();
		}
		else
		{
			std::cout << "You killed the " << defaultMonster.GetName() << "!" << std::endl;
			std::cout << "You got strong enough, you can't get more stats from" << defaultMonster.GetName() << std::endl;
			system("pause");
			defaultMonster.SetStats("", 0, 0, 0);
			Field();
		}
	}
	else
	{	//when you die you "respawn" at home
		std::cout << "You are defeated!\n Soldiers found you on the ground. They bring you home." << std::endl;
		system("pause");
		defaultMonster.SetStats("", 0, 0, 0);
		Home();
	}
	return;
}
void MonsterFightGold() 
{//fight mechanism, player gets gold after each fight , different mosnter different gold
	system("cls");
	Screen();
	actualmonsterhealth = defaultMonster.GetHealth();
	actualplayerhealth = player.GetHealth();

	std::cout << "You are fighting against a " << defaultMonster.GetName() << "! \n Choose!" << std::endl;
	while (actualplayerhealth > 0 && actualmonsterhealth > 0)//checks the caracters health
	{

		std::cout << "[1] Basic Attack" << std::endl;
		std::cout << "[2] Use Health Potion [" << hpPotion.GetAmount() << "]" << std::endl;
		std::cout << "[3] Curse Enemy[" << curse.GetAmount() << "]" << std::endl;
		std::cin >> command;

		if (command == 1)
		{
			//attack, subtracks each characters attacks with each healts
			actualmonsterhealth = actualmonsterhealth - player.GetAttackPower();
			actualplayerhealth = actualplayerhealth - defaultMonster.GetAttackPower();
			system("cls");
			FightScreen();
			std::cout << "You dealt " << player.GetAttackPower() <<
				" dmg to the" << defaultMonster.GetName() << "!" << std::endl;

			std::cout << "The " << defaultMonster.GetName()
				<< " dealt " << defaultMonster.GetAttackPower() << " dmg to you!" << std::endl;

		}
		else if (command == 2)
		{
			if (hpPotion.GetAmount() > 0)//checks the amount of potions
			{
				actualplayerhealth = actualplayerhealth + hpPotion.GetHealth() - defaultMonster.GetAttackPower();
				if (actualplayerhealth > player.GetHealth())//fixes the problem of overhealing
				{
					actualplayerhealth = player.GetHealth();
				}
				hpPotion.RedAmount(1);//reduces the number of potions
				system("cls");
				FightScreen();
				std::cout << "You healed " << hpPotion.GetHealth() << " Hp!" << std::endl;
				std::cout << "The " << defaultMonster.GetName() << " dealt "
					<< defaultMonster.GetAttackPower() << " dmg to you!" << std::endl;
				system("pause");
			}
			else
			{//this happens if you run out of potions but you try to use one
				actualplayerhealth = actualplayerhealth - defaultMonster.GetAttackPower();
				system("cls");
				FightScreen();
				std::cout << "You don't have potions!" << std::endl;
				std::cout << "The " << defaultMonster.GetName() << " dealt "
					<< defaultMonster.GetAttackPower() << " dmg to you!" << std::endl;
				system("pause");
			}
		}
		else if (command == 3)
		{	//spell, reduces the enemy attackpower, you can only use once each fight
			if (curse.GetAmount() == 1)
			{
				defaultMonster.RedPower(curse.GetPower());
				actualplayerhealth = actualplayerhealth - defaultMonster.GetAttackPower();
				curse.RedAmount(1);
				system("cls");
				FightScreen();
				std::cout << "You reduced the enemies attack by 10" << std::endl;
				std::cout << "The " << defaultMonster.GetName() << " dealt " << defaultMonster.GetAttackPower()
					<< "dmg to you!" << std::endl;
				system("pause");
			}
			else
			{//this happens if you try to use the curse in a fight multiple times
				actualplayerhealth = actualplayerhealth - defaultMonster.GetAttackPower();
				system("cls");
				FightScreen();
				std::cout << "You can use the curse only once each fight!" << std::endl;
				std::cout << "The " << defaultMonster.GetName() << " dealt " << defaultMonster.GetAttackPower()
					<< "dmg to you!" << std::endl;
				system("pause");
			}
			

		}
		else
		{
			
			std::cout << "Oops.. Wrong command. Try again!" << std::endl;
			return MonsterFightGold();

		}
		

	}

	if (actualmonsterhealth <= 0 && actualplayerhealth > 0)
	{	//this happens at a winning fight
		player.AddGold(defaultMonster.GetGold());//player gets gold
		std::cout << "You killed the " << defaultMonster.GetName() << "!" << std::endl;
		std::cout << "You earned " << defaultMonster.GetGold() << " gold!" << std::endl;
		system("pause");
		curse.SetAmount(1);// sets the curse back to one, the player will able to use it again in the next fight
		defaultMonster.SetStats("", 0, 0, 0);
		Crossroads();

	}
	else
	{	//when you die you "respawn" at home
		std::cout << "You are defeated!\n Soldiers find you on the ground. They bring you home." << std::endl;
		system("pause");
		curse.SetAmount(1);// sets the curse back to one, the player will able to use it again in the next fight
		defaultMonster.SetStats("", 0, 0, 0);
		Home();
	}
	
	return;
}
void MonsterMeet()//function for monster attack
{
	if (randHundred > 60)//40% chance the player will be attacked while changing locations
	{
		
		std::cout << "On your way a " << defaultMonster.GetName() << " attacked you! Make a decision!" << std::endl;
		std::cout << "[1]Fight" << std::endl;
		std::cout << "[2]Run" << std::endl;
		std::cin >> command;
		if (command == 1)
		{
			MonsterFightGold();
		}
		else if (command == 2)
		{
			player.AddGold(-50);//reduce players gold by 50
			if (player.GetGold() < 0)//doesn't allow to go negative value
			{
				player.SetGold(0);
			}
			std::cout << "You ran away! While you were running you lost 50 gold. " << std::endl;
			std::cout << "You arrived to the Crossroads" << std::endl;
			system("pause");
			Crossroads();
		}
		else
		{
			std::cout << "Oops.. Wrong command. Try again!" << std::endl;
			system("PAUSE");
			return MonsterMeet();
		}
	}
	else
	{
		return;
	}
}
void BossFight()
{
	system("cls");
	Screen();
	actualmonsterhealth = dragon.GetHealth();
	actualplayerhealth = player.GetHealth();

	std::cout << "You are fighting against the " << dragon.GetName() << "! \n Choose!" << std::endl;
	while (actualplayerhealth > 0 && actualmonsterhealth > 0)
	{

		std::cout << "[1] Basic Attack" << std::endl;
		std::cout << "[2] Use Health Potion" << std::endl;
		std::cout << "[3] Curse the dragon" << std::endl;
		std::cin >> command;

		if (command == 1)
		{
			defaultMonster = dragon;
			actualmonsterhealth = actualmonsterhealth - player.GetAttackPower();
			actualplayerhealth = actualplayerhealth - defaultMonster.GetAttackPower();
			system("cls");
			FightScreen();
			std::cout << "You dealt " << player.GetAttackPower() <<
				" dmg to the" << defaultMonster.GetName() << "!" << std::endl;

			std::cout << "The " << defaultMonster.GetName()
				<< " dealt " << defaultMonster.GetAttackPower() << " dmg to you!" << std::endl;

		}
		else if (command == 2)
		{
			if (hpPotion.GetAmount() > 0)
			{
				actualplayerhealth = actualplayerhealth + hpPotion.GetHealth() - defaultMonster.GetAttackPower();
				if (actualplayerhealth > player.GetHealth())
				{
					actualplayerhealth = player.GetHealth();
				}
				hpPotion.RedAmount(1);
				system("cls");
				FightScreen();
				std::cout << "You healed " << hpPotion.GetHealth() << " Hp!" << std::endl;
				std::cout << "The " << defaultMonster.GetName() << " dealt "
					<< defaultMonster.GetAttackPower() << " dmg to you!" << std::endl;
				system("pause");
			}
			else
			{
				actualplayerhealth = actualplayerhealth - defaultMonster.GetAttackPower();
				system("cls");
				FightScreen();
				std::cout << "You don't have potions!" << std::endl;
				std::cout << "The " << defaultMonster.GetName() << " dealt "
					<< defaultMonster.GetAttackPower() << " dmg to you!" << std::endl;
				system("pause");

			}
		}
		else if (command == 3)
		{
			if (curse.GetAmount() == 1)
			{
				curse.SetPower(-100);//the curse will be more powerful against the boss
				defaultMonster.RedPower(curse.GetPower());
				actualplayerhealth = actualplayerhealth - defaultMonster.GetAttackPower();
				curse.RedAmount(1);
				system("cls");
				FightScreen();
				std::cout << "You reduced the enemies attack by 10" << std::endl;
				std::cout << "The " << defaultMonster.GetName() << " dealt " << defaultMonster.GetAttackPower()
					<< "dmg to you!" << std::endl;
				system("pause");
			}
			else
			{
				actualplayerhealth = actualplayerhealth - defaultMonster.GetAttackPower();
				system("cls");
				FightScreen();
				std::cout << "You can use the curse only once each fight!" << std::endl;
				std::cout << "The " << defaultMonster.GetName() << " dealt " << defaultMonster.GetAttackPower()
					<< "dmg to you!" << std::endl;
				system("pause");
			}
		}
		else
		{
			system("cls");
			FightScreen();
			std::cout << "Oops.. Wrong command. Try again!" << std::endl;
			return BossFight();

		}


	}


	if (actualmonsterhealth <= 0 && actualplayerhealth > 0)
	{
		player.AddGold(dragon.GetGold());
		std::cout << "You killed the " << dragon.GetName() << "!" << std::endl;
		std::cout << "You saved the Kingdom!!!" << std::endl;
		std::cout << "Congratulations!! You win the game!!!" << std::endl;
		system("pause");

		return;
	}
	else
	{
		std::cout << "You are dead!\n You couldn't kill the Black Dragon..." << std::endl;
		std::cout << "The Kingdom is lost." << std::endl;
		std::cout << "The game is over..." << std::endl;
		system("pause");

		return;

	}

	return;
}
void Screen()
{
	//display all the stats, always shows the max value of each
	std::cout << "#===================================#"<< std::endl;
	std::cout << "     Player:"<< player.GetName() <<"\n"<<std::endl;
	std::cout << "     Health:" << player.GetHealth() <<  std::endl;
	std::cout << "     Attack:"<< player.GetAttackPower() <<std::endl;
	std::cout << "     Gold:" << player.GetGold() << std::endl;
	std::cout << "#===================================#"<< std::endl;
	std::cout << "     Monster:" << defaultMonster.GetName() << std::endl;
	std::cout << "     Health: " << defaultMonster.GetHealth() << std::endl;
	std::cout << "     Attack: " << defaultMonster.GetAttackPower() << std::endl;
	std::cout << "#===================================#"<< std::endl;
	return;
}
void FightScreen()
{
	//displays all the stats, flexible, tracks all the happenings in fights
	std::cout << "#===================================#" << std::endl;
	std::cout << "     Player:" << player.GetName() << "\n" << std::endl;
	std::cout << "     Health:" << actualplayerhealth << std::endl;
	std::cout << "     Attack:" << player.GetAttackPower() << std::endl;
	std::cout << "     Gold:" << player.GetGold() << std::endl;
	std::cout << "#===================================#" << std::endl;
	std::cout << "     Monster:" << defaultMonster.GetName() << std::endl;
	std::cout << "     Health: " << actualmonsterhealth << std::endl;
	std::cout << "     Attack: " << defaultMonster.GetAttackPower() << std::endl;
	std::cout << "#===================================#" << std::endl;
	return;
}

int Random()
{//random number generator
	srand(time(0));
	int I = rand() % 100;
	return rand() % 100;
}