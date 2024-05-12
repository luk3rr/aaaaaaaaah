void testa_coloracao_gulosa(Vertice **v, int n){
    int cor_vertice, grau_vertice, cor_teste, cor_vizinho;
    bool passou;

    for(int i = 0; i < n; i++){
        // para cada vertice com cor>1
        if(v[i]->getCor() > 1)
        {

            // condição 1: colorações gulosas têm grau>=(cor-1)
            if(v[i]->getGrau() < (v[i]->getCor()-1)){
              cout<<"0"<<endl;
              return;
            }

            cor_vertice = v[i]->getCor();
            grau_vertice = v[i]->getGrau();
            // Para esse problema, eu acho a lógica de assumir como verdadeiro e tentar achar um contra-examplo dificil de entender,
            // então mudei para false e só atribuo como verdadeiro quando já tiver encontrado todas as colorações para um determinado
            // vértice ser guloso
            passou = false;

            // condição 2: colorações gulosas têm pelo menos um vizinho para cada cor entre 1 e (cor_vertice-1)
            cor_teste = 1; 
            //std::cout << "\nTESTE Vertice: " << i << " cor: " << cor_vertice << std::endl; 
            
            // Você deve estar se perguntando por que diabos eu modifiquei seu loop de for para while. Leia o comentário
            // gigante a baixo antes de ler esse:
            //    Agora que você já entendeu o motivo de precisarmos definir o j como 0 sempre que encontramos uma vértice,
            //    não podemos continuar utilizando o for, pelo simples fato de que quando setamos j = 0, ao voltar no loop
            //    ele será incrementado em 1 :'). Assim a gente nunca volta a verificar o vértice na posição 0.
            //
            //for (int j = 0; j < grau_vertice; j++)
            int j = 0;
            while (j < grau_vertice)
            { 
                cor_vizinho = v[i]->vizinhos[j]->getCor();
                //std::cout << "Vizinho: " << v[i]->vizinhos[j]->getLabel() << " cor: " << cor_vizinho << std::endl; 
                if (cor_vizinho == cor_teste)
                {
                    // Com essa lógica, precisamos fazer j = 0 para verificarmos novamente todos os vizinhos e buscar o vizinho
                    // com a cor igual a cor de teste. But, why ?
                    // Pense no caso em que que o vértice i com cor 4 tem três vizinhos:
                    //   vizinho A com cor 1
                    //   vizinho B com cor 3
                    //   vizinho C com cor 2
                    // Vamos percorrer o array de vizinhos da seguinte forma:
                    //   j = 0, cor de teste = 1, procuramos um vértice com cor 1:
                    //     - De cara encontramos o vértice A. Its okay ;)
                    //
                    //   j = 1, cor de teste = 2, procuramos um vértice com cor 2:
                    //     - Ignoramos o A, pois j vai pegar os vizinhos a partir da posição 1 (segundo elemento do vetor)
                    //     - Encontramos o B, mas ele tem cor 3, que não é igual a cor de teste, então vamos para o próximo j
                    //   
                    //   j = 2, cor de teste = 2, procuramos (ainda) um vértice de cor 2:
                    //     - Ignoramos o A e o B, pois j vai pegar os vizinhos a partir da posição 2 (terceiro elemento do vetor)
                    //     - Encontramos o C, e ele tem cor igual a 2, que era o que procurávamos, yeah :)
                    //   
                    //   j = 3, que não é menor que o grau do vértice (3 não é menor que 3), então o loop é finalizado
                    //     - Fuck, não achamos o vértice de cor igual a 3 :(
                    //     - Mas ele existia
                    // 
                    // Definir o j como 0 é necessário para que todo o vetor de vizinhos seja percorrido novamente, se 
                    // não algum vértice pode passar despercebido. 
                    //
                    j = 0; 
                    cor_teste++;

                    //std::cout << "Achouu, Laura! Vizinho: " << v[i]->vizinhos[j]->getLabel() << " cor: " << cor_vizinho << std::endl; 
                    //std::cout << "cor teste: " << cor_teste << " cor_vertice: " << cor_vertice << std::endl;
                    if (cor_teste == cor_vertice)
                    {
                        //std::cout << "Tudo okay, vamos para o próximo :)" << std::endl;
                        passou = true;
                        break;
                    }
                }
                else 
                {
                    j++;
                }
            }

            if (!passou)
            {
                cout << "0" << endl;
                return;
            }

        }
    }


    // se condições 1 e 2 satisfeitas para todos os vértices
    cout<<"1";
    for(int i=0; i<n; i++){
        cout<<" "<<v[i]->getLabel();
    }
    cout<<endl;

}
