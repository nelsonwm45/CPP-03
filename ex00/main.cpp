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


	ct1.setAttackDmg(5); // set the attack dmg of ct1 to 5
	ct1.attack("Banana"); // ct1 attack all banana claptrap
	ct4.takeDamage(ct1.getAttackDmg());
	ct5.takeDamage(ct1.getAttackDmg());
	ct4.takeDamage(ct1.getAttackDmg());
	ct5.takeDamage(ct1.getAttackDmg());

	ct1.printStatus();
	ct4.printStatus();
	ct5.printStatus();
	ct1.beRepaired(2); // can repair
	ct4.beRepaired(2); // should be cannot repair
	ct5.beRepaired(2); // cannot repair
	ct4.attack("Banana"); // cannot attack
	ct5.attack("Banana"); // cannot attack
	ct1.attack("Banana"); // can attack
	ct4.takeDamage(ct1.getAttackDmg()); // suppose ded and cannot take dmg
	ct5.takeDamage(ct1.getAttackDmg()); // suppose ded
	ct1.printStatus();
	ct4.printStatus();
	ct5.printStatus();
}
