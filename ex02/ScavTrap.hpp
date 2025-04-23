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
	Parent/main/base class: ClapTrap
	Child/sub/derived class: ScavTrap

	class	ScavTrap: public ClapTrap
	--> modeling "is a" relationship: ScavTrap is a ClapTrap
	--> all public and protected members of ClapTrap remains public
		and protected in ScavTrap
	--> can use ScavTrap anywhere

	class	ScavTrap: private ClapTrap (or by default if not label)
	--> all public and protected members of ClapTrap become private in ScavTrap
	--> code outside ScavTrap won't be able to access ClapTrap's public method through
		a ScavTrap object
	--> for internal use only
*/
class	ScavTrap: public ClapTrap
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