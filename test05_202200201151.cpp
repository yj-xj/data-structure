#include<iostream> // ���������������
#include<vector> // ����������
#include<string> // �����ַ�����
#include<sstream> // �����ַ�������
using namespace std; // ʹ�ñ�׼�����ռ�

template<typename T>
class Stack { // ����һ��ģ���� Stack
private:
    vector<T> data; // ʹ�������洢����
public:
    void push(const T& value) { // ������ջ����
        data.push_back(value);
    }
    T pop() { // �����ջ����
        T value = data.back();
        data.pop_back();
        return value;
    }
    int size(){
		return data.size();
	}
    T top() const { // ����ջ��Ԫ��
        return data.back();
    }
    bool empty() const { // �ж�ջ�Ƿ�Ϊ��
        return data.empty();
    }
};

int priority(char op) { // ������������ȼ�����
    switch(op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

int operate(int a, char op, int b) { // �����������
    switch(op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

int calculate(string expr) { // ���������ʽ����
    Stack<int> numbers; // �����������͵�ջ
    Stack<char> operators; // �����ַ����͵�ջ

for(int i=0;i<expr.length();i++){
	if(expr[i]<='9' && expr[i]>='0') { // ������ʽ�ĵ�һ���ַ�������
	            int number = expr[i]-'0'; // ���ַ���ת��Ϊ����
	            numbers.push(number); // ��������ջ
	        }
	        else if(expr[i] == '(') { // ������ʽ�ĵ�һ���ַ���������
	            operators.push('('); // ��������ջ
	        }
	        else if(expr[i] == ')') { // ������ʽ�ĵ�һ���ַ���������
	            while(!operators.empty() && operators.top() != '(') { // ��������ջ��Ϊ����ջ��Ԫ�ز���������ʱ
	                int b = numbers.pop(); // ��ջ�õ��ڶ���������
	                int a = numbers.pop(); // ��ջ�õ���һ��������
	                numbers.push(operate(a, operators.pop(), b)); // ���㲢�������ջ
	            }
	            operators.pop(); // ����������
	        }
	        else { // �������
	            while(!operators.empty() && priority(operators.top()) >= priority(expr[i]) && operators.top() != '(') { // ��������ջ��Ϊ����ջ�����������ȼ����ڵ��ڵ�ǰ��������ջ������������ʱ
	                int b = numbers.pop(); // ��ջ�õ��ڶ���������
	                int a = numbers.pop(); // ��ջ�õ���һ��������
	                numbers.push(operate(a, operators.pop(), b)); // ���㲢�������ջ
	            }
	            operators.push(expr[i]); // ��ǰ��������ջ
	        }
}

    while(!operators.empty() && numbers.size()>=2) { // ��������ջ��Ϊ��ʱ
        int b = numbers.pop(); // ��ջ�õ��ڶ���������
        int a = numbers.pop(); // ��ջ�õ���һ��������
        numbers.push(operate(a, operators.pop(), b)); // ���㲢�������ջ
    }

    return numbers.top(); // ����ջ��Ԫ��
}

int main() { // ������
    cout << "Input" << endl; // �����ʾ��Ϣ
    int result; // ����������
    string str; // �����ַ�������
    getline(cin, str); // �ӱ�׼�������ж�ȡһ���ַ���
    result = calculate(str); // ���ü�����ʽ����
    cout << "Output" << endl; // �����ʾ��Ϣ
    cout << "=" << result << endl; // ������
    cout << "End" << endl; // ���������Ϣ
    return 0; // ����0
}
