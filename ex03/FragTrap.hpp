#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

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

// changing to virtual inheritance so that one member is created instead of 2.
class	FragTrap: virtual public ClapTrap
{
	private:

	public:
	FragTrap(void);
	FragTrap(std::string p_name);

	FragTrap(const FragTrap &other);

	FragTrap &operator=(const FragTrap &other);

	~FragTrap(void);

	void	highFivesGuys(void);
};


#endif