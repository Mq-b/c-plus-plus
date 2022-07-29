//
//#include <iostream>
//#include <stack>
//
//// 判断是否是操作符
//bool isOperator(char ch) {
//    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
//        return true;
//    return false; // 否则返回false
//}
//
//// 获取优先级
//int getPriority(char ch) {
//    int level = 0; // 优先级
//
//    switch (ch) {
//    case '(':
//        level = 1;
//        break;
//    case '+':
//    case '-':
//        level = 2;
//        break;
//    case '*':
//    case '/':
//        level = 3;
//        break;
//    default:
//        break;
//    }
//    return level;
//}
//
//int main(int argc, const char* argv[]) {
//    // insert code here...
//    int num;
//    char arr[256]; // 一个一个的读取表达式，直到遇到'\0'
//    std::stack<char> op; // 栈op:存储操作符
//
//    while (true) {
//        std::cin.getline(arr, 256);
//        int len, i;
//        char c; // c存储从栈中取出的操作符
//
//        len = (int)strlen(arr); // strlen()输出的是：unsigned long类型，所以要强制转换为int类型
//        i = 0;
//        while (i < len) {
//            if (isdigit(arr[i])) { // 如果是数字
//                num = 0;
//                do {
//                    num = num * 10 + (arr[i] - '0'); // ch - 48根据ASCAII码，字符与数字之间的转换关系
//                    i++; // 下一个字符
//                } while (isdigit(arr[i]));
//                std::cout << num << " ";
//            }
//            else if (arr[i] == '(') { // (:左括号
//                op.push(arr[i]);
//                i++;
//            }
//            else if (isOperator(arr[i])) { // 操作符
//                if (op.empty()) {// 如果栈空，直接压入栈
//                    op.push(arr[i]);
//                    i++;
//                }
//                else {
//                    // 比较栈op顶的操作符与ch的优先级
//                    // 如果ch的优先级高，则直接压入栈
//                    // 否则，推出栈中的操作符，直到操作符小于ch的优先级，或者遇到（，或者栈已空
//                    while (!op.empty()) {
//                        c = op.top();
//                        if (getPriority(arr[i]) <= getPriority(c)) {
//                            // 优先级低或等于
//                            std::cout << c << " ";
//                            op.pop();
//                        }
//                        else // ch优先级高于栈中操作符
//                            break;
//                    } // while结束
//                    op.push(arr[i]); // 防止不断的推出操作符，最后空栈了;或者ch优先级高了
//                    i++;
//                } // else
//            }
//            else if (arr[i] == ')') { // 如果是右括号，一直推出栈中操作符，直到遇到左括号(
//                while (op.top() != '(') {
//                    std::cout << op.top() << " ";
//                    op.pop();
//                }
//                op.pop(); // 把左括号(推出栈
//                i++;
//            }
//            else // 如果是空白符，就进行下一个字符的处理
//                i++;
//        } // 第二个while结束
//        while (!op.empty()) { // 当栈不空，继续输出操作符
//            std::cout << op.top() << " ";
//            op.pop();
//        }
//        std::cout << std::endl;
//        flush(std::cout);
//    } // 第一个while结束
//    return 0;
//}