#include "Serializer.hpp"

int main()
{
	Data *data = new Data;
	data->value = "test";

	std::cout << "before: " << data->value << std::endl;

	uintptr_t ptr = Serializer::serialize(data);
	data = Serializer::deserialize(ptr);

	std::cout << "after: " << data->value << std::endl;

	delete data;

	return 0;
}
