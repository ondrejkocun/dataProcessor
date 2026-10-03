#ifndef LIBDF_DATAFRAME_HPP
#define LIBDF_DATAFRAME_HPP

#include <vector>
#include <ostream>

namespace df {

template <typename T>
class DataFrame {
public:
    using value_type = T;
    DataFrame(std::vector<T> data);

    void print(std::ostream& ost) const;
    size_t size() const;
    template <typename Extractor>
    const T* min(Extractor e) const;

    template <typename Extractor>
    const T* max1400(Extractor e) const;

    template<typename Predicate>
    std::vector<const T*> filter(Predicate predicate) const;

    template<typename ValueType,typename Extractor>
    ValueType mean(Extractor extractor) const;

    template <typename Extractor>
    const T* max(Extractor e) const;

    template<typename F>
    void apply(F f) const;

    template<typename F>
    void transform(F f);

private:
    std::vector<T> m_data;
};
template <typename T>
DataFrame<T>::DataFrame(std::vector<T> data)
    :m_data(std::move(data))
{
}

template <typename T>
void DataFrame<T>::print(std::ostream& ost)const {
    ost << "Pocet nacitanych dat: " << m_data.size() << "\n";
    for(const T& d : m_data){
        ost << d << "\n";
    }
}

template <typename T>
size_t DataFrame<T>::size()const {
    return m_data.size();
}
template <typename T>
template <typename Extractor>
const T* DataFrame<T>::min(Extractor e) const {
    if(m_data.empty()){
        return nullptr;
    }

    const T* ptrBest = &m_data.front();
    for(const T& otestovany : m_data){
        if(e(otestovany) < e(*ptrBest)) {
            ptrBest = &otestovany;
        }
    }
    return ptrBest;
}

template <typename T>
template <typename Extractor>
const T* DataFrame<T>::max(Extractor e) const {
    if (m_data.empty()) {
        return nullptr;
    }

    const T* ptrBest = &m_data.front();
    for (const T& otestovany : m_data) {
        if (e(otestovany) > e(*ptrBest)) {
            ptrBest = &otestovany;
        }
    }
    return ptrBest;
}

template <typename T>
template <typename Extractor>
const T* DataFrame<T>::max1400(Extractor e) const {
    if(m_data.empty()){
        return nullptr;
    }

    const T* ptrBest = &m_data.front();
    for(const T& otestovany : m_data){
        if(e(otestovany) > e(*ptrBest)) {
            ptrBest = &otestovany;
        }
    }
    return ptrBest;
}

template <typename T>
template <typename Predicate>
std::vector<const T*> DataFrame<T>::filter(Predicate predicate) const {
    std::vector<const T*> result;
    for(const T& data : m_data){ 
        if(predicate(data)){
            result.push_back(&data);
        }
    }
    return result;
}

template <typename T>
template <typename ValueType, typename Extractor>
ValueType DataFrame<T>::mean(Extractor extractor) const {
    ValueType result;
    if (m_data.empty()){
        return ValueType();
    }
    for(const T& data: m_data){
        result += extractor(data);
    }
    result /= m_data.size();
    return result;
}
template <typename T>
template <typename F>
void DataFrame<T>::apply(F f) const {
    for (const T& record : m_data) {
        f(record);
    }
}

template <typename T>
template <typename F>
void DataFrame<T>::transform(F f) {
    for (T& record : m_data) {
        f(record);
    }
}

} // namespace df

#endif
