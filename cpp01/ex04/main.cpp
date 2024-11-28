/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:55 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/28 13:22:27 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

/*Prints out error message, in case argument amout given to program is not 3.*/
int	printInvalidArguments()
{
	std::cout << "Error. Insufficient argument amount." << std::endl;
	std::cout << "Allowed argument amount is '3' in the following order:"<< std::endl;
	std::cout << "filename, string1, string2." << std::endl;
	return (1);
}

std::ofstream	createSecondFile(char **av)
{
	std::ifstream	myFile;
	std::string		fileContent;

	myFile.open(av[1]);
	if(!myFile.is_open())
	{
		std::cout << "Error. File 1 could not be opened." << std::endl;
		return std::ofstream();
	}
	if (!std::getline(myFile, fileContent))
	{
		std::cout << "Error. File 1 is empty." << std::endl;
		return std::ofstream();
	}
	else
		myFile.close();
	std::cout << "File 1 Content: " << fileContent << std::endl;
	std::ofstream myFileReplace("file1.replace");
	myFileReplace << fileContent;
	myFileReplace.close();
	return (myFileReplace);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (printInvalidArguments());
	else
	{
		std::ofstream myFileReplace = createSecondFile(av);
		if (!myFileReplace)
			return (1);
	}
	return (0);
}
