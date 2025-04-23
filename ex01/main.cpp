#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	attack_ptr_test(void)
{
	std::cout << YELLOW << "---------------POINTER ATTACK TEST----------------" << std::endl;
	ClapTrap	*ptr1;

	ptr1 = new ScavTrap; // calling default constructor to construct ScavTrap and assign to ptr
	ptr1->attack("Random"); // expect to print out Scav's attack, but it prints ClapTrap, runtime polymorphism is not working
	delete (ptr1);

	ScavTrap	*ptr2;
	ptr2 = new ScavTrap;
	ptr2->attack("Random");
	delete (ptr2);
}

void	guard_test(void)
{
	std::cout << YELLOW << "---------------GUARD GATE TEST----------------" << std::endl;
	ScavTrap	st1("Orange");

	st1.guardGate();
}

void	hp_test(void)
{
	std::cout << YELLOW << "-------------HP TEST----------------" << std::endl;
	ScavTrap	st1("Cicak");
	ScavTrap	st2("Spider");

	// st1.printStatus();
	// st2.printStatus();
	std::cout << YELLOW << "Adjusting HP for hp test" << std::endl;
	st1.setHitPts(0);
	st2.setHitPts(10);
	// st1.printStatus();
	// st2.printStatus();

	st1.attack("Spider");
	st2.attack("Cicak");
	st1.takeDamage(st2.getAttackDmg());
	// st2.takeDamage(st1.getAttackDmg());
	// st1.printStatus();
	// st2.printStatus();
	st1.beRepaired(10);
	st2.beRepaired(10);
	// st1.printStatus();
	// st2.printStatus();
}

void	energy_test(void)
{
	std::cout << YELLOW << "----------------ENERGY TEST---------------------" << std::endl;
	ScavTrap	st1("Cicak");
	ScavTrap	st2("Spider");

	// st1.printStatus();
	// st2.printStatus();
	std::cout << YELLOW << "Adjusting energy for energy test" << std::endl;
	st1.setEnergyPts(0);
	st2.setEnergyPts(10);
	// st1.printStatus();
	// st2.printStatus();

	st1.attack("Spider");
	st2.attack("Cicak");
	st1.takeDamage(st2.getAttackDmg());
	st2.takeDamage(st1.getAttackDmg());
	// st1.printStatus();
	// st2.printStatus();
	st1.beRepaired(10);
	st2.beRepaired(10);
	// st1.printStatus();
	// st2.printStatus();
}

void	dmg_test(void)
{
	std::cout << YELLOW << "--------------DMG TEST-------------" << RESET << std::endl;
	ScavTrap	st1("Cicak");
	ScavTrap	st2("Spider");

	// st1.printStatus();
	// st2.printStatus();
	std::cout << YELLOW << "Adjusting dmg for dmg test" << std::endl;
	st1.setAttackDmg(7);
	st2.setAttackDmg(2);
	st2.setAttackDmg(-1);
	// st1.printStatus();
	// st2.printStatus();

	st1.attack("Spider");
	st2.takeDamage(st1.getAttackDmg());
	st1.attack("Spider");
	st2.takeDamage(st1.getAttackDmg());
	st1.attack("Spider");
	st2.takeDamage(st1.getAttackDmg());
}

void	setter_overload_test(void)
{
	std::cout << YELLOW << "--------------SETTER TEST-------------" << RESET << std::endl;
	ScavTrap	st1("Cicak");
	ScavTrap	st2("Spider");

	// st1.printStatus();
	// st2.printStatus();
	std::cout << YELLOW << "Adjusting dmg for setter test" << std::endl;
	st1.setAttackDmg(123456);
	st2.setAttackDmg(-1);
	st2.setAttackDmg(2147483647);
	st2.setAttackDmg(3000000000U); // this will success
	st2.setAttackDmg(4294967295U);
	// st1.printStatus();
	// st2.printStatus();
}

void	ocf_test(void)
{
	std::cout << YELLOW << "--------------OCF TEST---------------" << RESET << std::endl;
	ScavTrap	st1; // default constructor
	ScavTrap	st2("Pikachu"); // string construstor 
	ScavTrap	st3(st2); // copy constructor
	ScavTrap	st4;

	st4 = st2; // copy assignment operator
	// st4.printStatus();
}

int	main(void)
{
	ocf_test();
	setter_overload_test();
	dmg_test();
	hp_test();
	energy_test();
	guard_test();
	attack_ptr_test();
}
