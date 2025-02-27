#include <stdio.h>
#include <stdlib.h>

#include "myStringLib.h"

// [COPY AND PASTE] Copy and Paste your Lab 3 Q1 Solution Below

//  This is then your very first reusable custom C library 

int my_strlen(const char * const str1)
{
	int i = 0, sum = 0;
	while (str1[i] != '\0')
	{
		sum++;
		i++;
	}
	return sum;
}

int my_strcmp(const char * const str1, const char * const str2)
{
	// Checking lengths
	int length1 = 0, length2 = 0;
	for (int i = 0; str1[i] != '\0'; i++)
	{
		length1++;
	}
	for (int j = 0; str2[j] != '\0'; j++)
	{
		length2++;
	}
	if (length1 != length2)
	{
		return 0;
	}
	
	// Checking char by char
	for (int k = 0; str1[k] != '\0'; k++)
	{
		if (str1[k] != str2[k])
		{
			return 0;
		}
	}
	return 1;
}


int my_strcmpOrder(const char * const str1, const char * const str2)
{
	// Finding string lengths
	int length1 = 0, length2 = 0;
	for (int i = 0; str1[i] != '\0'; i++)
	{
		length1++;
	}
	for (int i = 0; str2[i] != '\0'; i++)
	{
		length2++;
	}

	if (length1 == length2) // If lengths are equal check this
	{
		for (int i = 0; str1[i] != '\0'; i++)
		{
			if (str1[i] > str2[i])
			{
				return 1;
			}
			else if (str1[i] < str2[i])
			{
				return 0;
			}
		}
		return -1;
	}
	else // If lengths are unequal check this
	{
		for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
		{
			if (str1[i] > str2[i])
			{
				return 1;
			}
			else if (str1[i] < str2[i])
			{
				return 0;
			}
		}
	}
}


char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL;
	
	// finding length of str1 and str2
	int len1 = 0, len2 = 0;
	while (str1[len1] != '\0')
	{
		len1++;
	}
	while (str2[len2] != '\0')
	{
		len2++;
	}

	/*write your implementation here*/
	z = (char*)malloc(len1 + len2 + 1);
	
	// writing str1 and str2 to z
	for (int i = 0; str1[i] != '\0'; i++)
	{
		z[i] = str1[i];
	}
	for (int i = 0; str2[i] != '\0'; i++)
	{
		z[i + len1] = str2[i];
	}

	// add null terminator at end
	z[len1 + len2] = '\0';

	return z;
}