/*
 * Filename: vectors.cc
 * Created on: May 10, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include <vector>

class QualquerCoisa
{
    private:
        std::vector<int> v;

    public:
        QualquerCoisa()
        {
            v.push_back(1);
            v.push_back(2);
            v.push_back(3);
        }

        // Retorna uma cópia do vetor
        std::vector<int> GetV()
        {
            return v;
        }

        // Retorna uma referência para o vetor
        std::vector<int>& GetVRef()
        {
            return v;
        }
};

int main()
{
    QualquerCoisa    qc;

    // Obtem uma cópia do vetor. Alterações em v não afetam o vetor original
    // Para fazer uma cópia do vetor, é necessário percorrer todos os elementos
    // e copiá-los para um novo vetor, o que implica em um custo computacional maior,
    // mas para os objetivos da disciplina de PDS2, isso é irrelevante.
    std::vector<int> v = qc.GetV();

    // Obtem uma referência para o vetor. Alterações em vRef afetam o vetor original
    // dentro da classe QualquerCoisa.
    // A referência é mais eficiente, pois não é necessário copiar todos os elementos
    // do vetor, mas é mais perigosa, pois alterações em vRef afetam o vetor original.
    //
    // Uma referência é um endereço de memória de uma variável (ponteiros)
    std::vector<int>& vRef = qc.GetVRef();

    // Se você quiser testar as alterações faça um for, altere e imprima o vetor :)

    return 0;
}
