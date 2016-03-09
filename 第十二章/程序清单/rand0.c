/*rand0.c -- 产生随机数							*/
/*使用ANSI C的可移植算法						*/
static unsigned long int next = 1;		/*种子	*/
int rand0(void)
{
	/*产生伪随机数的魔术般的公式				*/
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}