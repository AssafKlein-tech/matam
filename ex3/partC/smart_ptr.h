#include <memory>
using MyType_t = std::shared_ptr<my_structure>;

std::unique_ptr<int> a(new int(4));
std::shared_ptr<int> a = std::make_shared<int>