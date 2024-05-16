/*
 * Filename: historico_de_emprestimos.cc
 * Created on: May 16, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Exemplo de como armazenar o histórico de empréstimos de uma biblioteca. Utilizado
 * em uma atividade da disciplina de Programação e Desenvolvimento de Software II
 */

#include <vector>

class Item;
class User;

// Essa é a forma mais fácil que consigo pensar para armazenar o histórico de
// empréstimos. A ideia é que cada elemento do vetor m_reservations seja um
// par, onde o primeiro elemento é um par de ponteiros para Item e User, e o
// segundo elemento é um booleano que indica se o empréstimo foi devolvido ou
// não. Assim, para saber se um item está emprestado, basta procurar por ele
// no vetor m_reservations e verificar se o booleano correspondente é falso.
//
// Além disso, para adicionar um novo empréstimo, basta adicionar um novo
// par no vetor m_reservations. Para devolver um item, basta procurar pelo
// par correspondente e alterar o booleano para true.
std::vector<std::pair<std::pair<Item*, User*>, bool>> m_reservations;

// Você também pode criar uma struct (ou class, ou union (sim, existe isso em C/C++)) para armazenar as três informações juntas. Mas, sou
// preguiçoso e prefiro usar um Pair de Pair :p
