#include "human.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

    Queue<int> q;

    q.add_queue(1);
    q.add_queue(2);
    q.add_queue(3);

    std::cout << "ѕервый элемент: " << q.front() << std::endl;
    std::cout << "ƒлинна очереди: " << q.getSize() << std::endl;

    q.print_queue();
    std::cout << "Ёлемент после вышедшего: " << q.front() << std::endl;

    q.print_queue();
    q.print_queue();
    q.print_queue(); // Trying to dequeue from empty queue

    return 0;




	return 0;
}