/*
 * Filename: isalpha.cc
 * Created on: May 12, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Código de exemplo que mostra como usar a função isalpha da biblioteca e o que é
 * considerado um caractere alfabético (alpha).
 */

#include <iostream>
#include <string>

int main()
{
    std::string chars = "abcdefghijklmnopqrstuvwxyzáàéèíìóòúàâêîôûãõç1234567890><!@#$%*"
                        "()_+=;.,][~´`'=}{|/\\\"?^&*¨:><";

    for (int i = 0; i < chars.size(); i++)
    {
        std::isalpha(chars[i]) ? std::cout << chars[i] << " is alpha" << std::endl
                               : std::cout << chars[i] << " is not alpha" << std::endl;
    }

    return 0;
}
