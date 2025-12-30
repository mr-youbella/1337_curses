#include "Bureaucrat.hpp"

int	main(void)
{
	try 
	{
		Bureaucrat	bureaucrat("Youbella", 1);
		int			grade = bureaucrat.getGrade();
		std::cout << "Name bureaucrat is " << bureaucrat.getName() << " his grade is " << grade << '\n';
		try
		{
			bureaucrat.decrementGrade();
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

}
