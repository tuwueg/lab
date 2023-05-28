// Создать класс ВitString для работы с битовыми строками длиной 64 бита.Битовая строка должна быть представлена двумя полями типа unsigned long.Конструкторы инициализации должны обеспечивать инициализациюполей целыми числами любого типа и строкой типа string.Реализоватьтрадиционные операции для работы с битами(and, or , xor, not).Для остальныхдействий реализовать перегруженные операции как методы класса./ 

#include <iostream>
#include <string>

class BitString {
private:
    unsigned long field1;
    unsigned long field2;

public:
    BitString() : field1(0), field2(0) {}

    BitString(unsigned long num1, unsigned long num2) : field1(num1), field2(num2) {}

    BitString(const std::string& binaryString) : field1(0), field2(0) {
        int len = binaryString.length();
        if (len > 64) {
            len = 64;
        }
        for (int i = 0; i < len; i++) {
            char bit = binaryString[i];
            if (bit == '1') {
                setBit(i, true);
            }
        }
    }

    void setBit(int position, bool value) {
        if (position >= 0 && position < 64) {
            unsigned long mask = 1UL << position;
            if (value) {
                field1 |= mask;
            }
            else {
                field1 &= ~mask;
            }
        }
        else if (position >= 64 && position < 128) {
            unsigned long mask = 1UL << (position - 64);
            if (value) {
                field2 |= mask;
            }
            else {
                field2 &= ~mask;
            }
        }
    }

    bool getBit(int position) const {
        if (position >= 0 && position < 64) {
            return (field1 & (1UL << position)) != 0;
        }
        else if (position >= 64 && position < 128) {
            return (field2 & (1UL << (position - 64))) != 0;
        }
        return false;
    }

    BitString operator&(const BitString& other) const {
        BitString result(field1 & other.field1, field2 & other.field2);
        return result;
    }

    BitString operator|(const BitString& other) const {
        BitString result(field1 | other.field1, field2 | other.field2);
        return result;
    }

    BitString operator^(const BitString& other) const {
        BitString result(field1 ^ other.field1, field2 ^ other.field2);
        return result;
    }

    BitString operator~() const {
        BitString result(~field1, ~field2);
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const BitString& bitString) {
        for (int i = 63; i >= 0; i--) {
            os << (bitString.getBit(i) ? '1' : '0');
        }
        return os;
    }
};

int main() {
    BitString bs1(0xAAAAAAAAAAAAAAAAULL, 0x5555555555555555ULL);
    BitString bs2("1010101010101010101010101010101010101010101010101010101010101010");

    BitString bitwiseAnd = bs1 & bs2;
    BitString bitwiseOr = bs1 | bs2;
    BitString bitwiseXor = bs1 ^ bs2;
    BitString bitwiseNot = ~bs1;

    std::cout << "AND: " << bitwiseAnd << std::endl;
    std::cout << "OR: " << bitwiseOr << std::endl;
    std::cout << "XOR: " << bitwiseXor << std::endl;
    std::cout << "NOT: " << bitwiseNot << std::endl;

    return 0;
}
