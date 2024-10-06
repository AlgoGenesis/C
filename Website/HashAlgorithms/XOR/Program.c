#include <assert.h>
#include <inttypes.h>
#include <stdio.h>

/**
 * @brief 8-bit XOR algorithm implementation
 *
 * @param s NULL terminated ASCII string to hash
 * @return 8-bit hash result
 */
unsigned char xor8(const char *input_string) {
    unsigned char hash_value = 0;
    while (*input_string) {
        hash_value ^= (unsigned char)(*input_string); // XOR with the ASCII value
        input_string++;
    }
    return hash_value;
}

/**
 * @brief Test function for ::xor8
 * \returns None
 */
void test_xor8()
{
    assert(xor8("Hello World") == 32);
    assert(xor8("Hello world!") == 33);
    printf("Tests passed\n");
}

/** Main function */
int main()
{
    test_xor8();
    return 0;
}