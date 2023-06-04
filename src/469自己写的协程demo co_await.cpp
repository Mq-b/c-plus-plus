#include <coroutine>
#include <iostream>

struct promise;
struct coroutine : std::coroutine_handle<promise> {
    using promise_type = ::promise;//��Ҫ�������޶����ֲ��� ��Ҫ�������
};

struct promise {//primise����promise_type
    coroutine get_return_object()//����ֵ����Ҫ���������::promise_type
    {
        return { coroutine::from_promise(*this) };
    }
    std::suspend_never initial_suspend() noexcept { return {}; }//ע�ⷵ������
    std::suspend_always final_suspend() noexcept { return {}; }
    void return_void() {}
    void unhandled_exception() {}
};
struct Note { int guess; };//����Э�̴���ֵ
struct Input {
    Note& _in;
    bool await_ready() {
        return false;//����ĳ�true����ô������ͣЭ�̻�ִ�н�������ômain������resume()�ͻ��׳��쳣
    }
    void await_suspend(std::coroutine_handle<coroutine::promise_type>h) {
        //Э����ͣ����ת���� void������������ͣ����ת�����õ�������
    }
    int await_resume() { return _in.guess; }//����co_wait�ķ���ֵ
};

coroutine f(Note& note) {
    std::cout << note.guess << '\n';
    Input input{ note };
    int v = co_await input;
    std::cout << "co_await: " << v << '\n';
}

int main() {
    Note n{ 10 };
    auto result = f(n);
    std::cout << "main" << '\n';
    n.guess = 100;
    result.resume();
}