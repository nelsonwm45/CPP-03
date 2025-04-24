#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <iostream>


# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

/*
	Diamond Problem:
	FragTrap and ScavTrap both inherit from ClapTrap. 
	If you now make DiamondTrap inherit from both FragTrap and ScavTrap, 
		you'll end up with two copies of ClapTrap members inside DiamondTrap.
	(ClapTrap part from ScavTrap) + (ClapTrap part from FragTrap)
		--> Both copies exist in memory --- lead to ---- ambiguity
		--> They don't know which one to choose

	virtual inheritance
	- to ensure only one shared base class instance is inherited in a multliple inheritance
	- The virtual base class (ClapTrap) is only constructed once
		by the most derived class (here, DiamondTrap).
	- So even if two base classes (ScavTrap & FragTrap) depend on it,
		only one shared version is made
	
	w/o virtual inheritance
		DiamondTrap
		|- ScavTrap
		|	|- ClapTrap  ❌ (copy 1)
		|- FragTrap
			|- ClapTrap  ❌ (copy 2)

	with virtual inheritance
		DiamondTrap
		|- ClapTrap  ✅ (one shared)
		|- ScavTrap
		|- FragTrap

*/
class	ScavTrap: virtual public ClapTrap
{
	private:

	public:
	ScavTrap(void);
	ScavTrap(std::string p_name);

	ScavTrap(const ScavTrap &other);

	ScavTrap &operator=(const ScavTrap &other);

	~ScavTrap(void);

	void	attack(const std::string& target);
	void	guardGate();
};


#endif