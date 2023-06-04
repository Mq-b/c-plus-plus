#include <coroutine>
#include <iostream>

struct promise;
struct coroutine : std::coroutine_handle<promise>{
    using promise_type = ::promise;//��Ҫ�������޶����ֲ��� ��Ҫ�������
};

struct promise{//primise����promise_type
    coroutine get_return_object()//����ֵ����Ҫ���������::promise_type
    {
        return { coroutine::from_promise(*this) };
    }
    std::suspend_always initial_suspend() noexcept { return {}; }//ע�ⷵ������
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
    std::cout << "�ֺ�\n";
    //h.resume(); // Э�ָ̻���ִ����

}
void bad3()
{
    coroutine h = [i = 0]() -> coroutine // һ�� lambda ��ͬʱҲ�Ǹ�Э��
    {
        std::cout << i << '\n';
        co_return;
    }(); // ��������
    std::cout << "�ֺ�\n";
    // lambda ������
    std::cout << std::boolalpha << h.done() << '\n';//���coroutine���Ǹ������ķ���������suspend_never����ô������ӡtrue��Э��ִ�����
    h.resume(); // �ͷź�ʹ���� (anonymous lambda type)::i ��ָ������������ڽ�����ָ�Э�̣�UB�������suspend_never�������ͣ���ô������׳��쳣
    h.destroy();
}
void good()
{
    coroutine h = [](int i) -> coroutine // i ��һ��Э���β�
    {
        std::cout << i;
        co_return;
    }(0);
    std::cout << "�ֺ�\n";//�ȴ�ӡ�������ʾ���Ƕ���������Э��
    // lambda ������
    h.resume(); // û�����⣬ i �Ѿ���Ϊ��ֵ���ݵĲ��������Ƶ�Э��֡�� ����UB�����Ƿ���ֵ�ĳ�suspend_never�Ļ�����bad3()��һ��������
    h.destroy();
}
int main() {
    bad1();
    puts("---");
    bad3();
    puts("---");
    good();
}
//ʹ��suspend_never��initial_suspend�ķ������;ͻ�ִ����Э���ˣ�������cout��ӡ0
//���������ֵ�ĳ�suspend_always����ô��Ȼ�ȴ�ӡ���ֺǡ��������ʹ��h.resume();��Э�ָ̻�ִ�У���ô�����ӡ0
//Э��ֻ���溯��ջ��Ķ��� ������this