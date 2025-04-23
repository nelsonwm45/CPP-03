#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void	attack_ptr_test(void)
{
	std::cout << YELLOW << "---------------POINTER ATTACK TEST----------------" << std::endl;
	ClapTrap	*ptr1;

	ptr1 = new FragTrap; // calling default constructor to construct FragTrap and assign to ptr
	ptr1->attack("Random"); // expect to print out Scav's attack, but it prints ClapTrap, runtime polymorphism is not working
	delete (ptr1);

	FragTrap	*ptr2;
	ptr2 = new FragTrap;
	ptr2->attack("Random");
	delete (ptr2);
}

void	highfive_test(void)
{
	std::cout << YELLOW << "---------------HIGH FIVES TEST----------------" << std::endl;
	FragTrap	ft1("Orange");

	ft1.highFivesGuys();
}

void	hp_test(void)
{
	std::cout << YELLOW << "-------------HP TEST----------------" << std::endl;
	FragTrap	ft1("Cicak");
	FragTrap	ft2("Spider");

	// ft1.printStatus();
	// ft2.printStatus();
	std::cout << YELLOW << "Adjusting HP for hp test" << std::endl;
	ft1.setHitPts(0);
	ft2.setHitPts(10);
	// ft1.printStatus();
	// ft2.printStatus();

	ft1.attack("Spider");
	ft2.attack("Cicak");
	ft1.takeDamage(ft2.getAttackDmg());
	// ft2.takeDamage(ft1.getAttackDmg());
	// ft1.printStatus();
	// ft2.printStatus();
	ft1.beRepaired(10);
	ft2.beRepaired(10);
	// ft1.printStatus();
	// ft2.printStatus();
}

void	energy_test(void)
{
	std::cout << YELLOW << "----------------ENERGY TEST---------------------" << std::endl;
	FragTrap	ft1("Cicak");
	FragTrap	ft2("Spider");

	// ft1.printStatus();
	// ft2.printStatus();
	std::cout << YELLOW << "Adjusting energy for energy test" << std::endl;
	ft1.setEnergyPts(0);
	ft2.setEnergyPts(10);
	// ft1.printStatus();
	// ft2.printStatus();

	ft1.attack("Spider");
	ft2.attack("Cicak");
	ft1.takeDamage(ft2.getAttackDmg());
	ft2.takeDamage(ft1.getAttackDmg());
	// ft1.printStatus();
	// ft2.printStatus();
	ft1.beRepaired(10);
	ft2.beRepaired(10);
	// ft1.printStatus();
	// ft2.printStatus();
}

void	dmg_test(void)
{
	std::cout << YELLOW << "--------------DMG TEST-------------" << RESET << std::endl;
	FragTrap	ft1("Cicak");
	FragTrap	ft2("Spider");

	// ft1.printStatus();
	// ft2.printStatus();
	std::cout << YELLOW << "Adjusting dmg for dmg test" << std::endl;
	ft1.setAttackDmg(7);
	ft2.setAttackDmg(2);
	ft2.setAttackDmg(-1);
	// ft1.printStatus();
	// ft2.printStatus();

	ft1.attack("Spider");
	ft2.takeDamage(ft1.getAttackDmg());
	ft1.attack("Spider");
	ft2.takeDamage(ft1.getAttackDmg());
	ft1.attack("Spider");
	ft2.takeDamage(ft1.getAttackDmg());
}

void	setter_overload_test(void)
{
	std::cout << YELLOW << "--------------SETTER TEST-------------" << RESET << std::endl;
	FragTrap	ft1("Cicak");
	FragTrap	ft2("Spider");

	// ft1.printStatus();
	// ft2.printStatus();
	std::cout << YELLOW << "Adjusting dmg for setter test" << std::endl;
	ft1.setAttackDmg(123456);
	ft2.setAttackDmg(-1);
	ft2.setAttackDmg(2147483647);
	ft2.setAttackDmg(3000000000U);
	ft2.setAttackDmg(4294967295U);
	// ft1.printStatus();
	// ft2.printStatus();
}

void	ocf_test(void)
{
	std::cout << YELLOW << "--------------OCF TEST---------------" << RESET << std::endl;
	FragTrap	ft1; // default constructor
	FragTrap	ft2("Pikachu"); // string construstor 
	FragTrap	ft3(ft2); // copy constructor
	FragTrap	ft4;

	ft4 = ft2; // copy assignment operator
	// ft4.printStatus();
}

int	main(void)
{
	ocf_test();
	setter_overload_test();
	dmg_test();
	hp_test();
	energy_test();
	highfive_test();
	attack_ptr_test(); // not much difference
}
