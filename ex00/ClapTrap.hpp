#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

# ifndef INT32_MAX
#  define INT32_MAX 2147483647
# endif 

# ifndef UINT32_MAX
#  define UINT32_MAX 4294967295U
# endif

class	ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hit_pts;
		unsigned int	_energy_pts;
		unsigned int	_attack_dmg;

	public:
		ClapTrap(void);
		ClapTrap(std::string p_name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);


		~ClapTrap(void);


		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	printStatus(void);

		// Setters
		/*
			Compiler will choose the function to fit based on following
			int → unsigned int → long → unsigned long → long long → unsigned long long
		*/
		void		setName(std::string p_name);
		void		setHitPts(int p_hit_pts);
		void		setHitPts(unsigned int p_hit_pts);
		void		setEnergyPts(int p_energy_pts);
		void		setEnergyPts(unsigned int p_energy_pts);
		void		setAttackDmg(int p_attack_dmg);
		void		setAttackDmg(unsigned int p_attack_dmg);


		// Getters
		std::string		getName() const;
		unsigned int	getHitPts() const;
		unsigned int	getEnergyPts() const;
		unsigned int	getAttackDmg() const;

};


#endif