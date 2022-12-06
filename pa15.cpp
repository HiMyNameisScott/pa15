// DOCUMENTATION HEADER HERE

//#define NDEBUG
#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <string>


#define CATCH_CONFIG_MAIN
#include <catch.hpp>

namespace cs202 {
unsigned sum_squares(unsigned num);
int64_t mystery(int64_t x, int64_t y);
bool is_palindrome(const std::string& str);
double mysqrt(double num);
template <class Iter, class T> Iter search(Iter first, Iter last, const T& value);
}  /* namespace cs202 */

/** Place your function prototypes here.  */
unsigned cs202::sum_squares(unsigned num);
int64_t cs202::mystery(int64_t x, int64_t y);
bool cs202::is_palindrome(const std::string& str);
double cs202::mysqrt(double num);
std::string fix_a_string(std::string str);


/** Place your function definitions here. */

/// @brief 
/// @param num 
/// @return 
unsigned cs202::sum_squares(unsigned num) {
    
    return 0;
}

/// @brief 
/// @param x 
/// @param y 
/// @return 
int64_t cs202::mystery(int64_t x, int64_t y) {
    if ( y == 0) {
        return x;
    }
    return mystery(y, ( x % y));
}

/// @brief checks to see if 
/// @param str 
/// @return 
bool cs202::is_palindrome(const std::string& str) {
    fix_a_string(str);
    if (str.front() == str.back()) {
        if (str.length() == 0) {
            return true;
        } else {
            return is_palindrome(str.substr(str.front()+1, str.back()-1));
        }
    } else {
        return false;
    }
}

/// @brief Will return the square root of a number
/// @param num 
/// @return num if square root else return function with num
double cs202::mysqrt(double num) {
    if(fabs((num*num) - num) <= 1e-6) {
        return num;
    } else {
        return mysqrt((num * num)/ 2*(num));
    }
}

/// @brief Iterates through a list, and finds a target value
/// @tparam Iter 
/// @tparam T 
/// @param first 
/// @param last 
/// @param value 
/// @return 
template <class Iter, class T>
Iter cs202::search(Iter first, Iter last, const T& value) {
    // TODO
    return last;
}

// helpers

/// @brief Formats string
/// @param str string to be formatted
/// @return the formated string
std::string fix_a_string(std::string str) {
    std::string output;
    for (int i = 0 ; i < str.length() ; i++) {
        tolower(str[i]);
    }
    for (int i = 0 ; i < str.length() ; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            output.push_back(str[i]);
            std::cout << str[i] << std::endl;
        }
    }
    return output;

};

// ============================================================================
// UNIT TESTS - DO NOT MODIFY!!!
// ============================================================================

TEST_CASE("cs202::sum_squares()") {
    const std::array<unsigned, 11> expected {
        0, 1, 5, 14, 30, 55, 91, 140, 204, 285, 385
    };

    for (unsigned n = 0; n < expected.size(); ++n) {
        INFO("When n is " << n);
        CHECK(cs202::sum_squares(n) == expected[n]);
    }
}

TEST_CASE("cs202::is_palindrome()") {
    std::array<std::string, 5> inputs {
        "",
        "madam",
        "Red rum, sir, is murder.",
        "A Man, a Plan, a Canal -- Panama!",

        // Demetri Martin's "Dammit I'm Mad" - a very long palindrome indeed!
        "Dammit I'm mad.\n"
        "Evil is a deed as I live.\n"
        "God, am I reviled? I rise, my bed on a sun, I melt.\n"
        "To be not one man emanating is sad. I piss.\n"
        "Alas, it is so late. Who stops to help?\n"
        "Man, it is hot. I'm in it. I tell.\n"
        "I am not a devil. I level \"Mad Dog\".\n"
        "Ah, say burning is, as a deified gulp,\n"
        "In my halo of a mired rum tin.\n"
        "I erase many men. Oh, to be man, a sin.\n"
        "Is evil in a clam? In a trap?\n"
        "No. It is open. On it I was stuck.\n"
        "Rats peed on hope. Elsewhere dips a web.\n"
        "Be still if I fill its ebb.\n"
        "Ew, a spider... eh?\n"
        "We sleep. Oh no!\n"
        "Deep, stark cuts saw it in one position.\n"
        "Part animal, can I live? Sin is a name.\n"
        "Both, one... my names are in it.\n"
        "Murder? I'm a fool.\n"
        "A hymn I plug, deified as a sign in ruby ash,\n"
        "A Goddam level I lived at.\n"
        "On mail let it in. I'm it.\n"
        "Oh, sit in ample hot spots. Oh wet!\n"
        "A loss it is alas (sip). I'd assign it a name.\n"
        "Name not one bottle minus an ode by me:\n"
        "\"Sir, I deliver. I'm a dog\"\n"
        "Evil is a deed as I live.\n"
        "Dammit I'm mad.\n"
    };

    for (auto str : inputs) {
        INFO("When str is " << str);
        CHECK(cs202::is_palindrome(str) == true);
    }

    for (auto& str : inputs) {
        str.insert(str.size() / 2, "NOT");
        INFO("When str is " << str);
        CHECK(cs202::is_palindrome(str) == false);
    }
}

TEST_CASE("cs202::mystery()") {
    CHECK(cs202::mystery(  8, 12) == 4);
    CHECK(cs202::mystery( 54, 24) == 6);
    CHECK(cs202::mystery( 13, 48) == 1);
    CHECK(cs202::mystery(135, 25) == 5);
}

TEST_CASE("cs202::mysqrt()") {
    for (double d = 0.0; d <= 10.0; d += 0.5) {
        INFO("When d is " << d);
        CHECK(cs202::mysqrt(d) == Approx(std::sqrt(d)));
    }
}

TEST_CASE("cs202::search()") {
    std::array<int, 10> list { 7, 1, 6, 9, 4, 0, 8, 5, 3, 2 };

    for (int i = 0; i < 10; ++i) {
        INFO("When i is " << i);
        CHECK(cs202::search(list.begin(), list.end(), i) == std::find(list.begin(), list.end(), i));
    }

    CHECK(cs202::search(list.begin(), list.end(), 42) == list.end());
}

/* EOF */

