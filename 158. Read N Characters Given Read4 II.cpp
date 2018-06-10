/*158. Read N Characters Given Read4 II - Call multiple times

The API: int read4(char *buf) reads 4 characters at a time from a file.
The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters 
left in the file.
By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function may be called multiple times.

Example 1: 

Given buf = "abc"
read("abc", 1) // returns "a"
read("abc", 2); // returns "bc"
read("abc", 1); // returns ""

Example 2: 

Given buf = "abc"
read("abc", 4) // returns "abc"
read("abc", 1); // returns ""
*/

/*用两个变量readPos和writePos来记录读取和写的位置，i从0到n开始循环，如果此时读和写的位置相同，那么我们调用read4函数，
将结果赋给writePos，把readPos置零，如果writePos为零的话，说明buf中没有东西了，返回当前的坐标i。然后我们用内置的buff
变量的readPos位置覆盖输入字符串buf的i位置，如果完成遍历，返回n*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        for (int i = 0; i < n; ++i) {
            if (readPos == writePos) {
                writePos = read4(buff);
                readPos = 0;
                if (writePos == 0) return i;
            }
            buf[i] = buff[readPos++];
        }
        return n;
    }
    
private:
    int readPos = 0;
    int writePos = 0;
    char buff[4];
};






















