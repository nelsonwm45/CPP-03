#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
	- hiding/shadowing the base class if they have same member name
		- using this->_name will access only DiamondTrap's _name member
		- to access ClapTrap's name, use ClapTrap::_name
*/
class	DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string		_name; // hides ClapTrap::_name
	
	public:
	DiamondTrap(void);
	DiamondTrap(std::string p_name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap(void);

	using	ScavTrap::attack; // to specify using ScavTrap's attack
	void	whoAmI();
};


#endif