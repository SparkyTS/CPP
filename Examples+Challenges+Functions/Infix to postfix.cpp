#include <iostream>
#include <map>
#include <stack>
#include <unordered_set>

int main(){
    std::string Infix;          Infix += ')';

    std::string Postfix;

    std::stack <char> Stack;    Stack.push('(');

    std::unordered_set<char> operators {'/','*','+','-'};

    std::map <char,int> Priority {{'/',4},{'*',3},{'+',2},{'-',1}};

    std::getline(std::cin,Infix);

    for(int i = 0  ; !Stack.empty() ; i++){

        if(Infix[i]=='(')
            Stack.push('(');

        else if(Infix[i]==')'){
            while(Stack.top()!='(')
                    {Postfix += Stack.top() ; Stack.pop();}
        Stack.pop();
        }

        else if(operators.find(Infix[i])!=operators.end()){
            while(Priority[Infix[i]]<=Priority[Stack.top()])
                {Postfix += Stack.top();Stack.pop();}
                Stack.push(Infix[i]);
        }

        else
            Postfix += Infix[i];
    }

    std::cout << "Postfix : " << Postfix;
}
