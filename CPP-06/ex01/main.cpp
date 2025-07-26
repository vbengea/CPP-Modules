#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
	
	Data* originData = new Data;
	originData->x = 42;

	unsigned long serialized = Serializer::serialize(originData);

	Data* deserializedData = Serializer::deserialize(serialized);

	std::cout << "Original pointer: " << originData << std::endl;
	std::cout << "Deserialized pointer: " << deserializedData << std::endl;

	std::cout << "Original value: " << originData->x << std::endl;
	std::cout << "Deserialized value: " << deserializedData->x << std::endl;

	delete originData;
}