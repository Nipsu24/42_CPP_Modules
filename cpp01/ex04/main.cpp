/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:55 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/28 15:30:05 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

/*Prints out error message, in case argument amout given to program is not 3.*/
int	printInvalidArguments()
{
	std::cout << "Error. Insufficient arguments." << std::endl;
	std::cout << "Allowed argument amount is '3' in the following order:"<< std::endl;
	std::cout << "filename, string1, string2." << std::endl;
	std::cout << "string1 and string2 must be of the same length." << std::endl;
	return (1);
}

/*Opens file or returns error in case it cannot be opened or is empty.
  If file can be opened, reads its content and stores it in a string.*/
int	createSecondFile(char **av, std::string fileContent)
{
	std::string		s1 = av[2];
	std::string		s2 = av[3];

	std::ofstream myFileReplace("file1.replace");
	int j = fileContent.find(av[2], 0);
	if ((const size_t) j == std::string::npos)
	{
		std::cout << "String '" << av[2] << "' was not found in file1.replace." << std::endl;
		return (1);
	}
	for (size_t i = j, k = 0; i - j < s1.length(); i++, k++)
		fileContent[i] = s2[k];
	myFileReplace << fileContent;
	myFileReplace.close();
	return (0);
}

int	checkEqualArgumentLen(char **av)
{
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	
	if (s1.length() != s2.length())
		return (1);
	return (0);
}

std::string	getFileContent(char **av)
{
	std::ifstream	myFile;
	std::string		fileContent;

	myFile.open(av[1]);
	if (!myFile.is_open())
	{
		std::cout << "Error. File 1 could not be opened." << std::endl;
		return ("");
	}
	if (!std::getline(myFile, fileContent))
	{
		std::cout << "Error. File 1 is empty." << std::endl;
		return ("");
	}
	else
		myFile.close();
	return (fileContent);
}

int	main(int ac, char **av)
{
	std::string	fileContent;

	if (ac != 4)
		return (printInvalidArguments());
	if (checkEqualArgumentLen(av))
		return (printInvalidArguments());
	else
	{
		fileContent = getFileContent(av);
		if (fileContent.empty())
			return (1);
		if (createSecondFile(av, fileContent))
			return (1);
	}
	return (0);
}
