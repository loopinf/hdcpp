#include <thread>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

constexpr std::size_t sz = 1000000;

std::vector<int> v;

void init()
{
    for (int i = 0; i < sz; ++i)
    {
        v.push_back(i);
    }
}
//---------------------------------------------

template<typename IT, typename RT>
void sum(IT first, IT last, RT& result)
{
    result = std::accumulate(first, last, 0);
}

//---------------------------------------------
// sample3.cpp 에서 
// first ~ last 구간의 합을 멀티스레드로 구하는 코드

template<typename IT, typename RT>
void parallel_sum(IT first, IT last, RT& result)
{
    // #1. 구간내 요소의 갯수 구하기
    // auto cnt_element = last - first;    // vector ok, linked list 는 안됨
    auto cnt_element = std::distance(first, last);

    if (cnt_element == 0) return;

    // #2. 몇개의 스레드 쓸지 결정
    std::size_t cnt_hw_thread = std::thread::hardware_concurrency();  // core갯수파악

    if (cnt_hw_thread == 0)
        cnt_hw_thread = 2;

    // 한개의 스레드가 계산할 최소 요소의 갯수를 250개로 설정
    const std::size_t cnt_per_thread = 250;

    // 요소가 1100개라면 - 5개의 스레드 필요
    const std::size_t max_cnt_thread =
        (cnt_element + cnt_per_thread - 1) / cnt_per_thread;

    // core 수와, 계산값중 작은 값으로 스레드 갯수 결정
    const std::size_t cnt_thread =
        std::min(cnt_hw_thread, max_cnt_thread);

    // -----------------------------------------------
    // 최종 스레드 갯수: cnt_thread
    // 이미 main thread 있으므로, : cnt_thread - 1 

    const std::size_t block_size = cnt_element / cnt_thread;
    std::vector<std::thread> thread_vec(cnt_thread - 1);
    std::vector<RT> result_vec(cnt_thread);   // 각 스레드가 수행한 결과를 담을 vector

    IT start = first;

    for (int i = 0; i < cnt_thread - 1; ++i)
    {
        IT end = std::next(start, block_size);

        thread_vec[i] = std::thread(
            sum<std::vector<int>::iterator, int>,
            start, end, std::ref(result_vec[i]));

        start = end;
    }
    // main thread will do this
    sum(start, last, result_vec[cnt_thread - 1]);

    // main thread done
    // 다른 모든 스레드의 종료 대기
    for (auto& t : thread_vec)
        t.join();

    // 결과를 담는 vecotr의 모든 요소를 더하기 
    RT ret = std::accumulate(result_vec.begin(), result_vec.end(), 0);

    result = ret;
}

// ------------------------------------------------------------------

int main()
{
    init();

    int s = 0;
    // sum(v.begin(), v.end(), s);
    parallel_sum(v.begin(), v.end(), s);
}
