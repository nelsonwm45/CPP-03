#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	ct1("Weezing");
	ClapTrap	ct2;
	ClapTrap	ct3 = ct1;
	ClapTrap	ct4("Banana");
	ClapTrap	ct5(ct4);
	ClapTrap	ct6("Pineapple");
	
	ct2 = ct6;
	ct1.printStatus();
	ct4.printStatus();
	ct5.printStatus();
	ct1.setAttackDmg(5);
	ct1.attack("Banana");
	ct4.takeDamage(ct1.getAttackDmg());
	ct5.takeDamage(ct1.getAttackDmg());
	ct4.takeDamage(ct1.getAttackDmg());
	ct5.takeDamage(ct1.getAttackDmg());

	ct1.printStatus();
	ct4.printStatus();
	ct5.printStatus();
	ct1.beRepaired(2);
	ct4.beRepaired(2);
	ct5.beRepaired(2);
	ct1.printStatus();
	ct4.printStatus();
	ct5.printStatus();
}
