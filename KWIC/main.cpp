#include "Input.h"
#include "Keywords.h"
#include "StopwordLoader.h"
#include "Output.h"

#include <bits/stdc++.h>
using namespace std;

int main(){
    Input input = Input();
    KeyWord keyword = KeyWord();
    StopWords stopword =  StopWords();
    Output output = Output();
    
    input.GetTitles();
    stopword.GetStopWords();
    
    keyword.GetKeywords(input);
    keyword.Filter(stopword);
    
    output.GetOutput(input, keyword);
   
    int opr;
    cout << "____________________________________________";
    cout << "\nEscolha uma das opcoes abaixo:" << endl;
    cout << "\t1: Procura titulo por keyword" << endl;
    cout << "\t2: Mostrar os titulos" << endl;
    cout << "\t3: Mostrar as keywords" << endl;
    cout << "\t4: Adicionar uma stopword" << endl;
    cout << "\t5: Mostrar as stopwords" << endl;
    cout << "\t6: Finalizar programa" << endl << endl;
 	cout << "->Digite a operacao: ";
    
    cin >> opr;
    
    switch(opr) {
    	case 1:
    			output.FindTitles(input);
    			main();
    			break;
    	case 2:
    			input.PrintTitles();
    			main();
    			break;
    	case 3:
    			keyword.PrintKeywords();
    			main();
    			break;
    	case 4:
    			stopword.AddStopWord();
    			main();
    			break;
    	case 5:
    			stopword.PrintStopWords();
    			main();
    			break;
    	case 6:
    			cout << "Obrigado, volte sempre." << endl;
    			exit(-1);
    	default:
    			cout << "Opcao invalida, tente novamente!" << endl;
    			main();		
    }
}