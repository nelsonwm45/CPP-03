// #include "ClapTrap.hpp"
// #include "ScavTrap.hpp"
// #include "FragTrap.hpp"
#include "DiamondTrap.hpp"


void	attack_ptr_test(void)
{
	std::cout << YELLOW << "---------------POINTER ATTACK TEST----------------" << std::endl;
	ClapTrap	*ptr1;

	ptr1 = new DiamondTrap; // calling default constructor to construct DiamondTrap and assign to ptr
	ptr1->attack("Random"); // expect to print out Scav's attack, but it prints ClapTrap, runtime polymorphism is not working
	delete (ptr1);

	DiamondTrap	*ptr2;
	ptr2 = new DiamondTrap;
	ptr2->attack("Random");
	delete (ptr2);
}

void	guard_gate_test(void)
{
	std::cout << YELLOW << "---------------GUARD GATE TEST----------------" << std::endl;
	DiamondTrap	dt1("Banana");

	dt1.guardGate();
}
void	highfive_test(void)
{
	std::cout << YELLOW << "---------------HIGH FIVES TEST----------------" << std::endl;
	DiamondTrap	dt1("Orange");

	dt1.highFivesGuys();
}

void	hp_test(void)
{
	std::cout << YELLOW << "-------------HP TEST----------------" << std::endl;
	DiamondTrap	dt1("Cicak");
	DiamondTrap	dt2("Spider");

	// dt1.printStatus();
	// dt2.printStatus();
	std::cout << YELLOW << "Adjusting HP for hp test" << std::endl;
	dt1.setHitPts(0);
	dt2.setHitPts(10);
	// dt1.printStatus();
	// dt2.printStatus();

	dt1.attack("Spider");
	dt2.attack("Cicak");
	dt1.takeDamage(dt2.getAttackDmg());
	// dt2.takeDamage(dt1.getAttackDmg());
	// dt1.printStatus();
	// dt2.printStatus();
	dt1.beRepaired(10);
	dt2.beRepaired(10);
	// dt1.printStatus();
	// dt2.printStatus();
}

void	energy_test(void)
{
	std::cout << YELLOW << "----------------ENERGY TEST---------------------" << std::endl;
	DiamondTrap	dt1("Cicak");
	DiamondTrap	dt2("Spider");

	// dt1.printStatus();
	// dt2.printStatus();
	std::cout << YELLOW << "Adjusting energy for energy test" << std::endl;
	dt1.setEnergyPts(0);
	dt2.setEnergyPts(10);
	// dt1.printStatus();
	// dt2.printStatus();

	dt1.attack("Spider");
	dt2.attack("Cicak");
	dt1.takeDamage(dt2.getAttackDmg());
	dt2.takeDamage(dt1.getAttackDmg());
	// dt1.printStatus();
	// dt2.printStatus();
	dt1.beRepaired(10);
	dt2.beRepaired(10);
	// dt1.printStatus();
	// dt2.printStatus();
}

void	dmg_test(void)
{
	std::cout << YELLOW << "--------------DMG TEST-------------" << RESET << std::endl;
	DiamondTrap	dt1("Cicak");
	DiamondTrap	dt2("Spider");

	dt1.attack("Spider");
	dt2.takeDamage(dt1.getAttackDmg());
	dt1.attack("Spider");
	dt2.takeDamage(dt1.getAttackDmg());
	dt1.attack("Spider");
	dt2.takeDamage(dt1.getAttackDmg());
	dt1.attack("Spider");
	dt2.takeDamage(dt1.getAttackDmg());
	dt1.attack("Spider");
	dt2.takeDamage(dt1.getAttackDmg());
}

void	setter_overload_test(void)
{
	std::cout << YELLOW << "--------------SETTER TEST-------------" << RESET << std::endl;
	DiamondTrap	dt1("Cicak");
	DiamondTrap	dt2("Spider");

	// dt1.printStatus();
	// dt2.printStatus();
	std::cout << YELLOW << "Adjusting dmg for setter test" << std::endl;
	dt1.setAttackDmg(123456);
	dt2.setAttackDmg(-1);
	dt2.setAttackDmg(2147483647);
	dt2.setAttackDmg(3000000000U);
	dt2.setAttackDmg(4294967295U);
	// dt1.printStatus();
	// dt2.printStatus();
}

void	ocf_test(void)
{
	std::cout << YELLOW << "--------------OCF TEST---------------" << RESET << std::endl;
	DiamondTrap	dt1; // default constructor
	DiamondTrap	dt2("Pikachu"); // string construstor 
	DiamondTrap	dt3(dt2); // copy constructor
	DiamondTrap	dt4;

	dt4 = dt2; // copy assignment operator
	dt1.whoAmI();
	dt1.printStatus();
	dt2.whoAmI();
	dt2.printStatus();
	dt3.whoAmI();
	dt3.printStatus();
	dt4.whoAmI();
	dt4.printStatus();
	// dt4.printStatus();
}

void	whoAmI_test(void)
{
	std::cout << YELLOW << "--------------WHOAMI TEST---------------" << RESET << std::endl;
	DiamondTrap	dt1("Mickey");

	dt1.whoAmI();
}

int	main(void)
{
	whoAmI_test();
	ocf_test();
	setter_overload_test();
	dmg_test();
	hp_test();
	energy_test();
	highfive_test();
	guard_gate_test();
	attack_ptr_test();
}
