/*
 * Filename: modificadores_de_acesso.cc
 * Created on: May 10, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Exemplo de uso de modificadores de acesso em C++
 */

class QualquerCoisa
{
    public: // Podem ser acessados de qualquer lugar, inclusive de fora da classe
            // e.g. QualquerCoisa.publicVar = 10;
        int publicVar;
        int publicMethod() { return publicVar; }

    protected: // Podem ser acessados apenas por classes derivadas
               // Fora da classe não é possível acessar e modificar diretamente, sendo necessário
               // usar métodos para isso
        int protectedVar;
        int protectedMethod() { return protectedVar; }

    private: // Podem ser acessados apenas pela própria classe
             // Classe derivada não pode acessar
             // Aqui sempre é necessário usar métodos para acessar ou modificar
        int privateVar;
        int privateMethod() { return privateVar; }
};

class Derivada : public QualquerCoisa
{
    public:
        void AccessAttributes()
        {
            publicVar = 10; // OK
            protectedVar = 10; // OK, pois é uma classe derivada
            // privateVar = 10; // Erro, pois é privado na classe base. Deve ser acessado por métodos

            publicMethod(); // OK
            protectedMethod(); // OK
            // privateMethod(); // Erro, pois é privado na classe base. Deve ser acessado por métodos
        }
};

int main()
{
    QualquerCoisa qc;

    qc.publicVar = 10; // OK
    // qc.protectedVar = 10; // Erro, de fora da classe não é possível acessar
    // qc.privateVar = 10; // Erro, de fora da classe não é possível acessar

    qc.publicMethod(); // OK
    // qc.protectedMethod(); // Erro, de fora da classe não é possível acessar
    // qc.privateMethod(); // Erro, de fora da classe não é possível acessar

    Derivada d;

    d.publicVar = 10; // OK
    // d.protectedVar = 10; // Erro, de fora da classe não é possível acessar
    // d.privateVar = 10; // Erro, de fora da classe não é possível acessar

    return 0;
}
