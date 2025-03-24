#include<iostream> // 包含输入输出流库
#include<vector> // 包含向量库
#include<string> // 包含字符串库
#include<sstream> // 包含字符串流库
using namespace std; // 使用标准命名空间

template<typename T>
class Stack { // 定义一个模板类 Stack
private:
    vector<T> data; // 使用向量存储数据
public:
    void push(const T& value) { // 定义入栈操作
        data.push_back(value);
    }
    T pop() { // 定义出栈操作
        T value = data.back();
        data.pop_back();
        return value;
    }
    int size(){
		return data.size();
	}
    T top() const { // 返回栈顶元素
        return data.back();
    }
    bool empty() const { // 判断栈是否为空
        return data.empty();
    }
};

int priority(char op) { // 定义操作符优先级函数
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

int operate(int a, char op, int b) { // 定义操作函数
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

int calculate(string expr) { // 定义计算表达式函数
    Stack<int> numbers; // 创建整数类型的栈
    Stack<char> operators; // 创建字符类型的栈

for(int i=0;i<expr.length();i++){
	if(expr[i]<='9' && expr[i]>='0') { // 如果表达式的第一个字符是数字
	            int number = expr[i]-'0'; // 将字符串转换为数字
	            numbers.push(number); // 将数字入栈
	        }
	        else if(expr[i] == '(') { // 如果表达式的第一个字符是左括号
	            operators.push('('); // 左括号入栈
	        }
	        else if(expr[i] == ')') { // 如果表达式的第一个字符是右括号
	            while(!operators.empty() && operators.top() != '(') { // 当操作符栈不为空且栈顶元素不是左括号时
	                int b = numbers.pop(); // 出栈得到第二个操作数
	                int a = numbers.pop(); // 出栈得到第一个操作数
	                numbers.push(operate(a, operators.pop(), b)); // 计算并将结果入栈
	            }
	            operators.pop(); // 弹出左括号
	        }
	        else { // 其他情况
	            while(!operators.empty() && priority(operators.top()) >= priority(expr[i]) && operators.top() != '(') { // 当操作符栈不为空且栈顶操作符优先级大于等于当前操作符且栈顶不是左括号时
	                int b = numbers.pop(); // 出栈得到第二个操作数
	                int a = numbers.pop(); // 出栈得到第一个操作数
	                numbers.push(operate(a, operators.pop(), b)); // 计算并将结果入栈
	            }
	            operators.push(expr[i]); // 当前操作符入栈
	        }
}

    while(!operators.empty() && numbers.size()>=2) { // 当操作符栈不为空时
        int b = numbers.pop(); // 出栈得到第二个操作数
        int a = numbers.pop(); // 出栈得到第一个操作数
        numbers.push(operate(a, operators.pop(), b)); // 计算并将结果入栈
    }

    return numbers.top(); // 返回栈顶元素
}

int main() { // 主函数
    cout << "Input" << endl; // 输出提示信息
    int result; // 定义结果变量
    string str; // 定义字符串变量
    getline(cin, str); // 从标准输入流中读取一行字符串
    result = calculate(str); // 调用计算表达式函数
    cout << "Output" << endl; // 输出提示信息
    cout << "=" << result << endl; // 输出结果
    cout << "End" << endl; // 输出结束信息
    return 0; // 返回0
}
