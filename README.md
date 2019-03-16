# simple-serializer

serialize everything into char array in one function call.

## Sample

    #include "serializer.h" // single header

    // classes is ok if it is copyable (T &operator=(const T &t) is allowed)
    // this class costs 8 bytes
    class TestObj
    {
    public:
        int v1 = 0x8899AABB;
        short v2 = 0xCCDD;
        char v3 = 0xEE;
    };

    int main()
    {
        int v1 = 0x11223344;
        short v2 = 0x5566;
        char v3 = 0x77;
        TestObj v4;

        char buf[15];
        serialize(buf, v1, v2, v3, v4);

        printf("%02x %02x %02x %02x, %02x %02x, %02x, %02x %02x %02x %02x %02x %02x %02x %02x\n",
                buf[0], buf[1], buf[2], buf[3],
                buf[4], buf[5],
                buf[6],
                buf[7], buf[8], buf[9], buf[10], buf[11], buf[12], buf[13], buf[14]);

        // 44 33 22 11, 66 55, 77, bb aa 99 88 dd cc ee 00
    }

## Compiler support

Require C++ compiler that supports `C++11 Variadic templates`
