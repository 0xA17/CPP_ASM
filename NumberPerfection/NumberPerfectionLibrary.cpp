#include "pch.h"
#include <utility>
#include <limits.h>
#include "NumberPerfectionLibrary.h"
#include "..//Menu2/Menu.h"
using namespace std;


int GetIntTmp(int number)
{
	int i, sum = 0;

	for (i = 1; i < number; i++)
	{
		if (number % i == 0)
		{
			sum = sum + i;
		}
	}

	if (number == sum)
	{
		return 1;
	}

	return 0;
}