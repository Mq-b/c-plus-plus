#include<iostream>
#include<memory>
#include<thread>
#include<mutex>
#include<algorithm>

template<typename T>
class threadsafe_list {
	struct node {
		std::mutex m;
		std::shared_ptr<T>data;
		std::unique_ptr<node>next;
		node() :next() {}
		node(T const& value) :data(std::make_shared<T>(value)) {}
	};
	node head;
private:
	threadsafe_list() {}
	~threadsafe_list() {
		std::remove_if([](node const&) {return true; });
	}
	threadsafe_list(threadsafe_list const& other) = delete;
	threadsafe_list& operator=(threadsafe_list const& other) = delete;

	void push_front(T const& value) {
		std::unique_ptr<node>new_node(new node(value));	//创建初始化智能指针对象new_node
		std::lock_guard<std::mutex>lk(head.m);			//锁
		new_node->next = std::move(head.next);			//将智能指针new_node指向的node的next设置为head.next
		head.next = std::move(new_node);				//将head.next设置为new_node		也就是说构成了环形
	}
	template<typename Function>
	void for_each(Function f) {
		node* current = &head;
		std::unique_lock<std::mutex>lk(head.m);
		while (node* const next = current->next.get()) {
			std::unique_lock<std::mutex>next_lk(next->m);
			lk.unlock();									//解锁
			f(*next->data);
			current = next;	//相当于把node的
			lk = std::move(next_lk);
		}
	}
	template<typename Predicate>
	std::shared_ptr<T> find_first_if(Predicate p) {
		node* current = &head;
		std::unique_lock<std::mutex>lk(head.m);
		while (node* const next = current->next.get()) {
			std::unique_ptr
		}
	}
};