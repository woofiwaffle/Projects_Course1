#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;



void push(vector<string>& stack, string value){
    stack.push_back(value);
}



string pop(vector<string>& stack){
    string value = stack.back();
    stack.pop_back();
    return value;
}



void printStack(vector<string>& stack){
    cout << "[";
    for(int i = 0; i < stack.size(); i++){
        cout << stack[i];
        if(i < stack.size() - 1){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}



void clearStack(vector<string>& stack){
    stack.clear();
}



bool isOperator(string token){
    return token == "+" || token == "-" || token == "*" || token == "/";
}



int evaluate(string op, int a, int b){
    if(op == "+"){
        return a + b;
    }
    else if(op == "-"){
        return a - b;
    }
    else if(op == "*"){
        return a * b;
    }
    else if(op == "/"){
        return a / b;
    }
    else{
        throw runtime_error("Unknown operator: " + op);
    }
}



void printResult(int result){
    cout << "Result: " << result << endl;
}



void convertToDPN(vector<string>& tokens){
    vector<string> stack;
    vector<string> output;

    for(int i = tokens.size() - 1; i >= 0; i--){
        string token = tokens[i];

        if(isdigit(token[0])){
            output.push_back(token);
            cout << "Output: ";
            printStack(output);
        }
        else if(isOperator(token)){
            while(!stack.empty() && isOperator(stack.back()) && ((token == "*" || token == "/") || (token == "+" || token == "-"))) {
                string op = stack.back();
                stack.pop_back();
                output.push_back(op);
                cout << "Output: ";
                printStack(output);
            }
            stack.push_back(token);
            cout << "Stack: ";
            printStack(stack);
        }
        else if(token == ")"){
            stack.push_back(token);
            cout << "Stack: ";
            printStack(stack);
        }
        else if(token == "("){
            while(!stack.empty() && stack.back() != ")") {
                string op = stack.back();
                stack.pop_back();
                output.push_back(op);
                cout << "Output: ";
                printStack(output);
            }
            if(stack.empty()){
                throw runtime_error("Error");
            }
            stack.pop_back();
            cout << "Stack: ";
            printStack(stack);
        }
        else{
            throw runtime_error("Unknown token: " + token);
        }
    }

    while(!stack.empty()){
        string op = stack.back();
        stack.pop_back();
        if(op == ")"){
            throw runtime_error("Error");
        }
        output.push_back(op);
        cout << "Output: ";
        printStack(output);
    }
    reverse(output.begin(), output.end());
    tokens = output;
}



int evaluateExpressionToDPN(vector<string>& tokens){
    vector<string> stack;

    int result = 0;
    for(int i = tokens.size() - 1; i >= 0; i--){
        string token = tokens[i];

        if(isOperator(token)){
            string op = token;
            int a = stoi(pop(stack));
            int b = stoi(pop(stack));
            result = evaluate(op, a, b);
            push(stack, to_string(result));
            cout << "Stack after evaluating " << op << ": ";
            printStack(stack);
            printResult(result);
        }
        else{
            push(stack, token);
            cout << "Stack after pushing " << token << ": ";
            printStack(stack);
        }
    }
    return result;
}



string convertToRPN(vector<string>& tokens) {
    vector<string> stack;
    vector<string> output;

    for(int i = 0; i < tokens.size(); i++){
        string token = tokens[i];

        if(isdigit(token[0])){
            output.push_back(token);
            cout << "Output: ";
            printStack(output);
        }
        else if(isOperator(token)){
            while(!stack.empty() && isOperator(stack.back()) && ((token == "*" || token == "/") || (token == "+" || token == "-"))) {
                string op = stack.back();
                stack.pop_back();
                output.push_back(op);
                cout << "Output: ";
                printStack(output);
            }
            stack.push_back(token);
            cout << "Stack: ";
            printStack(stack);
        }
        else if(token == "("){
            stack.push_back(token);
            cout << "Stack: ";
            printStack(stack);
        }
        else if(token == ")"){
            while(!stack.empty() && stack.back() != "(") {
                string op = stack.back();
                stack.pop_back();
                output.push_back(op);
                cout << "Output: ";
                printStack(output);
            }
            if(stack.empty()){
                throw runtime_error("Error");
            }
            stack.pop_back();
            cout << "Stack: ";
            printStack(stack);
        }
        else{
            throw runtime_error("Unknown token: " + token);
        }
    }

    while(!stack.empty()){
        string op = stack.back();
        stack.pop_back();
        if(op == "("){
            throw runtime_error("Error");
        }
        output.push_back(op);
        cout << "Output: ";
        printStack(output);
    }
    tokens = output;
    return output.back();
}



int evaluateExpressionToRPN(vector<string>& tokens){
    vector<string> stack;

    int result = 0;

    for(int i = 0; i < tokens.size(); i++) {
        string token = tokens[i];

        if (isOperator(token)) {
            string op = token;
            int b = stoi(pop(stack));
            int a = stoi(pop(stack));
            result = evaluate(op, a, b);
            push(stack, to_string(result));
            cout << "Stack after evaluating " << op << ": ";
            printStack(stack);
            printResult(result);
        } else {
            push(stack, token);
            cout << "Stack after pushing " << token << ": ";
            printStack(stack);
        }
    }
    return result;
}



int main() {
    string s;
    vector<string> tokens;
    string token;
    string input;
    char choice;
    do {
        cout << "Enter the number: \n";
        cout << "1 - Convert in DPN\n";
        cout << "2 - Convert in RPN\n";
        cout << ">>...\n";
        cin >> choice;
        cin.ignore();

        cout << "\n\n";

        switch (choice) {
            case '1': {
                cout << "Enter expression: ";
                getline(cin, input);
                cout << "You entered: " << input << endl;

                stringstream ss(input);
                while (ss >> token) {
                    tokens.push_back(token);
                }

                cout << "Original expression: ";
                printStack(tokens);
                convertToDPN(tokens);
                cout << "Expression in DPN: ";
                printStack(tokens);
                int result = evaluateExpressionToDPN(tokens);
                cout << "Final result: " << result << endl;
                clearStack(tokens);
                cout << "\n\n";
                break;
            }

            case '2': {
                cout << "Enter expression: ";
                getline(cin, input);
                cout << "You entered: " << input << endl;

                stringstream iss(input);
                while (iss >> token) {
                    tokens.push_back(token);
                }

                cout << "Original expression: ";
                printStack(tokens);
                convertToRPN(tokens);
                cout << "Expression in RPN: ";
                printStack(tokens);
                int result = evaluateExpressionToRPN(tokens);
                cout << "Final result: " << result << endl;
                clearStack(tokens);
                cout << "\n\n";
                break;
            }
            default: {
                cout << "Error" << endl;
                return 0;
            }
        }
    } while (choice != 0);

    return 0;
}