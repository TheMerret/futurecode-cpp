#include <string>
#include <set>

struct NamesHolder {
    std::set<std::string> holder;

    void AddName(const std::string& name) {
        holder.insert(name);
    }
    bool HasName(const std::string& name) {
        return holder.find(name) != holder.end();
    }
    size_t Size() {
        return holder.size();
    }
};
