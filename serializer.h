#ifndef SIMPLE_SERIALIZER_H_
#define SIMPLE_SERIALIZER_H_

template <typename T>
inline constexpr void serialize(char *buf, const T t)
{
    *((T *)(buf + 0)) = t;
}

template <typename T, typename... Args>
inline constexpr void serialize(char *buf, const T t, const Args &... args)
{
    serialize(buf, t);
    serialize(buf + sizeof(T), args...);
}

#endif
