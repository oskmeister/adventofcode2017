import std.stdio;
import std.algorithm;
void main() {
    string str;
    readf("%s", &str);
    long[] lengths;
    {
        for (int i = 0; i < str.length-1; ++i) {
            lengths ~= cast(long)str[i];
        }
        lengths ~= 17;
        lengths ~= 31;
        lengths ~= 73;
        lengths ~= 47;
        lengths ~= 23;
    }
    for (int i = 0; i < lengths.length; ++i) {
        writeln(lengths[i]);
    }
    long[] circle = new long[256];
    for (long i = 0; i < circle.length; ++i) circle[i] = i;
    long pos = 0;
    long ss = 0;
    for (int k = 0; k < 64; ++k) {
        for (long i = 0; i < lengths.length; ++i) {
            long cur_length = lengths[i];
            for (long j = 0; j < cur_length / 2; ++j) {
                long first = (pos + j) % circle.length;
                long second = (pos + cur_length - j - 1) % circle.length;
                swap(circle[first], circle[second]);
            }
            pos = (pos + cur_length + ss++) % circle.length;
        }
    }
    long[] buckets = new long[16];
    for (int i = 0; i < 16; ++i) {
        buckets[i] = 0;
        for (int j = 0; j < 16; ++j) {
            buckets[i] ^= circle[i * 16 + j];
        }
        writef("%02x", buckets[i]);
    }
    writeln();
}
