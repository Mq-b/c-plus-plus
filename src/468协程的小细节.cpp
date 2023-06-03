#include <coroutine>
#include <iostream>

struct promise;
struct coroutine : std::coroutine_handle<promise>{
    using promise_type = ::promise;//��Ҫ�������޶����ֲ���
};

struct promise{
    coroutine get_return_object()
    {
        return { coroutine::from_promise(*this) };
    }
    std::suspend_always initial_suspend() noexcept { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    void return_void() {}
    void unhandled_exception() {}
};

struct S {
    int i;
    coroutine f() {
        std::cout << i << '\n';
        co_return;
    }
};

void bad1() {
    S s{ 0 };
    coroutine h = s.f();
    // S{0} ������
    std::cout << "�ֺ�\n";
    //h.resume(); // Э�ָ̻���ִ���� std::cout << i �����ͷź�ʹ���� S::i

}

int main() {
    bad1();
}
//ʹ��suspend_never��initial_suspend�ķ���ֵ�ͻ���ִ�е�co_return�ȴ���������cout��ӡ0
//���������ֵ�ĳ�suspend_always����ô��Ȼ�ȴ�ӡ���ֺǡ��������ʹ��h.resume();��Э�ָ̻�ִ�У���ô�����ӡ0