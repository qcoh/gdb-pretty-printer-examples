#include <cstddef>
#include <new>
#include <string>

namespace stack {

template <typename T, int Capacity>
class vector {
public:
    using value_type = T;

    value_type& operator[](int index)
    {
	return *(reinterpret_cast<value_type*>(m_data) + index);
    }

    void push_back(const value_type& other)
    {
	value_type* address = reinterpret_cast<value_type*>(m_data) + m_length;

	new (address) value_type{ other };

	m_length++;
    }

private:
    alignas(value_type) std::byte m_data[sizeof(value_type) * Capacity]{};
    int m_length{ 0 };
};
}

int main()
{
    stack::vector<std::string, 8> example;

    for (auto&& word : { "this", "is", "an", "example" }) {
	example.push_back(word);
    }
}
