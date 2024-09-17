/*
Задание 1
Очередь клиентов
Вам нужно создать приложение, которое имитирует очередь в окошко. Для этого нужно создать два потока, работающие с одной разделяемой переменной.

Первый поток имитирует клиента: раз в секунду он обращается к счётчику клиентов и увеличивает его на 1. Максимальное количество клиентов должно быть параметризировано.

Второй поток имитирует операциониста: раз в 2 секунды он обращается к счётчику клиентов и уменьшает его на 1. «Операционист» работает до последнего клиента.
*/

#include <iostream>
#include <Windows.h>
#include<thread>
#include <ctime>
void secunda(int start)
{
    int end = start;
    std::cout << "First window: start to work!\n";
    for (int i = 0; i < end; ++i)
    {
        ++start;
        Sleep(1000);
    }
    std::cout << "First window: work is down!\n" << std::endl;
}
void to_the_last(int start)
{
    std::cout << "Second window: start to work!\n";
    do
    {
        --start;
        Sleep(2000);
    } while (start > 0);
    std::cout << "Second window: work is down!\n" << std::endl;
}

int main()
{    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int queue = 10;
    auto now = std::chrono::system_clock::now();
    time_t now_t = std::chrono::system_clock::to_time_t(now);
    std::cout << "Время начала работы: ";
    printf("%02d:%02d:%02d \n", (now_t / 3600 + 3) % 24, (now_t / 60 % 60), now_t % 60 );// текущее время 
    std::thread window1 (secunda,queue);
    std::thread window2(to_the_last,queue);
    window1.join();
    window2.join();
    return 0;
}


