import std.stdio;
import std.algorithm;
void main() {
    string str;
    readf("%s", &str);
    long[] lengths;
    {
        long cur = 0;
        for (int i = 0; i < str.length; ++i) {
            if (str[i] >= '0' && str[i] <= '9') {
                cur = cur * 10 + int(str[i] - '0');
            } else {
                lengths ~= cur;
                cur = 0;
            }
        }
    }
    long pos = 0;
    long ss = 0;
    long[] circle = new long[256];
    for (long i = 0; i < circle.length; ++i) circle[i] = i;
    for (long i = 0; i < lengths.length; ++i) {
        long cur_length = lengths[i];
        for (long j = 0; j < cur_length / 2; ++j) {
            long first = (pos + j) % circle.length;
            long second = (pos + cur_length - j - 1) % circle.length;
            swap(circle[first], circle[second]);
        }
        pos = (pos + cur_length + ss++) % circle.length;
        for (long j = 0; j < circle.length; ++j) {
            write(circle[j]);
            write(" ");
        }
        writeln();
    }
}
