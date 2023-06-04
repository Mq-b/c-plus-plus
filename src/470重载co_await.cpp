#include <coroutine>
#include <iostream>

struct promise;
struct coroutine : std::coroutine_handle<promise> {
    using promise_type = ::promise;
};

struct promise {
    coroutine get_return_object()//����ֵ����Ҫ���������::promise_type
    {
        return { coroutine::from_promise(*this) };
    }
    std::suspend_never initial_suspend() noexcept { return {}; }//ע�ⷵ������
    std::suspend_always final_suspend() noexcept { return {}; }
    void return_void() {}
    void unhandled_exception() {}
};
struct X {
    int n;
    bool await_ready() {
        return false;
    }
    void await_suspend(std::coroutine_handle<coroutine::promise_type>h) {
        //Э����ͣ����ת���� void������������ͣ����ת�����õ�������
    }
    int await_resume() { return 0; }//����co_wait�ķ���ֵ
};
inline auto operator co_await(X x) {//���뷵��������
    std::cout << "operator co_await ������ X= " << x.n << '\n';
    return x;
}

coroutine f() {
    int v = co_await X{ 10 };
    std::cout << v << '\n';
}
int main() {
    auto result = f();
    std::cout << "main\n";
    result.resume();
}