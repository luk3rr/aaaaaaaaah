#include <iostream>
#include <string>

int main()
{
    std::string alphabet =
        "abcdefghijklmnopqrstuvwxyzç1234567890><!@#$%*()_+=;.,][~´`'=";

    for (int i = 0; i < alphabet.size(); i++)
    {
        std::isalpha(alphabet[i])
            ? std::cout << alphabet[i] << " is alpha" << std::endl
            : std::cout << alphabet[i] << " is not alpha" << std::endl;
    }

    return 0;
}
