/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:35:17 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/22 15:39:12 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	Marvin("Marvin", 42);
	Bureaucrat	Jesus("Jesus", 3);
	std::cout << Marvin << Jesus;
	Intern	whoCares;
	{
		LOG("");
		try
		{
			AForm	*scf;
			scf = whoCares.makeForm("shrubbery creation", "here");
			if (!scf)
				throw AForm::VoidFormException();
			std::cout << *scf;
			Marvin.signForm(*scf);
			Marvin.executeForm(*scf);
			delete scf;
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Bureaucrat construction failed because " << e.what() << ".\n";
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Bureaucrat construction failed because " << e.what() << ".\n";
		}
		catch(AForm::VoidFormException& e)
		{
			std::cerr << e.what() << ".\n";
		}
	}
	std::cout << "\n----------------------------------------------------" << std::endl;
	{
		LOG("");
		try
		{
			AForm	*rrf;
			rrf = whoCares.makeForm("robotomy request", "Pencil");
			if (!rrf)
				throw AForm::VoidFormException();
			std::cout << *rrf;
			Marvin.signForm(*rrf);
			Marvin.executeForm(*rrf);
			Jesus.executeForm(*rrf);
			delete rrf;
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Bureaucrat construction failed because " << e.what() << ".\n";
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Bureaucrat construction failed because " << e.what() << ".\n";
		}
		catch(AForm::VoidFormException& e)
		{
			std::cerr << e.what() << ".\n";
		}
	}
	std::cout << "\n----------------------------------------------------" << std::endl;
	{
		LOG("");
		try
		{
			AForm	*ppd;
			ppd = whoCares.makeForm("presidential pardon", "Judas");
			if (!ppd)
				throw AForm::VoidFormException();
			std::cout << *ppd;
			Marvin.signForm(*ppd);
			Marvin.executeForm(*ppd);
			Jesus.signForm(*ppd);
			Jesus.executeForm(*ppd);
			delete ppd;
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Bureaucrat construction failed because " << e.what() << ".\n";
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Bureaucrat construction failed because " << e.what() << ".\n";
		}
		catch(AForm::VoidFormException& e)
		{
			std::cerr << e.what() << ".\n";
		}
	}
	std::cout << "\n----------------------------------------------------" << std::endl;
	{
		LOG("");
		try
		{
			AForm	*lol;
			lol = whoCares.makeForm("lolwat", "Nobody");
			if (!lol)
				throw AForm::VoidFormException();
			std::cout << *lol;
			Marvin.signForm(*lol);
			Marvin.executeForm(*lol);
			Jesus.signForm(*lol);
			Jesus.executeForm(*lol);
			delete lol;
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Bureaucrat construction failed because " << e.what() << ".\n";
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Bureaucrat construction failed because " << e.what() << ".\n";
		}
		catch(AForm::VoidFormException& e)
		{
			std::cerr << e.what() << ".\n";
		}
	}
	std::cout << "\n----------------------------------------------------" << std::endl;
}