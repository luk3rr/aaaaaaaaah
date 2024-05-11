/*
 * Filename: modificadores_de_acesso_em_heranca.cc
 * Created on: May 10, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Exemplo de modificadores de acesso em herança
 */

class Base
{
    public:
        int publicVar;

        int publicMethod()
        {
            return publicVar;
        }

    protected:
        int protectedVar;

        int protectedMethod()
        {
            return protectedVar;
        }

    private:
        int privateVar;

        int privateMethod()
        {
            return privateVar;
        }
};

// Tudo que é público em Base, continua público em DerivedPublic,
// tudo que é protegido em Base, continua protegido em DerivedPublic
// e tudo que é privado em Base, continua privado em DerivedPublic
class DerivedPublic : public Base
{
    public:
        void Access()
        {
            publicVar    = 1;
            protectedVar = 2;
            // privateVar = 3; // Erro de compilação
            publicMethod();
            protectedMethod();
            // privateMethod(); // Erro de compilação
        }
};

// Tudo que é público em Base, vira protegido em DerivedProtected,
// tudo que é protegido em Base, continua protegido em DerivedProtected
// e tudo que é privado em Base, continua privado em DerivedProtected
class DerivedProtected : protected Base
{
    public:
        void Access()
        {
            publicVar    = 1;
            protectedVar = 2;
            // privateVar = 3; // Erro de compilação
            publicMethod();
            protectedMethod();
            // privateMethod(); // Erro de compilação
        }
};

// Tudo que é público em Base, vira privado em DerivedPrivate,
// tudo que é protegido em Base, vira privado em DerivedPrivate
// e tudo que é privado em Base, continua privado em DerivedPrivate
class DerivedPrivate : private Base
{
    public:
        void Access()
        {
            publicVar    = 1;
            protectedVar = 2;
            // privateVar = 3; // Erro de compilação
            publicMethod();
            protectedMethod();
            // privateMethod(); // Erro de compilação
        }
};

/* Nos exemplos abaixo eu utilizo herança publica apenas porque ela não altera
 * o tipo de acesso das classes que estão sendo herdadas. O objetivo e testar a
 * modificação feita na herança anterior (DerivedPublic, DerivedPrivate e
 * DerivedProtected) */

// Como DerivedPublic herdou Base publicamente, os modificadores de acesso de Base
// continuam os mesmos em DerivedPublic, ou seja, publicVar e publicMethod continuam
// públicos, protectedVar e protectedMethod continuam protegidos e privateVar e
// privateMethod continuam privados.
//
// O mesmo vale para TesteDerivedPublic, que herda DerivedPublic publicamente.
class TesteDerivedPublic : public DerivedPublic
{
    public:
        void Access()
        {
            publicVar    = 1;
            protectedVar = 2;
            // privateVar = 3; // Erro de compilação
            publicMethod();
            protectedMethod();
            // privateMethod(); // Erro de compilação
        }
};

// Como DerivedProtected herdou Base protegido, os atributos e métodos públicos de Base
// viram protegidos em DerivedProtected, ou seja, publicVar e publicMethod viram
// protegidos, protectedVar e protectedMethod continuam protegidos e privateVar e
// privateMethod continuam privados.
//
// Não há diferença entre DerivedProtected e TesteDerivedProtected, pois o que era
// público em Base virou protegido em DerivedProtected, logo TesteDerivedProtected pode
// acessar os atributos e métodos de Base da mesma forma que DerivedProtected.
//
// No entanto, se você criar uma instância de TesteDerivedProtected, você não poderá
// acessar os atributos e métodos de Base diretamente (sem métodos), pois
// DerivedProtected herdou Base protegido
class TesteDerivedProtected : public DerivedProtected
{
    public:
        void Access()
        {
            publicVar    = 1;
            protectedVar = 2;
            // privateVar = 3; // Erro de compilação
            publicMethod();
            protectedMethod();
            // privateMethod(); // Erro de compilação
        }
};

// Aqui que realmente vemos a diferença entre DerivedPrivate e TesteDerivedPrivate.
// DerivedPrivate herdou Base privado, logo tudo que era público e protegido em Base
// virou privado em DerivedPrivate. Assim, não é possível acessar os atributos e métodos
// de Base em TesteDerivedPrivate.
//
// Perceba que mesmo que TesteDerivedPrivate herde DerivedPrivate publicamente, não é
// possível modificar o tipo de acesso dos atributos e métodos de Base.
class TesteDerivedPrivate : public DerivedPrivate
{
    public:
        void Access()
        {
            // publicVar = 1; // Erro de compilação, pois publicVar é privado em
            // DerivedPrivate (foi modificado durante a herança) protectedVar = 2; //
            // Erro de compilação, pois protectedVar é privado em DerivedPrivate (foi
            // modificado durante a herança) privateVar = 3; // Erro de compilação, já
            // era privado em Base publicMethod(); // Erro de compilação pois
            // publicMethod é privado em DerivedPrivate (foi modificado durante a
            // herança) protectedMethod(); // Erro de compilação pois protectedMethod é
            // privado em DerivedPrivate (foi modificado durante a herança)
            // privateMethod(); // Erro de compilação
        }
};

// Em geral, quando você herda uma classe publicamente, você não pode modificar o tipo
// de acesso dos atributos e métodos da classe base. Normalmemente fazemos herança assim.
//
// Por outro lado, quando você herda uma classe protegido tudo que era público em Base
// vira protegido.
//
// Agora, quando você herda uma classe privadamente, tudo que era público e protegido em
// Base vira privado.
int main()
{
    DerivedPublic dp;
    dp.publicVar = 1; // Ok
    // dp.protectedVar = 2; // Erro de compilação
    // dp.privateVar = 3; // Erro de compilação

    DerivedProtected dprot;
    // dprot.publicVar = 1; // Erro de compilação
    // dprot.protectedVar = 2; // Erro de compilação
    // dprot.privateVar = 3; // Erro de compilação

    DerivedPrivate dpriv;
    // dpriv.publicVar = 1; // Erro de compilação
    // dpriv.protectedVar = 2; // Erro de compilação
    // dpriv.privateVar = 3; // Erro de compilação

    TesteDerivedPublic tdp;
    tdp.publicVar = 1; // Ok
    // tdp.protectedVar = 2; // Erro de compilação
    // tdp.privateVar = 3; // Erro de compilação
    tdp.publicMethod(); // Erro de compilação
    // tdp.protectedMethod(); // Erro de compilação
    // tdp.privateMethod(); // Erro de compilação

    TesteDerivedProtected tdprot;
    // tdprot.publicVar = 1; // Erro de compilação
    // tdprot.protectedVar = 2; // Erro de compilação
    // tdprot.privateVar = 3; // Erro de compilação
    // tdprot.publicMethod(); // Erro de compilação
    // tdprot.protectedMethod(); // Erro de compilação
    // tdprot.privateMethod(); // Erro de compilação

    TesteDerivedPrivate tdpriv;
    // tdpriv.publicVar = 1; // Erro de compilação
    // tdpriv.protectedVar = 2; // Erro de compilação
    // tdpriv.privateVar = 3; // Erro de compilação
    // tdpriv.publicMethod(); // Erro de compilação
    // tdpriv.protectedMethod(); // Erro de compilação
    // tdpriv.privateMethod(); // Erro de compilação

    return 0;
}

// Você pode testa o códiga acima descomentando as linhas de erro de compilação para ver
// os erros que ocorrem. Recomendo para entender melhor o comportamento dos
// modificadores. Se você tiver alguma dúvida, pode escrever para mim no meu e-mail.
