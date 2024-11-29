/*********************************TESTS****************************************/

/*********************************TESTS 1***************************************/
// #include <cstring>
// int	main(void)
// {
// 	int	ac = 4;
// 	char* av[4];
// 	av[0] = strdup("programName");
// 	av[1] = strdup("file1");
// 	av[2] = strdup("Hello");
// 	av[3] = strdup("World");
// 	std::cout << "Test Case 1: \n";
// 	std::cout << "3 args, s1: 'Hello', s2 'World'\n";

// 	std::string	fileContent;
	
// 	if (ac != 4 || checkForEmptyString(av))
// 	{
// 		for (int i = 0; i < 4; ++i) {free(av[i]);}
// 		return (printInvalidArguments());
// 	}
// 	else
// 	{
// 		fileContent = getFileContent(av);
// 		if (fileContent.empty())
// 		{
// 			for (int i = 0; i < 4; ++i) {free(av[i]);}
// 			return (1);
// 		}
// 		if (createSecondFile(av, fileContent))
// 		{
// 			for (int i = 0; i < 4; ++i) {free(av[i]);}
// 			return (1);
// 		}
//     }
// 	for (int i = 0; i < 4; ++i) {free(av[i]);}
// 	return (0);
// }

/*********************************TESTS 2***************************************/
// int	main(void)
// {
// 	int	ac = 2;
// 	char* av[2];
// 	av[0] = strdup("programName");
// 	av[1] = strdup("file1");
// 	std::cout << "Test Case 2: \n";
// 	std::cout << "1 arg\n";
	
// 	std::string	fileContent;
	
// 	if (ac != 4 || checkForEmptyString(av))
// 	{
// 		for (int i = 0; i < 2; ++i) {free(av[i]);}
// 		return (printInvalidArguments());
// 	}
// 	else
// 	{
// 		fileContent = getFileContent(av);
// 		if (fileContent.empty())
// 		{
// 			for (int i = 0; i < 2; ++i) {free(av[i]);}
// 			return (1);
// 		}
// 		if (createSecondFile(av, fileContent))
// 		{
// 			for (int i = 0; i < 2; ++i) {free(av[i]);}
// 			return (1);
// 		}
//     }
// 	for (int i = 0; i < 2; ++i) {free(av[i]);}
// 	return (0);
// }

/*********************************TESTS 3***************************************/
// int	main(void)
// {
// 	int	ac = 4;
// 	char* av[4];
// 	av[0] = strdup("programName");
// 	av[1] = strdup("file1");
// 	av[2] = strdup("Hello");
// 	av[3] = strdup("");
// 	std::cout << "Test Case 3: \n";
// 	std::cout << "3 args, s1: 'Hello', s2 empty\n";
	
// 	std::string	fileContent;
	
// 	if (ac != 4 || checkForEmptyString(av))
// 	{
// 		for (int i = 0; i < 2; ++i) {free(av[i]);}
// 		return (printInvalidArguments());
// 	}
// 	else
// 	{
// 		fileContent = getFileContent(av);
// 		if (fileContent.empty())
// 		{
// 			for (int i = 0; i < 2; ++i) {free(av[i]);}
// 			return (1);
// 		}
// 		if (createSecondFile(av, fileContent))
// 		{
// 			for (int i = 0; i < 2; ++i) {free(av[i]);}
// 			return (1);
// 		}
//     }
// 	for (int i = 0; i < 2; ++i) {free(av[i]);}
// 	return (0);
// }

/*********************************TESTS 4***************************************/
// int	main(void)
// {
// 	int	ac = 4;
// 	char* av[4];
// 	av[0] = strdup("programName");
// 	av[1] = strdup("file2");
// 	av[2] = strdup("Hello");
// 	av[3] = strdup("World");
// 	std::cout << "Test Case 3: \n";
// 	std::cout << "3 args, invalid file name, s1: 'Hello', s2 'World'\n";
	
// 	std::string	fileContent;
	
// 	if (ac != 4 || checkForEmptyString(av))
// 	{
// 		for (int i = 0; i < 2; ++i) {free(av[i]);}
// 		return (printInvalidArguments());
// 	}
// 	else
// 	{
// 		fileContent = getFileContent(av);
// 		if (fileContent.empty())
// 		{
// 			for (int i = 0; i < 2; ++i) {free(av[i]);}
// 			return (1);
// 		}
// 		if (createSecondFile(av, fileContent))
// 		{
// 			for (int i = 0; i < 2; ++i) {free(av[i]);}
// 			return (1);
// 		}
//     }
// 	for (int i = 0; i < 2; ++i) {free(av[i]);}
// 	return (0);
// }
