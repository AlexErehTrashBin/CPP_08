#include <iostream>
#include <queue>
#include <unordered_set>

template<typename T>
auto contains_duplicates_generic(
    std::queue<T> queue
) -> bool {
    std::unordered_set<T> seen_elements;
    seen_elements.reserve(queue.size());
    while (!queue.empty()) {
        int current = queue.front();
        if (seen_elements.contains(current)) {
            return true;
        }
        seen_elements.insert(current);
        queue.pop();
    }
    return false;
}

int main() {
    const std::queue<int> queue({5, 5, 6, 7, 9});
    const bool result = contains_duplicates_generic(queue);
    if (result) {
        std::cout << "да" << std::endl;
    } else {
        std::cout << "нет" << std::endl;
    }
    return 0;
}
