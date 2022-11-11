#include<thread>
#include<iostream>
#include<mutex>

class SingleInstance {
public:
    static SingleInstance*& GetInstance();

    static void deleteInstance();

    void Print() {
        std::cout << this << '\n';
    }

private:
    SingleInstance() {
        std::cout << __func__ << '\n';
    }
    ~SingleInstance() {
        std::cout << __func__ << '\n';
    }

    SingleInstance(const SingleInstance& signal);
    const SingleInstance& operator=(const SingleInstance& signal) = delete;

    inline static SingleInstance* m_SingleInstance = nullptr;
    inline static std::mutex m_Mutex;
};

SingleInstance*& SingleInstance::GetInstance() {
    if (m_SingleInstance == nullptr) {
        std::lock_guard<std::mutex> lock(m_Mutex);
        if (m_SingleInstance == nullptr) {
            m_SingleInstance = new (std::nothrow) SingleInstance{};
        }
    }
    return m_SingleInstance;
}

void SingleInstance::deleteInstance() {
    std::lock_guard<std::mutex> lock(m_Mutex);
    if (m_SingleInstance) {
        delete m_SingleInstance;
        m_SingleInstance = nullptr;
    }
}

int main() {
    decltype(auto) p = SingleInstance::GetInstance();
    p->Print();
    SingleInstance::deleteInstance();

    decltype(auto) p2 = SingleInstance::GetInstance();
    p2->Print();
    SingleInstance::deleteInstance();

    decltype(auto) p3 = SingleInstance::GetInstance();
    p3->Print();
    SingleInstance::deleteInstance();
}
