export module A;// 为具名模块 'A' 声明主模块接口单元
int f() { return 0; } // f 具有模块链接

import :imp1;
import :imp2;
export void MyFunc();
export void print(auto);