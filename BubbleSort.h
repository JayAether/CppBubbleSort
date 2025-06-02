#include <iostream>
#include <array>

template<std::size_t SIZE>
bool arrayIsSorted(const std::array<int, SIZE>& arr);

template<std::size_t SIZE>
void printArray(std::array<int, SIZE>& arr);

template<std::size_t SIZE>
void bubbleSort(std::array<int, SIZE>& arr)
{
	std::array<int, SIZE> ogCpy = arr;


	while (!arrayIsSorted(arr))
	{
		printArray(arr);

		std::array<int, SIZE> tmpCpy = arr;
		for (int i = 0; i < (arr.size() - 1); i++)
		{
			// break if the next step doesnt exist
			//if (i == arr.end())
			//{
			//	break;
			//} //actualy i may be dum, this prob isnt needed

			if (arr.at(i) > arr.at(i + 1))
			{
				int current = arr.at(i);
				int next = arr.at(i + 1);
				
				arr.at(i) = next;
				arr.at(i + 1) = current;
			}
		}
	}
}

template<std::size_t SIZE>
bool arrayIsSorted(const std::array<int, SIZE>& arr)
{
	int lastValue = arr.at(0);
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr.at(i) < lastValue)
		{
			return false;
		}
		lastValue = arr.at(i);
	}
	
	return true;
}

template<std::size_t SIZE>
void printArray(std::array<int, SIZE>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr.at(i) << ' ';
	}
	std::cout << '\n';
}