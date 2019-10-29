#include <cstdint>

// What do you see when printing the variable bc?
//
// b main
// r
// n
// n
// n
// p bc
//
// What does the output look like once you load word_printer.py?
//
// source word_printer.py
//
// (repeat)

using u8 = std::uint8_t;
using u16 = std::uint16_t;

class word {
public:
    word(u8& hi, u8& lo) noexcept
	: m_hi{ hi }
	, m_lo{ lo }
    {
    }

    operator u16() const noexcept
    {
	return static_cast<u16>((m_hi << 8) | m_lo);
    }

    word& operator=(u16 rhs) noexcept
    {
	m_hi = static_cast<u8>(rhs >> 8);
	m_lo = static_cast<u8>(rhs);
	return *this;
    }

private:
    u8& m_hi;
    u8& m_lo;
};

int main()
{
    u8 b = 0xff;
    u8 c = 0xef;

    word bc{ b, c };

    return bc;
}
