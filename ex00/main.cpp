#include "ClapTrap.hpp"

void	hp_test(void)
{
	ClapTrap	ct1("Cicak");
	ClapTrap	ct2("Spider");

	std::cout << YELLOW << "-------------HP TEST----------------" << std::endl;
	// ct1.printStatus();
	// ct2.printStatus();
	std::cout << YELLOW << "Adjusting HP for hp test" << std::endl;
	ct1.setHitPts(0);
	ct2.setHitPts(10);
	// ct1.printStatus();
	// ct2.printStatus();

	ct1.attack("Spider");
	ct2.attack("Cicak");
	ct1.takeDamage(ct2.getAttackDmg());
	// ct2.takeDamage(ct1.getAttackDmg());
	// ct1.printStatus();
	// ct2.printStatus();
	ct1.beRepaired(10);
	ct2.beRepaired(10);
	// ct1.printStatus();
	// ct2.printStatus();
}

void	energy_test(void)
{
	ClapTrap	ct1("Cicak");
	ClapTrap	ct2("Spider");

	std::cout << YELLOW << "----------------ENERGY TEST---------------------" << std::endl;
	// ct1.printStatus();
	// ct2.printStatus();
	std::cout << YELLOW << "Adjusting energy for energy test" << std::endl;
	ct1.setEnergyPts(0);
	ct2.setEnergyPts(10);
	// ct1.printStatus();
	// ct2.printStatus();

	ct1.attack("Spider");
	ct2.attack("Cicak");
	ct1.takeDamage(ct2.getAttackDmg());
	ct2.takeDamage(ct1.getAttackDmg());
	// ct1.printStatus();
	// ct2.printStatus();
	ct1.beRepaired(10);
	ct2.beRepaired(10);
	// ct1.printStatus();
	// ct2.printStatus();
}

void	dmg_test(void)
{
	ClapTrap	ct1("Cicak");
	ClapTrap	ct2("Spider");

	std::cout << YELLOW << "--------------DMG TEST-------------" << RESET << std::endl;
	// ct1.printStatus();
	// ct2.printStatus();
	std::cout << YELLOW << "Adjusting dmg for dmg test" << std::endl;
	ct1.setAttackDmg(7);
	ct2.setAttackDmg(2);
	ct2.setAttackDmg(-1);
	// ct1.printStatus();
	// ct2.printStatus();

	ct1.attack("Spider");
	ct2.takeDamage(ct1.getAttackDmg());
	ct1.attack("Spider");
	ct2.takeDamage(ct1.getAttackDmg());
	ct1.attack("Spider");
	ct2.takeDamage(ct1.getAttackDmg());
}

void	setter_overload_test(void)
{
	ClapTrap	ct1("Cicak");
	ClapTrap	ct2("Spider");

	std::cout << YELLOW << "--------------SETTER TEST-------------" << RESET << std::endl;
	// ct1.printStatus();
	// ct2.printStatus();
	std::cout << YELLOW << "Adjusting dmg for setter test" << std::endl;
	ct1.setAttackDmg(123456);
	ct2.setAttackDmg(-1);
	ct2.setAttackDmg(2147483647);
	ct2.setAttackDmg(3000000000U);
	ct2.setAttackDmg(4294967295U);
	// ct1.printStatus();
	// ct2.printStatus();
}

void	ocf_test(void)
{
	std::cout << YELLOW << "--------------OCF TEST---------------" << RESET << std::endl;
	ClapTrap	ct1; // default constructor
	ClapTrap	ct2("Pikachu"); // string construstor 
	ClapTrap	ct3(ct2); // copy constructor
	ClapTrap	ct4;

	ct4 = ct2; // copy assignment operator
	ct4.printStatus();
}

int	main(void)
{
	ocf_test();
	setter_overload_test();
	dmg_test();
	hp_test();
	energy_test();
}
