#include "Utils.h"

unsigned Utils::Gcd(unsigned a, unsigned b) {
    if (!b) return a;
    return Gcd(b, a  % b);
}

unsigned Utils::Lcm(unsigned a, unsigned b) {
    return a / Utils::Gcd(a, b) * b;
}